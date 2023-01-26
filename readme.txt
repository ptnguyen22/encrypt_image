**********************************************************************
 *  Linear Feedback Shift Register 
**********************************************************************

Peter Nguyen

Developed in Ubuntu using the G++ GNU compiler.
Dependencies: SFML --to install: sudo apt-get install libsfml-dev

**********************************************************************
This is a program that takes in an input file name, output file name, and
a 16 bit binary seed. It uses the input file name to open an image and then
uses the FibLFSR class (from previous assignment) and the command line seed 
argument to generate pseudo-random numbers that are used to manipulate each 
pixel color so that the result is an encrypted image. It then saves the 
encrypted image to a file using the output file name from the command line argument.
It also uses SFML to display two windows of the original image and the new
encrypted image. Given the same seed, running an encrypted image will return 
the original image.
**********************************************************************

to run:
./PhotoMagic (input file) (output file) (16 bit binary seed) 
example:
./PhotoMagic input-file.png output.png 0111000100000100

