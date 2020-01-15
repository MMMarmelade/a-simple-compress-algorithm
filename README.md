# a-simple-compress-algorithm

As we known, the image are store based on the gray values, which are stored in the computer by 8-bits. However, sometimes, when the image is quite dark, all the values are smaller, and these values can represented by less-bits.

The algorithm cut the gray values sequence into several segments, in which all the values have the same bits, and each segment has a header ,which record how many values it contains (max:256, 8-bits) and how many bits each value needs(max:8, 3-bits).Therefore, the header will add 11 padding bits. 

By dynamic programming, this algorithm will find a optimal seperating solution, the goal is minimizing the total bits.

For example, the sequence P:{10,11,12,9,255,1,2,3}. The optimal solution is seperating 3 segments, {10,11,12}, {255}, {1,2}. By this way, (11+4x4)+(11+8)+(11+2x3)=63 bits are needed, less than the regular (8x8)=64.
