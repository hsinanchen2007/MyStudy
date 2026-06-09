解题思路：容易想到用减法代替除法，但是若出现除数很小，而被除数很大的情况，则单纯的减法很耗时间，所以想到放大除数，但是不可以使用乘除，那么就用移位来实现。

因此有以下的思路：每次将除数复制后进行移位到比被除数小的最大的数（同时设置一个mask，初始为1, 同时进行移位），再将被除数减去该数，此时mask的值就为减去的除数的个数。另外需要注意的是符号的问题，有负号的话不方便比较大小，所以先将除数和被除数都取绝对值，若两者符号不同，需要对最后的结果取相反数（位运算实现，取反加一或者减一再取反）。

PS：因为只有32位，考虑到在运算过程中涉及2^31，换成无符号格式，被INT_MAX和INT_MIN这两个数折磨得不像话。

考虑比如出现初始为INT_MIN，怎么去掉它的符号；

结果为INT_MIN的时候要怎么从2^31得到INT_MIN；

除数为2^31时，移位会有什么影响。
```
class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == INT_MIN && divisor == -1)
            return INT_MAX;
        int sign = (dividend ^ divisor) >= 0 ? 1 : -1;
        unsigned int mydivisor = divisor == INT_MIN ? (unsigned int) (INT_MAX) + 1:abs(divisor);
        unsigned int mydividend = dividend == INT_MIN ? (unsigned int) (INT_MAX) + 1:abs(dividend);
        unsigned int res = 0;
        while(mydividend >= mydivisor){
            unsigned int temp = mydivisor, mask = 1;
            while(temp && mydividend >= temp){
                mydividend -= temp;
                res += mask;
                mask <<= 1;
                temp <<= 1;
            }
        }
        if(sign == -1)
            res = ~(int)(res - 1);
        return res;
    }
};
```

