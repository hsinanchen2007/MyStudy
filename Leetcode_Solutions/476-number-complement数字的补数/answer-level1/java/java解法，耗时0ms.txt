![LeetCode.PNG](https://pic.leetcode-cn.com/9e17e4fd4fd3b2a59ad4cc443f645f0a2b1b6fe58072dd57e59b505c9f219e12-LeetCode.PNG)

解题思路：
原码 + 补码 = 对应位数的最大值
例：
5 原码 101 对应位数最大值 111 补码 010
101 + 010 = 111;

源码：
class Solution {
    public int findComplement(int num) {
        long temp = 1;
        while(num >= temp)
            temp <<= 1;
        return (int)(temp - 1 - num);
    }
}
