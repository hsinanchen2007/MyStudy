### 解题思路
作者 [Paul](https://leetcode-cn.com/problems/count-all-valid-pickup-and-delivery-options/solution/zu-he-shu-xue-ti-by-paulzfm/) 对思路介绍的很详细，这里就不再赘述了。可将推导公式计算一下即可。
由公式：

$$P(n)=P(n-1)\times (C^2_{2(n-1)+1}+C^1_{2(n-1)+1})=P(n-1)\times ((2n+1)(n-1)+1)$$
### 代码
```python []
class Solution:
    def countOrders(self, n: int) -> int:
        mod = 1000000007
        p_n = 1
        for i in range(2, n + 1):
            p_n = p_n * ((2 * i + 1) * (i - 1) + 1) % mod
        return p_n
```
```C++ []
const int mod = 1000000007;
class Solution {
public:
    int countOrders(int n) {
        long long p_n = 1;
        for (int i = 2; i <= n; ++i){
            long long tmp = (2 * i + 1) * (i - 1) + 1;
            p_n = (p_n * tmp) % mod;
        }
        return p_n;
    }
};
```


