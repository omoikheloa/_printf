Custom Printf Implementation
This project is a collaborative effort between Omo Ikheloa
and Nnaemeka Noble as part of the ALX Software Engineering
Cohorts 1 Blended Programme.

Overview
The printf function is a crucial part of the standard
C library, responsible for formatted output. This repository
contains our custom implementation of the printf function,
offering a subset of its functionality while exploring
the concepts of variadic functions, string parsing, and
character manipulation.

Features
Our printf implementation currently supports:

Basic conversion specifiers (%c, %s, %d, %i, %u, %x, %X, %o, %p)
Width and precision modifiers
Some flags (-, +, space, 0, #)

Buffer and Write Function: Our implementation uses
a buffer mechanism to handle output before writing to the
standard output. The write function is utilized to output
data from the buffer to the standard output.

Print Handler Function: Internally, our implementation
uses a print handler function to process different format
specifiers and handle their respective output formatting.
