## 思路
本题实质是求在一个数组中取出一个或多个不相邻数，使其和最大。这类求极值问题考虑动态规划。
动态规划：维护一个大小等于已给数组dp，其中dp[i]表示在i位置时不相邻数所能形成的最大值。
举例：[1, 2, 3, 1]，在第一个位置时dp[0] = 1, 在第二个位置时dp[1] = 2，在第三个位置时，因为不能连续取两个数，所以我们用当前元素加上再前面的dp值和当前元素前面一个dp值比较，取较大值作为当前dp值，即：
`dp[i] = max(dp[i-1], dp[i-2] + num[i])`

## 代码
时间复杂度：O(n)
空间复杂度：O(n)
```
class Solution {
public:
    int rob(vector<int>& nums) {
        int size = nums.size();
        if (size <= 1) return size == 1 ? nums[0] : 0;        
        vector<int> dp(size);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for (int i = 2; i < size; ++i) {
            dp[i] = max(nums[i] + dp[i - 2], dp[i - 1]);
        }
        return dp.back();
    }
};
```

### 官方写法：优化空间复杂度
因为每一步只需保存前两个最大值，可以用两个变量。
时间复杂度：O(n)
空间复杂度：O(1)
```c++
int rob(vector<int>& nums) {
    int preMax = 0;
    int curMax = 0;
    for (int x : nums) {
        int tmp = curMax;
        curMax = max(preMax+x, curMax);
        preMax = tmp;
    }
    return curMax;
}
```


