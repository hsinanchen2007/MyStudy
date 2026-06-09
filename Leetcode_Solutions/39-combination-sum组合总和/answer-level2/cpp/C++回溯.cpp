```C++ []
class Solution {
public:
    void backtrack(vector<vector<int>>& ans, vector<int>& nums, int i, int target, vector<int>& cur){
        if(target == 0){
            ans.push_back(cur);
            return;
        }
        if(target < nums[i])
            return;
        
        for(int s = i; s < nums.size(); s++){
            target = target - nums[s];
            cur.push_back(nums[s]);
            backtrack(ans, nums, s, target, cur);
            target = target + nums[s];
            cur.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> cur;
        backtrack(ans, candidates, 0, target, cur);
        return ans;
        
    }
};
```
讲道理，感觉回溯这个方法和DFS差不多