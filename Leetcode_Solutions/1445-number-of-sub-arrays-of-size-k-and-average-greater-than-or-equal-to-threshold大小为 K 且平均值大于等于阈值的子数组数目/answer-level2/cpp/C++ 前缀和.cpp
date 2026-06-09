### 解题思路
先遍历一次，求出前缀和；后面计算数组和都使用前缀和相减计算。
![图片.png](https://pic.leetcode-cn.com/82fc3e31f8c28d46bb4501391d80f11a5c16ac450f4875ed1a93c1e6d387c169-%E5%9B%BE%E7%89%87.png)


### 代码

```cpp
class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int n = arr.size();
        vector<int> preSum(n + 1, 0);
        for (int i = 1; i <= n; ++i) {
            preSum[i] = arr[i - 1] + preSum[i - 1];
        }
        int ans = 0;
        for (int i = 0; i <= n - k; ++i) {
            int sum = preSum[i + k] - preSum[i];
            if (sum >= k * threshold) {
                ++ans;
            }
        }
        return ans;
    }
};
```