假设数字为  1 2 3 4 5
这里借用动态规划的思想，假设数据集为 1 2 3的子集都求出，此时应该如何求 1 2 3 4的子集呢？
1 2 3 的子集为： 1，2，3 ，12,13，123,23，{}。
那么假如一个4时，应该将4分别添加到上面所有子集中去。
能够得到：1，2,3,14,24,34,124,134,1234,234，{}，4
即为所求。
代码如下：
```
vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp;
        for(int i = 0;i < n;i++){
            if(dp.size() > 0){
                int m = dp.size();
                for(int j = 0;j < m;j++){
                    vector<int>temp = dp[j];
                    temp.push_back(nums[i]);
                    dp.push_back(temp);
                }
            }
          dp.push_back({nums[i]});
        }
        dp.push_back({});
        return dp;
    }
```
