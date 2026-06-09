### 解题思路
快速幂算法。这里留意的是n为负数的时候，其实是需要将x取倒数。
另外一个坑是n为负数的时候，转为正数的时候会溢出，需要先转为long类型。

### 代码

```cpp
class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0) return 1;
        long N = n;
        if (n < 0) {
            x = 1/x;
            N = -N;
        }
        double res = 1;
       
        while (N > 0) {
            if ((N & 1) == 1) {
                res = res * x;
            }
            x *= x;
            N >>= 1;
        }
        return res;
    }
};
```