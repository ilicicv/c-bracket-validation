#ifndef CHECK_BRACKETS_H
#define CHECK_BRACKETS_H
 
#include <stdint.h>

/*
 * Checks if every opening bracket has a matching closing bracket
 * and prints the index pairs
 *
 * Returns:
 *   0  SUCCESS (all brackets matched)
 *  -1  missing brackets
 *  -2  nesting deeper than ST_CAPACITY
 *  -3  empty or invalid input (NULL, longer than 255 characters)
 */

typedef enum{
    CB_INVALID_INPUT = -3,
    CB_STACK_ERR     = -2,
    CB_MISSING_BR    = -1,
    CB_OK            = 0
} CBStatus;

int_least8_t CheckBrackets(const char* formula);

#endif