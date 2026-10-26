#include <stdio.h>
#include <stdbool.h>
#include <inttypes.h>
#include "stack.h"
#include "check_brackets.h"

int main(void){
    Stack stack;
    ST_TYPE el = 0;
    ST_INDEX i;
    
    /* STACK TEST */
    /* Init, Full, Empty */

    printf("\n=== STACK TESTS ===\n");

    if (StackInit(NULL) == -1)
    {
        printf("Init with NULL rejected.\n");
    }
    else
    {
        printf("[ERROR] Init with NULL was accepted.\n");
    }


    if (StackInit(&stack) == 0)
    {
        printf("Stack initialized.\n\n");
    }
    else
    {
        printf("[ERROR] Stack failed to initialize.\n\n");
    }

    if ((StackIsEmpty(&stack) == true) && (StackIsFull(&stack) == false))
    {
        printf("New stack is empty and not full.\n");
    }
    else
    {
        printf("[ERROR] New stack is not empty or is full.\n");
    }


    if (StackPop(&stack, &el) == -1)
    {
        printf("Pop on empty stack rejected.\n\n");
    }
    else
    {
        printf("[ERROR] Pop on empty stack was accepted.\n\n");
    }

    /* Push, Pop */
    for (i = 1; i <= 3; i++)
    {
        StackPush(&stack, (ST_TYPE)i);
        printf("Pushed value " ST_PRINT ".\n", (ST_TYPE)i);
    }
    StackDump(&stack);

    for (i = 3; i >= 1; i--)
    {
        StackPop(&stack, &el);
        printf("Pop returned " ST_PRINT ".\n", (ST_TYPE)i);

    }

    StackDump(&stack);

    /* Overflow */
    for (i = 0; i < ST_CAPACITY; i++)
    {
        StackPush(&stack, (ST_TYPE)i);
    }

    if (StackIsFull(&stack))
    {
        printf("Pushed max number of elements. Stack is full.\n");
    }
    else
    {
        printf("[ERROR] Stack is not full at capacity.\n");
    }

    if (StackPush(&stack, (ST_TYPE)4) == -1)
    {
        printf("Push on full stack rejected.\n");
    }
    else
    {
        printf("[ERROR] Push on full stack was accepted.\n");
    }

    StackDump(&stack);


 
    /* CHECK BRACKETS TEST */

    printf("\n=== CHECK BRACKETS TESTS ===\n");

    /* Long formulas for boundary tests */
    static char formula_256[257];
    static char formula_255[256];
    int_least16_t k;
    for (k = 0; k < 256; k++)
    {
        formula_256[k] = '1';
    }
    formula_256[k] = '\0';

    for (k = 0; k < 255; k++)
    {
        formula_255[k] = '2';
    }
    formula_255[0] = '(';
    formula_255[254] = ')';
    formula_255[255] = '\0';


    const char* formulas[12] = {
        "(1+2)*[3-{4}]",
        "((1+2)*3)",
        "1+2",
        "(1+2",
        "1+2)",
        "(1+2]",
        "{[(])}",
        "((((((((((((((((()))))))))))))))))",
        "",
        NULL,
        formula_255,
        formula_256
    };

    int_least8_t j = 0;
    for (j = 0; j < 12; j++)
    {
        if (formulas[j] != NULL)
        {
            printf("Formula: \"%s\"\n", formulas[j]);
        }
        else
        {
            printf("Formula: NULL\n");
        }

        int_least8_t result = CheckBrackets(formulas[j]);

        if (result == CB_OK)
        {
            printf("All brackets have pair.\n\n");
        }
        else if (result == CB_MISSING_BR)
        {
            printf("Missing brackets.\n\n");
        }
        else if (result == CB_STACK_ERR)
        {
            printf("Nesting exceeds stack capacity (%" PRIdLEAST8 ").\n\n", (int_least8_t)ST_CAPACITY);
        }
        else
        {
            printf("Invalid input.\n\n");
        }
    }

    
    return 0;

}
