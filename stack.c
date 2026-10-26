#include "stack.h"
#include <stdio.h>

int_least8_t StackInit(Stack *s)
{
    if (s == NULL)
    {
        return -1;
    }
    
    s->top = -1;
    return 0;
}

bool StackIsFull(const Stack *s)
{
    if (s->top == ST_CAPACITY - 1)
    {
        return true;
    }
        
    return false;
}

bool StackIsEmpty(const Stack *s)
{
    if (s->top == -1)
    {
        return true;
    }
       
    return false;
}

int_least8_t StackPush(Stack *s, ST_TYPE value)
{
    if(StackIsFull(s))
    {
        return -1;
    }
    
    s->top++;
    s->data[s->top] = value;
    return 0;
}

int_least8_t StackPop(Stack *s, ST_TYPE *value)
{
    if(StackIsEmpty(s))
    {
        return -1;
    }

    *value = s->data[s->top];
    s->top--;
    return 0;
}

void StackDump(const Stack *s)
{
    ST_INDEX i;
    if (StackIsEmpty(s))
    {
        printf("Stack is empty.\n\n");
        return;
    }
    else
    {
        for (i = 0; i <= s->top; i++)
        {
            printf("[" ST_PRINT "] ", s->data[i]);
        }
    }
    
    printf("\n\n");
}
