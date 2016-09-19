#brainf: A simple Brainfuck Interpreter

This interpreter behaves like mechanical computer working with punched tapes, as the Brainfuck language itself is a imitation of the Turing-imagined Turing Machine ---- and no optimization performed.

#Compiling and running

To compile, simply run

    gcc main.c LinkedList.c -o brainf
    
then

    ./brainf code.bf
    
See what happens.

#A little bit about Brainfuck and this implementation

As described in [Wikipedia](https://en.wikipedia.org/wiki/Brainfuck#Commands), Brainfuck has defined 8 commands in total, which is exactly like programming a FSM with its state transition table.

In this implementation, the Brainfuck standard (If there is one) is strictly implemented. Except the 8 commands, all other characters (Letters, numbers, etc.) are treated as comment, and won't be taken care by the interpreter.