思路：先对数组排序，因为不能重复利用数组中元素，在每次回溯时，开始的序号要递增，同时，结果不能有重复解，每次放入解时，查询res中是否存在相同的解集。
```
class Solution {
public:
    vector<vector<int>> res;
    vector<int> temp;
    
    void solve(int id, vector<int>& nums, int target) {
        if(target == 0) {
            if(find(res.begin(), res.end(), temp) == res.end()) // 查询是否已有相同的解集
                res.push_back(temp);
            return ;
        }
        for(int i = id; i < nums.size() && target - nums[i] >= 0; i++) {
            temp.push_back(nums[i]);
            solve(i+1, nums, target-nums[i]); // 下一次回溯从下一个元素开始
            temp.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        solve(0, candidates, target);
        return res;
    }
};
```

