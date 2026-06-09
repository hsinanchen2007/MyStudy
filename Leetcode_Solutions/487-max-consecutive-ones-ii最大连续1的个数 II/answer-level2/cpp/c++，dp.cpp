dp1表示以当前数结尾的将0转为1的1的个数（如 0 0 1，dp1 = 2）  
dp0表示以当前数结尾的连续1的个数（未用掉0转为1的机会）  
有如下关系：
- num == 1：dp1 = dp1 + 1, dp0 = dp0 + 1
- num == 0：dp1 = dp0 + 1, dp0 = 0
```
    int findMaxConsecutiveOnes(vector<int> &nums) {
        int dp1 = 0;
        int dp0 = 0;
        int res = -1;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == 1) {
                dp1 = dp1 + 1;
                dp0 = dp0 + 1;
            } else {
                dp1 = dp0 + 1;
                dp0 = 0;
            }
            res = max(dp1, max(res, dp0));
        }
        return res;
    }
```