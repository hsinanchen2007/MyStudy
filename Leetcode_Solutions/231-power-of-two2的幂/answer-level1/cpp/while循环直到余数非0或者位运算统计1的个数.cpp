### 解题思路
while循环直到余数非0，不是2的次幂最后会变成非1奇数；是2的次幂最后变成1，都会停止。

### 代码

```cpp
//method 1
class Solution {
public:
    bool isPowerOfTwo(int n) {
    if ( n == 0 )return false;//一定不要忘了0，不然死循环
    while( (n % 2) == 0)n = n / 2; //不是2的次幂最后会变成非1奇数；是2的次幂最后变成1，都会停止
    if ( n == 1 )return true;//注意随后判断的是1，而不是0
    else return false;
    }
};
//method 2
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n <= 0)return false;//2的幂不需要考虑负数，且0也不满足
        bitset<32>aim(n);
        bitset<32>check(1);
        int count = 0;
        
        for ( int i = 0 ; i <31 ; i++){
            if ( ((aim >> i) & check) == 1)count++;
            if ( count > 1 )return false;//统计1的个数
        }
        return true;
    }//计算机里二进制负数除符号位是补码存储，连bitset也是这样
};
```