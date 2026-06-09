

LeetCode 342 4的幂
给定一个整数 (32 位有符号整数)，请编写一个函数来判断它是否是 4 的幂次方。
若num为4的幂，则num必定为2的幂。将4的幂用二进制表示有：
4       100         1在第三位；
16      10000       1在第五位；
64      1000000     1在第七位；
...
可以发现4的幂二进制位中奇数位为1，偶数位为0.如果num为4的幂，将4&10101010101010101010101010101010（0x55555555）可以得到num自身 
class Solution {
public:
    bool isPowerOfFour(int num) {
        if ( num <= 0 )
            return 0;
        //判断num是否为2的次幂
        if ( num & (num - 1) )
            return 0;
        //判断num是否为4的次幂
        if ( ( num & 0x55555555 ) ==num )
            return 1;
        return 0;
    }
};


暴力循环法：
class Solution {
public:
    bool isPowerOfFour(int num) {
        while ( num && ( (num % 4) ) == 0 ){
            num /= 4;
        }
        return num == 1;
        
    }
};