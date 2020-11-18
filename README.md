Liam Lasurdo

Compile the code by running make.
Execute with ./main
Design Decisions
- used a 2d vector instead of a matrix to allow for graphs of different sizes to be passed into the same function
- print results inside the function to allow the function to be of type void and not worry about returning anything
- made infinity only 9999 because im controlling the inputs and nothing comes close to being as large as that
- could have made a node class and then had it contain the value as well as if it had been visited but I instead opted to just make 2 arrays as it was simpler
