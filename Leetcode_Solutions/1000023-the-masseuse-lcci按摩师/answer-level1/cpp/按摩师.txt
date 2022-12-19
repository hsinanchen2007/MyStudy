### 解题思路
这道题是我参考官方答案写的，自己没想出来，采用动态规划的思想来解答

### 代码

```cpp
class Solution {
public:
    int massage(vector<int>& nums) {
        
        int n = nums.size();
        if(!n)
            return 0;
        int dp0 = 0;
        int dp1 = nums[0];
        for(int i=1;i<n;i++){
            int tdp0 = max(dp0,dp1);
            int tdp1 = dp0+nums[i];
            dp0 = tdp0;
            dp1 = tdp1;
        }
        return max(dp0,dp1);
    }
};
```