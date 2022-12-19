![捕获.PNG](https://pic.leetcode-cn.com/5140f6b2a0426c072bfc48f4f9037fecd93a8f1f926ee4b289d446d39af11077-%E6%8D%95%E8%8E%B7.PNG)

```
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        long maxLen = pow(2, nums.size());
        vector<vector<int>> res;
        
        for (long i = 0; i < maxLen; ++i) {
            vector<int> oneAns;
            long t = 1;
            for (int j = 0; j < nums.size(); ++j) {
                if (i & t) {
                    oneAns.push_back(nums[j]);
                }
                t <<= 1;
            }
            res.push_back(oneAns);
        }
        return res;
    }
};
```
