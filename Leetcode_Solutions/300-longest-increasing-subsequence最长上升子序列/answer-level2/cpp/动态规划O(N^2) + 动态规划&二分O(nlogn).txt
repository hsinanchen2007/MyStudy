
## 动态规划O(N^2)

### 01背包

dp[i]表示以第i个元素结尾的，最长上升子序列的长度

如果存在第i个元素大于之前的某个元素 nums[j]; `dp[i] = Max(dp[i], dp[j] + 1)`

### 代码实现

cpp

```cpp
bool cmp(int a, int b){
    return a < b;
}
class Solution {
public:
    int lengthOfLIS(vector<int> &nums) {
        if (nums.size() == 0) return 0;
        vector<int> dp(nums.size(), 1);
        for (int i = 1; i < nums.size(); i++) 
            for (int j = i-1; j >=0; j--) 
                if (nums[j] < nums[i]) 
                    dp[i] = max(dp[i], dp[j] + 1);
        return *max_element(dp.begin(), dp.end(), cmp);
    }
};
```

## 动态规划+二分O(nlogn)

f[i] 表示 长度为 i+1的递增子序列 最后一个元素的最小值

```cpp
class Solution {
public:
    int f[100000];
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;
        for (auto &n: nums){
            if (cnt == 0 || n > f[cnt -1]) f[cnt++] = n; // 大于 末尾元素 直接追加
            else f[divid(0, cnt - 1, n)] = n; // 找到第一个大于等于当前位置元素的 位置，替换
        }
        return cnt;
    }

    int divid(int l, int r, int n){ // 找到第一个大于等于n的元素
        while (l < r){
            int mid = l + r >> 1;
            if (f[mid] >= n) r = mid;
            else l = mid + 1;
        }
        return l;
    }
};
```
