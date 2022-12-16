# Assignment 1 - Pass the Pigs
This C program simulates a simplified version of the game "Pass the Pigs" with a given set of names for players. The user can input the number of players (between 2-10) they want to play, and a random seed value to randomize the positions for the pig. The program outputs the gameplay and winner. 

## Building

Build the program with:

```
$ make
```
You can check the format using:
```
$ make format
```
Remember to clean up afterwards:
```
$ make clean
```
## Running

Run the program with:

```
$ ./pig
```
## Possible Errors
When the user uses invalid inputs such as "asdf" or "123asdf", the programs skips over the user input for a random seed. This error is due to the way the scanf() works. 
