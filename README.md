# c-bracket-validation
This project consists of a stack implemented as a static library and a `CheckBrackets` function built on top of it. Using the stack, `CheckBrackets` takes a string containing a mathematical formula and checks whether every opening bracket has a matching closing bracket. It prints the index pairs of matched brackets to standard output.

## Stack
- Implemented as a fixed-capacity array inside the `Stack` struct.
- The struct holds the **data array** and a **top index** (`top`, type `ST_INDEX`), `-1`= stack empty.
- Element type (`ST_TYPE`), print format (`ST_PRINT`) and capacity (`ST_CAPACITY`) are defined through macros. The index type is chosen automatically based on capacity.
- The stack and its functions are separated into an independent static library (`libstack.a`).

## CheckBrackets
- Makes a single pass through the formula, pushing the indices of opening brackets onto the stack.
- On each closing bracket it pops the last opening one, checks that both are of the same type and prints their index pair.



## Build 

Build the library:

```
gcc -c stack.c
ar -rs libstack.a stack.o
```

Build the program:

```
gcc main.c check_brackets.c -L. -lstack -o main
```

Run:

```
./main
```




## Limitations :

- One element type per build (type and capacity are set at compile time; multiple types would require a dynamic stack).
- Maximum formula length: 255 characters.
- Maximum 16 nested brackets (default `ST_CAPACITY`).
