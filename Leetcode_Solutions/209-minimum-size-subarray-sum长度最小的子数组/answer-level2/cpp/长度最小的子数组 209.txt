
关键点：
1、滑动窗口法
2、注意进入第二个while的时候，right已经++过了，所有在算长度的时候right - left的时候是多+1，就不用再减一了；
3、注意minLen初始值INT_MAX，第二层while循环不一定走的进去，如果还是初始值，返回0；
![image.png](https://pic.leetcode-cn.com/8f745a263079824c6c97c7bb381abd252e5c5baca46710c17f5c796976d475d6-image.png)
