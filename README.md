# Assembly-Compilation-Script
Simple executable to compile and link Assembly programs in a single command in linux machines
_____________________________________________________
Command: g++ assembly_script.cpp -o asm64 --std=c++14
_____________________________________________________

# Using the tool:
./asm64 <assembly-main-file> (without extension)

Example: ./asm64 hello_world
         ./asm64 main
         ./asm64 pi_calc
         ...etc.
       
You can move the asm64 executable into the /usr/bin to execute it from anywhere.     
