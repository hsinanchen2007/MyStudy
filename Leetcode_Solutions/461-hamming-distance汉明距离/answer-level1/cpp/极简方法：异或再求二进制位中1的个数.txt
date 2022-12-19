LeetCode 461 汉明距离
两个整数之间的汉明距离指的是这两个数字对应二进制位不同的位置的数目。
给出两个整数 x 和 y，计算它们之间的汉明距离。
注意：
0 ≤ x, y < 231.
思路：读题目很容易想到使用异或操作，则异或结果中每位上1的个数即为两个整数二进制位不同的位置的数目（汉明距离）。
且异或之后，题目转化为LeetCode191和剑指offer15题--求二进制位中1的个数。
下面是代码实现：
class Solution {
public:
    int hammingDistance(int x, int y) {
        int count = 0;
        int a = x ^ y;
        
        while ( a ){
            a &= a - 1;//只要n二进制位中有1，就会进行该运算
            count++;
    
        }
        return count; 
    }
};
