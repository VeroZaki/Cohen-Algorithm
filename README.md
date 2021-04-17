# Cohen-Algorithm

The Cohen–Sutherland algorithm is a computer-graphics algorithm used for line clipping. The algorithm divides a two-dimensional space into 9 regions and then efficiently determines the lines and portions of lines that are visible in the central region of interest.

## The algorithm

We have three cases:
  - **First case:** If the binary of the line from the two ends is 0000 then line lies inside the window then "Accepted"
  - **Second case:** If the the binary of the two ends of the line is different but their anding results a 0000 then the line has an intersection in the window from here we have two      cases: :a: One end equals 0000 means lies inside the window XXXX means outside the window anding equals 0000 then we have one intersection.
          :b: Two ends differ but their anding equals 0000 means we have two intersections.
  - **Third case:** If the anding reult is not equal 0000 the the line is "Refused"
