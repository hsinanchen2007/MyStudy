Leetcode 191 编写一个函数，输入是一个无符号整数，返回其二进制表达式中数字位数为 ‘1’ 的个数（也被称为汉明重量）。

示例 1：

输入：00000000000000000000000000001011
输出：3
解释：输入的二进制串 00000000000000000000000000001011 中，共有三位为 '1'。

解法一：众所周知，有符号数的最高位是1，那么我们可以将n强制转为有符号数类型，将所有的1都逐个左移到最高位，这样只需判断是否为负数即可。
代码实现：
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        while ( n ){
            if ( signed(n) < 0 )
                count++;
            n <<= 1; 
        }
        return count;
        
    }
};

解法二：上述解法有一个缺点，假如n=00000001，那么循环体中判负条件中，其实多判了很多次0，如果能将n中的0都去掉，那么循环次数肯定会少。
利用位运算n&(n-1)来去掉0。代码如下：
class solution{
public:
    int hammingWeight(uint32_t n){
        int count = 0;
        while( n ){
            n &= n - 1;
            count++;
        }
    return count;
    }
};