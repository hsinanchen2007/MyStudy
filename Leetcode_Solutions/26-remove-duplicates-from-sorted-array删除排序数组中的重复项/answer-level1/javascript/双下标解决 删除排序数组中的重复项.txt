![image.png](https://pic.leetcode-cn.com/ba4025abded9fbc6502cbfc3ea77b27eb1d2af94aeddc60845750c1b7b00d6ca-image.png)
定义两个下标 一个为i，一个为j 分别记录当前地址和比较地址；
定义i为0 ，j为1；若是相同，则j往后走一步，若是不同，则把j的值赋值给i+1的地址上；当j=nums.length时，也就是整个数组都遍历完成，这时候 i就是要返回的长度