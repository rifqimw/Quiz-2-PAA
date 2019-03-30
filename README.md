### MineSweeper

Minesweeper is a game that played by one player, played by opening all the field while evading the bombs by marking them with flags and clicking the safe field. The player will click on a square in the field to open the square. The square’s contents are a bomb, a number, or a blank square.

If a player opens a square that contains a bomb, the player loses.
If the square contains a number,  the number represents how many bombs are there in the square’s current location on a 3 x 3 spaces.
If a player opens a square that contains a blank square, that is a safe zone, there is no bomb near there.

The winning conditions are when all the bombs are evaded and all other fields are opened.

## How to use
![alt text](https://github.com/rifqimw/Quiz-2-PAA/blob/master/gambar/S1.JPG)

The user asked to give inputs n to state the area of the field, and ranjau to state the number of bombs planted in the field.

![alt text](https://github.com/rifqimw/Quiz-2-PAA/blob/master/gambar/S2.JPG)

The program then generates n x n area field with ranjau bombs. To check a box, insert two numbers to check the square of that box.

![alt text](https://github.com/rifqimw/Quiz-2-PAA/blob/master/gambar/S3.JPG)

In this case, the user inputs a zero and a one. Imagine that the value given is (0,1). Now, (0,1) doesn’t refer to the cartesian places, but more to which column and row is a square. Add each value by one, we get (1,2), as in:
1 → the first row 
2 → the second column
Check the first row and second column of the field, open the square. We now get a number ‘3’, which means that there are 3 bombs near the 3 x 3 area of the square.

![alt text](https://github.com/rifqimw/Quiz-2-PAA/blob/master/gambar/S4.JPG)

In case of losing, the map then will be revealed, the bombs and the numbers. However, if you win, there only will state that you win (because you evade all the bombs).
Let’s look at this directory (4,4) → increment to (5,5)
5 → the 5th row
5 → the 5th column
Check the fifth row and the fifth column, open the square. That happens to be a bomb. Then, you lose the game.
