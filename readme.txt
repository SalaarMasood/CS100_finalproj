Salaar Masood (26100149)

Sana Humayun (26100273)


Okay so our project was hangman. We tried to add a little twist of our own into this game by giving the user the option to
choose from five different categories. The rest of the game works as usual. We made a total of 6 functions: 
1.game_Rules
2.category_choice
3.read_File
4.rand_Word
5.guess_Word
6.hang_Body

The overall jist of the code is as follows:
Firstly, all the rules of the game will be told, and then it will ask you what category of words you want. Now
depending on what category the user chose, that file's words will be read into an array and then a random word will be chosen 
from those words. Then blanks will be generated according to the word. Now the actual game begins where you have to input
a letter and try to guess the word. If the letter is correct, it will replace the blank with the letter and if it isn't, it
will output that you have entered an incorrect letter and a body part of the hangman will be drawn. If you choose the wrong letter
more than 6 times, the hangman would've been drawn fully and you'll lose!

game_Rules:
Prints out all the game rules at the start of the program

category_choice:
Returns the file of the category that the user chooses

read_File:
It reads all the elements of the file into an array

rand_Word:
Generates a random word from the array and generates blanks according to it. 

guess_Word:
This function is to guess the letter and to replace the blanks with the correct guess input. 

hang_Body:
This will draw a body part of the hangman for every incorrect guess.












