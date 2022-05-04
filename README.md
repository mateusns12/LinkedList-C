# Linked List in C

![System](https://img.shields.io/badge/System-Android_TERMUX-47D147?style=for-the-badge&logo=android)

![Language](https://img.shields.io/badge/language-c-00599c?style=for-the-badge&logo=c&logoColor=white)

Simple Linked List in C. Full implementation of linked list, with no read/write errors or memory leaks, checked with Valgrind. 

Using calloc  to initialize struct, so if user enters a invalid value, it is already set to zero. Using hardcoded lenghts for char arrays and malloc calls, to make tests simpler. Will be changed to dynamic values later;

## Implemented Methods

````
    1 - Insert Data         // Insert new node
    2 - Print Data          // Print Entire list
    3 - Delete Data         // Delete Entire list
    4 - Remove Last         // Remove Last node
    5 - Remove selected     // Entering a string
    6 - Exit
````

<!--
## Features:
Generic methods allows to reuse code to create different types of lists. Queue and Stacks can be handled by Insert and Delete.
-->

# Notes 

- Fixed SIGSEV error, when trying to remove a node wich doesnt exist;
- The current List is a queue, where the first is always first, and new members are put in the end of the list.(Last In First Out)
- "first" pointer and "last" pointer keeps track of the data in their respective positions.

# To-do

- [X] Implement Deletion
- [X] Implement Delete Selected Methods
- [X] Create typedef for struct 
- [ ] Implement Insertion in place 
- [ ] Implement Stack (FIFO)
- [ ] Implement union
- [ ] Save and list to file (sqlite3 or bin)
- [ ] Implement Generic methods
- [ ] Remove Global variables
 
# Valgrind Analysis

After testing all the operations
````
==9103== HEAP SUMMARY:
==9103==     in use at exit: 0 bytes in 0 blocks
==9103==   total heap usage: 8 allocs, 8 frees, 2,183 bytes allocated
==9103== 
==9103== All heap blocks were freed -- no leaks are possible
==9103== 
==9103== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
````
