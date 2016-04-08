List of Bugs in ConnectX

First bug lies in InBound() function.
Where we are checking condition for width, we are not returning after width, we are still checking for height, if it is invalid.
it goes to height and return inside.

Second big lies in Constructor()
We are not checking for invalid value for X. 
It can be out of scope that is X bigger than the grid.
For Example:
if width is 5 and height is 6 and x is 50, it suppose to throw an error but it's not doing anything for that and ignorong it.
