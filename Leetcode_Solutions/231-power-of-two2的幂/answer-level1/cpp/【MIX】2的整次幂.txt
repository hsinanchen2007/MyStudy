### 解题思路
1. 如果$x$是$2^n$可以表示最大值的约数.
2. 位运算, 如果$x=2^n$, 有$x$^$-x=x$成立, 即x的二进制表示的最右侧的1即唯一的1.

### 代码

```c++ []
class Solution {
public:
    bool isPowerOfTwo(int n) {
        return (n>0) && (1<<30)%n==0;
    }
};
```

```c++ []
class Solution {
public:
    bool isPowerOfTwo(int n) {
        return (n>0) && ((n & -n)==n);
    }
};
```