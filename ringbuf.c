/****************************************************
 * File       : ringbuf.c
 * Author     : Naitik Pawar
 * Description: Circular Ring Buffer Implementation
 * Compiler   : gcc -Wall -std=c99
 ****************************************************/

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#define BUFFER_SIZE   8U
#define RINGBUF_MASK  (BUFFER_SIZE - 1U)

#define RINGBUF_OK     0
#define RINGBUF_ERROR -1

/*--------------------------------------------------
 * Ring Buffer Structure
 *--------------------------------------------------*/
typedef struct
{
    uint8_t buffer[BUFFER_SIZE];
    uint8_t head;
    uint8_t tail;
    uint8_t count;

} RingBuffer;

/*--------------------------------------------------
 * Static Global Ring Buffer
 *--------------------------------------------------*/
static RingBuffer rb;

/*--------------------------------------------------
 * Function Prototypes
 *--------------------------------------------------*/
static void ringbuf_init(void);
static int ringbuf_is_empty(void);
static int ringbuf_is_full(void);
static uint8_t ringbuf_count(void);
static int ringbuf_write(uint8_t data);
static int ringbuf_read(uint8_t *data);

/*--------------------------------------------------
 * Function : ringbuf_init
 * Purpose  : Initialize ring buffer
 *--------------------------------------------------*/
static void ringbuf_init(void)
{
    rb.head = 0U;
    rb.tail = 0U;
    rb.count = 0U;
}

/*--------------------------------------------------
 * Function : ringbuf_is_empty
 * Purpose  : Check if buffer is empty
 * Return   : 1 if empty, 0 otherwise
 *--------------------------------------------------*/
static int ringbuf_is_empty(void)
{
    return (rb.count == 0U);
}

/*--------------------------------------------------
 * Function : ringbuf_is_full
 * Purpose  : Check if buffer is full
 * Return   : 1 if full, 0 otherwise
 *--------------------------------------------------*/
static int ringbuf_is_full(void)
{
    return (rb.count == BUFFER_SIZE);
}

/*--------------------------------------------------
 * Function : ringbuf_count
 * Purpose  : Return current number of bytes
 *--------------------------------------------------*/
static uint8_t ringbuf_count(void)
{
    return rb.count;
}

/*--------------------------------------------------
 * Function : ringbuf_write
 * Purpose  : Write one byte into ring buffer
 * Input    : data byte
 * Return   : RINGBUF_OK on success
 *            RINGBUF_ERROR if full
 *
 * Note:
 * Faster wrap-around using bitwise AND.
 * Works because BUFFER_SIZE is power of 2.
 * Faster than modulo (%) on MCUs without
 * hardware divider.
 *--------------------------------------------------*/
static int ringbuf_write(uint8_t data)
{
    if (ringbuf_is_full())
    {
        return RINGBUF_ERROR;
    }

    rb.buffer[rb.head] = data;

    rb.head = (rb.head + 1U) & RINGBUF_MASK;

    rb.count++;

    return RINGBUF_OK;
}

/*--------------------------------------------------
 * Function : ringbuf_read
 * Purpose  : Read one byte from ring buffer
 * Output   : data pointer
 * Return   : RINGBUF_OK on success
 *            RINGBUF_ERROR if empty/NULL
 *--------------------------------------------------*/
static int ringbuf_read(uint8_t *data)
{
    if ((data == NULL) || (ringbuf_is_empty()))
    {
        return RINGBUF_ERROR;
    }

    *data = rb.buffer[rb.tail];

    rb.tail = (rb.tail + 1U) & RINGBUF_MASK;

    rb.count--;

    return RINGBUF_OK;
}

/*--------------------------------------------------
 * Main Function
 *--------------------------------------------------*/
int main(void)
{
    uint8_t value = 0U;

    uint8_t data1[BUFFER_SIZE] =
    {
        0x41U, 0x42U, 0x43U, 0x44U,
        0x45U, 0x46U, 0x47U, 0x48U
    };

    uint8_t data2[3U] =
    {
        0x49U, 0x4AU, 0x4BU
    };

    ringbuf_init();

    printf("====================================\n");
    printf(" Ring Buffer Demonstration Program\n");
    printf("====================================\n\n");

    /* Step 1: Write first 8 bytes */
    for (uint8_t i = 0U; i < BUFFER_SIZE; i++)
    {
        if (ringbuf_write(data1[i]) == RINGBUF_OK)
        {
            printf("[WRITE] 0x%02X -> OK   (count=%u)",
                   data1[i],
                   ringbuf_count());

            if (ringbuf_is_full())
            {
                printf(" FULL");
            }

            printf("\n");
        }
    }

    printf("\n");

    /* Step 2: Attempt extra write */
    if (ringbuf_write(0x99U) == RINGBUF_ERROR)
    {
        printf("[WRITE] 0x99 -> FAIL (buffer full)\n");
    }

    printf("\n");

    /* Step 3: Read 3 bytes */
    for (uint8_t i = 0U; i < 3U; i++)
    {
        if (ringbuf_read(&value) == RINGBUF_OK)
        {
            printf("[READ ] -> 0x%02X (count=%u)\n",
                   value,
                   ringbuf_count());
        }
    }

    printf("\n");

    /* Step 4: Write 3 new bytes */
    for (uint8_t i = 0U; i < 3U; i++)
    {
        if (ringbuf_write(data2[i]) == RINGBUF_OK)
        {
            printf("[WRITE] 0x%02X -> OK   (count=%u)\n",
                   data2[i],
                   ringbuf_count());
        }
    }

    printf("\n");

    /* Step 5: Read all remaining bytes */
    while (!ringbuf_is_empty())
    {
        if (ringbuf_read(&value) == RINGBUF_OK)
        {
            printf("[READ ] -> 0x%02X (count=%u)\n",
                   value,
                   ringbuf_count());
        }
    }

    if (ringbuf_is_empty())
    {
        printf("\nBuffer is now EMPTY\n");
    }

    printf("\n");

    /* Step 6: Attempt read from empty buffer */
    if (ringbuf_read(&value) == RINGBUF_ERROR)
    {
        printf("[READ ] (empty) -> FAIL (buffer empty)\n");
    }

    return 0;
}
