一、暴力求解：
```C++
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n == 0) return false;
        while (n != 1) {
            if (n % 2 != 0) {
                return false;
            } else {
                n = n / 2;
            }
        }
        return true;
    }
};
```

二、位运算：
2的幂（n）的二进制中只有一位为1，所以(n-1)的二进制中只有一位为0，例如：n=4时，二进制位100， n-1的二进制位011。n&(n-1)所得结果为0.
```C++
class Solution {
public:
    bool isPowerOfTwo(int n) {
        return n <= 0 ? false : ((n & (n-1)) == 0);
    }
};

```

