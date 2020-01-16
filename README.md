# a-simple-compression-algorithm

As we known, the image are store based on the gray values, which are stored in the computer by 8-bits. However, sometimes, when the image is quite dark, all the values are smaller, and these values can represented by less-bits.

The algorithm cut the gray values sequence into several segments, in which all the values have the same bits, and each segment has a header ,which record how many values it contains (max:256, 8-bits) and how many bits each value needs(max:8, 3-bits).Therefore, the header will add 11 padding bits. 

By dynamic programming, this algorithm will find a optimal seperating solution, the goal is minimizing the total bits.

For example, the sequence P:{10,11,12,9,255,1,2,3}. The optimal solution is seperating 3 segments, {10,11,12}, {255}, {1,2}. By this way, (11+4x4)+(11+8)+(11+2x3)=63 bits are needed, less than the regular (8x8)=64.


By the way, I learned the algorithm at https://www.bilibili.com/video/av7134874, which is the open algorithm courses made by Peking University. *For this compression-algorithm, the course video presents the pseudocode, but there's a mistake, the header is added at the end, actually, it should be added during the processing, otherwise, the compare results would be wrong.

The small mistake confused me for hours, which make me not sleep until 2 a.m.>_<. On the other hand, thanks to the mistake, I get much more familier to this algotithm.

各位有一起学习北大算法课 （https://www.bilibili.com/video/av7134874 ）的同学注意下，视频中给出的伪码有误，+header应该在过程中就加上，不能最后加，最后加会使得比较的时候不是正确的S[i]比较，结果自然就错了。
