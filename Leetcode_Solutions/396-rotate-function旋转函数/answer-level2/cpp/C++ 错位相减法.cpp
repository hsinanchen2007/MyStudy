### 解题思路
推导过程：
（1）`F(k) = 0 * Bk[0] + 1 * Bk[1] + ... + (n-2) * Bk[n-2] + (n-1) * Bk[n-1]`
（2）`F(k+1) = 0 * Bk[n-1] + 1 * Bk[0] + 2 * Bk[2] + ... + (n-1) * Bk[n-2]`
（2）`-`（1）得：`F(k+1) - F(k) = (Bk[0] + Bk[1] + ... + Bk[n-2]) - (n-1)*Bk[n-1]`
可得：`F(k+1) - F(k) = (Bk[0] + Bk[1] + ... + Bk[n-2] + Bk[n-1]) - n*Bk[n-1]`
令`S=Sum{Bk}`
有：`F(k+1) = F(k) + S - n * Bk[n-1]`

### 代码

```cpp
class Solution {
public:
    int maxRotateFunction(vector<int>& A) {
        long N = A.size();
        long S = 0;
        long t = 0;
        for (int i = 0; i < N; ++i) {
            S += A[i];
            t += i * A[i];
        }
        long res = t;
        for (int i = N - 1; i >= 0; --i) {
            // F(k+1) = F(k) + S - n * Bk[n-1]
            t += S - N * (long)A[i];
            res = max(res, t);
        }
        return res;
    }
};
```

![image.png](https://pic.leetcode-cn.com/aa21e87dd11b9e788bc946f7ea4f79fca8f0a27508757c3c4073bd7c479fb9ad-image.png)
