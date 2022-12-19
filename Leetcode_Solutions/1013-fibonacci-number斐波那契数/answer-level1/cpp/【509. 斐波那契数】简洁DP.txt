## 思路：动态规划
同[面试题10- I. 斐波那契数列](https://leetcode-cn.com/problems/fei-bo-na-qi-shu-lie-lcof/solution/mian-shi-ti-10-i-fei-bo-na-qi-shu-lie-7xing-dai-ma/)

如果使用递归f[n] = f[n-1] + f[n-2]会有大量重复计算，时间复杂度为O(n^2)，使用动态规划使时间复杂度为O(n)。

### 代码
时间复杂度：O(n)
空间复杂度：O(n)
```c++
class Solution {
public:
    int fib(int N) {        
        if (N == 0 || N == 1) {
            return N;
        }
        int f[N+1];
        f[0] = 0;
        f[1] = 1;
        for (int i = 2; i <= N; ++i) {
            f[i] = f[i-1] + f[i-2];
        }
        return f[N];
    }
};
```

### 优化空间复杂度
因为每个当前值只与前面两个数相关，所以可以利用两个变量优化空间复杂度。
```c++
class Solution {
public:
    int fib(int N) {        
        if (N == 0 || N == 1) {
            return N;
        }
        int a = 0, b = 1;        
        int res = 0;
        for (int i = 2; i <= N; ++i) {
            res = a + b;
            a = b;
            b = res;
        }
        return res;
    }
};
```
