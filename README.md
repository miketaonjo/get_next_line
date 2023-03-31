# Project name : get_next_line

For this project, the assignment is : 

Program a function that returns a line read from a file descriptor

We learn to read from a file descriptor, as well as the use of static variables. This function returns a single line from a given file descriptor
If called in a loop, get_next_line returns the entire contents of a file, line by line until it reaches the end of the file. It can be compiled specifying any buffer size.

## Usage

In order to compile :
<code>gcc srcs/main.c srcs/get_next_line.c srcs/get_next_line_utils.c</code><br>
or<br>
<code>gcc -D BUFFER_SIZE=42 srcs/main.c srcs/get_next_line.c srcs/get_next_line_utils.c</code>

Execution :
<code>./a.out file.txt</code>
