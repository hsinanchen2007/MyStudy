### 解题思路
投 i 轮骰子，sum 的范围是 [i, 6*i]
n 轮骰子的概率结果可以由 n-1 轮骰子的概率结果推导得出

![Xnip2020-03-13_11-00-23.jpg](https://pic.leetcode-cn.com/fdd899d1d00bf88549ed174d87c1133d3f490dbe950522473c842465b9db145c-Xnip2020-03-13_11-00-23.jpg)

### 代码
```cpp
class Solution {
public:
    vector<double> twoSum(int n) {
        const double D16 = 1.0 / 6.0;
        vector<double> res(6*n+1, 0.0);
        for (int i = 1; i <= 6; i++) {
            res[i] = D16;
        }
        for (int i = 2; i <= n; i++) {
            for (int j = 6*i; j >= i; j--) {
                res[j] = 0;
                for (int k = j-1; k >= i-1 && k >= j-6; k--) {
                    res[j] += (res[k] * D16);
                }
            }
        }
        return vector<double>(res.begin()+n, res.end());
    }
};
```
