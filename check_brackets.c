#include "check_brackets.h"
#include "stack.h"
#include <stdio.h>
#include <inttypes.h>

int_least8_t CheckBrackets(const char* formula)
{
    Stack stack_bc;
    StackInit(&stack_bc);

    uint_least8_t i = 0u;
    ST_TYPE open_index = (ST_TYPE)0;
    char current;
    char open_char;

    if ((formula == NULL) || (formula[0] == '\0'))
    {
        return CB_INVALID_INPUT;
    }
        
    while (formula[i] != '\0')
    {
        /* formula longer than 255 characters*/
        if (i == UINT_LEAST8_MAX)
        {
            return CB_INVALID_INPUT;
        }
 
        current = formula[i];

        if ((current == '(') || (current == '[') || (current == '{'))
        {
 
            if (StackPush(&stack_bc, (ST_TYPE)i) != 0)
            {
                return CB_STACK_ERR;
            }
                
        }
        else if ((current == ')') || (current == ']') || (current == '}'))
        {
            if (StackPop(&stack_bc, &open_index) != 0)
            {
                return CB_MISSING_BR;
            }
 
            open_char = formula[open_index];
 
            if (((current == ')') && (open_char != '(')) ||
                ((current == ']') && (open_char != '[')) ||
                ((current == '}') && (open_char != '{')))
            {
                return CB_MISSING_BR;
            }
 
            printf("[%" PRIuLEAST8 ", %" PRIuLEAST8 "]\n", open_index, i);
        }
        else
        {
            /* not a bracket, ignore */
        }
 
        i++;
    }

    if (!StackIsEmpty(&stack_bc))
    {
        return CB_MISSING_BR;
    }
        
    return CB_OK;
}