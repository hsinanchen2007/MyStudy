### 解题思路
跳上第n阶台阶的方式是 跳上第n-1阶台阶的方式加上跳上第n-2阶台阶的方式。 所以 f(n) = f(n-1) + f(n-2). 这就是个斐波那契数列。只是f(0)=1,f(1)=2;

### 代码

```cpp
class Solution {
public:
    int numWays(int n) {
        if (n == 0) {
            return 1;
        }
        if (n == 1) {
            return 1;
        }
        int a = 1, b = 1, t = 0;
        for (int i=1; i<n; i++) {
            t = a;
            a = b;
            b = t + b;
            if (b > 1000000007) {
                b = b % 1000000007;
            }
        }
        return b;
    }
};
```