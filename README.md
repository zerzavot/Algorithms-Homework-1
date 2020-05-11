# Algorithms II - Homework 1

### Questions

1.  Given a set of M positive integers A = a 1 , . . . , a M , <br>
develop an dynamic programming that finds a partition A 1 , A 2 such that | S 1 − S 2 | is minimized,<br>
where S i is the sum of elements in A i .<br><br>
2.  Given bit strings X = x 1 x m , Y = y 1 y n , and Z = z 1 z m+n , <br>
if Z can be obtained by interleaving the bits in X and Y in a way that it maintains <br>
the left-to-right order of the bits in X and Y , then we say Z is an interleaving of X and Y .<br>
For example if X = 101 and Y = 01 , then Z = 10011 is an interleaving of X and Y , but Z = 11010 is not.<br>
Develop a (dynamic programming) algorithm that determines whether Z is an interleaving of X and Y or not.<br><br>
3.  Given an array of size n that has the following specifications:<br>
–  each element in the array contains either a policeman or a thief<br>
–  each policeman can catch only one thief<br>
–  policeman cannot catch a thief who is more than K units away from the policeman<br>
Devise a greedy algorithm that finds the maximum number of thieves that can be caught.<br>
Also, prove that your algorithm satisfies the greedy-choice property.<br>
For the array [ P, T, T, P, T ] and k = 1, your algorithm should output 2<br>
(first policeman catches first thief and second one catches either second or third thief) <br>
For the array [ T, T, P, P, T, P ] and k = 2 your algorithm should output 3.<br><br>

4.  Given a set of n activities A 1 , . . . , A n with the starting and finishing time (s i , f i )<br>
assigned to each activity and a number of rooms in which activities are performed. <br>
Develop a greedy algorithm that assign all the activities to minimum number of rooms so <br>
that no two overlapping activities are performed in same room.<br>
