# 题目分析：
求一个数是否是2的次幂，首先想到2进制表示下该数仅有一位为1，其余位均为0。
## 注意：输入类型为int，需先排除非正数。
## 思路一：逐位右移，当结果为奇数时，再右移一次的结果为0则为2的幂。
```C++
    bool isPowerOfTwo(int n) {
        if (n <= 0)
            return false;
        while(!(n%2)){
            n>>=1;
        }
        return (n>>=1)==0;
    }
```
## 思路二：n&n-1==0则为2的幂次方
```C++
    bool isPowerOfTwo(int n) {
        return (n>0)&&((n&(n-1))==0);
    }
```