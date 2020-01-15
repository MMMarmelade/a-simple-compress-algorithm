# a-simple-compress-algorithm

As we known, the image are store based on the gray values, which are stored in the computer by 8-bits. However, sometimes, when the image is quite dark, all the values are smaller, and these values can represented by less-bits.

The algorithm cut the gray values sequence into several segments, in which all the values have the same bits, and each segment has a header ,which record how many values it contains (max:256, 8-bits) and how many bits each value needs(max:8, 3-bits).Therefore, the header will add 11 padding bits. 

By dynamic programming, this algorithm will find a optimal seperating solution, the goal is minimizing the total bits.
