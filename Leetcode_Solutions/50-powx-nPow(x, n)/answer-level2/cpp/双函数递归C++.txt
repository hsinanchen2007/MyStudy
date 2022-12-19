### 解题思路
大体思路官方题解说的很清楚，记录一下细节问题：

1，中间变量一定要用更高精度的double，中间结果尽可能精度高点，最后取小数点后5位。
2，对于n，要有个更大范围的N，用来避免：当n是下界（2的31次方）转换成-n时，超过上界（2的31次方减一）。

### 代码

```cpp
class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0) {
            return 1.0;
        }
        
        long N = n;
        if (N < 0) {
            N = -N;
            return 1 / pow(x, N);
        }
        else {
            return pow(x, N);
        }
    }

    double pow(double x, long n) {
        double y = myPow(x, n/2);
        y = y * y;
        if (n % 2) {
            y = y * x;
        }
        return y;
    }
};
```

![微信图片_20200112143833.png](https://pic.leetcode-cn.com/56353d91ac8ae22652b9fb496a1f96fddbcb42f2432283d1da31210ad707a9c5-%E5%BE%AE%E4%BF%A1%E5%9B%BE%E7%89%87_20200112143833.png)
