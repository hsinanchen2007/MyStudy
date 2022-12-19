这道题其实不是easy题，估计是面试的时候被考烂了，所以当成easy题了。。。

两种解法，动态规划，需要数组额外空间以及在线更新不需要额外O(N)的空间。

都贴下代码，都很好理解，第二种不理解的可以看[连续子数组的最大和](<https://bbkgl.github.io/2019/09/26/%E8%BF%9E%E7%BB%AD%E5%AD%90%E6%95%B0%E7%BB%84%E7%9A%84%E6%9C%80%E5%A4%A7%E5%92%8C/>)。

### 动态规划

相当简单，递推公式，`dp[i] = max(dp[i-1] + nums[i], nums[i])`。

```cpp
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int m = nums.size();
        int *dp = new int[m];
        int ans = dp[0] = nums[0];
        for (int i = 1; i < m; i++) {
            dp[i] = max(dp[i-1] + nums[i], nums[i]);
            ans = max(ans, dp[i]);
        }
        delete[] dp;
        return ans;
    }
};
```

### 在线更新

可以看[连续子数组的最大和](<https://bbkgl.github.io/2019/09/26/%E8%BF%9E%E7%BB%AD%E5%AD%90%E6%95%B0%E7%BB%84%E7%9A%84%E6%9C%80%E5%A4%A7%E5%92%8C/>)，不再赘述。

```cpp
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = INT_MIN;
        int tempsum = 0;
        for (const int &it : nums) {
            if (tempsum <= 0)
                tempsum = it;
            else
                tempsum += it;
            ans = max(tempsum, ans);
        }
        return ans;
    }
};
```



