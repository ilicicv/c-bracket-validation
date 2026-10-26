#ifndef STACK_H
#define STACK_H

#include <stdint.h>
#include <stdbool.h>
#include <inttypes.h>

/*
 * Configuration:
 *  ST_TYPE     - element type
 *  ST_PRINT    - format for printf (must match ST_TYPE)
 *  ST_CAPACITY - maximum number of elements (1..32767)
 */
#ifndef ST_TYPE
#define ST_TYPE uint_least8_t
#endif

#ifndef ST_PRINT
#define ST_PRINT "%"PRIuLEAST8
#endif

#ifndef ST_CAPACITY
#define ST_CAPACITY 16
#endif

#if ST_CAPACITY <= 127
    typedef int_least8_t  ST_INDEX;
#else
    typedef int_least16_t ST_INDEX;
#endif

typedef struct{
    ST_TYPE data[ST_CAPACITY];
    ST_INDEX top; 
} Stack;

int_least8_t StackInit(Stack *s);
bool StackIsFull(const Stack *s);
bool StackIsEmpty(const Stack *s);
int_least8_t StackPush(Stack *s, ST_TYPE value);
int_least8_t StackPop(Stack *s, ST_TYPE *value);
void StackDump(const Stack *s);

#endif

