### 解题思路
简单dp O(n)复杂度

![image.png](https://pic.leetcode-cn.com/5f8d3e9512bb66a17bf1ab9caece7d14e07d76a451dddad875998ede746658b2-image.png)

[我的题解](https://www.github.com/wfnuser/leetcode)
[我的github](https://www.github.com/wfnuser)
最近沉迷刷题，真诚欢迎大家star和follow 最近也在学习和实现lua，欢迎交流

### 代码

```cpp
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int sum = 0;
        vector<int> dp(A.size(), 0);

        if (A.size() < 3) return 0;

        for (int i = 2; i<A.size(); i++) {
            if (A[i]+A[i-2] == 2*A[i-1]) {
                dp[i] += dp[i-1];
                dp[i]++;
            }
            sum += dp[i];
        }

        return sum;
    }
};
```