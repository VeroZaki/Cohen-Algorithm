# Cohen-Algorithm
Cohen Sutherland Line Clipping Algorithm:
In this Algorithm we have 3 cases
1) If the line is visible (Inside the window)
2) If the line is not visible (Outside the window)
3) It the clipping case

Note: Cohen made his algorithm specialy for case three.

1) Visible:
The line is visible only if the start and the end points anre inside the coordinates of the window.
if((xmin <= x <= xmax) && (ymin <= y <= ymax)) then Accepted

2) Not Visible:
The line is visible only if the start and the end points anre outside the coordinates of the window, but in cohen's case the codes of the two points are not equal to 0000.

3) Clipping:
