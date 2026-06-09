```C++ []
class Solution {
public:
    void backtrack(vector<vector<int>>& ans, vector<int>& nums, int target, vector<int>& cur, int start){
        if(target == 0)
           ans.push_back(cur);
        if(target < 0)
            return;
        for(int i = start; i < nums.size(); i++){
            if(i > 0 && i != start && nums[i] == nums[i - 1]) continue;
            target = target - nums[i];
            cur.push_back(nums[i]);
            backtrack(ans, nums, target, cur, i + 1);
            
            target = target + nums[i];
            cur.pop_back();
            
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> cur;
        
        backtrack(ans, candidates, target, cur, 0);
        return ans;
    }
};

```

这个题实际上也是典型的回溯题目。但是因为有重复元素和只需要取组合使得问题复杂了起来。


- 对于组合，进行排序，一直向数组的后面取数。

- 对于重复元素的处理，实际上重复元素在单一的结果中可以选取，但是在多个结果中如何选中重复的元素的话，会使得结果出现重复。if(i > 0 && i != start && nums[i] == nums[i - 1])该判断首先要确保i-1有意义，确保同样的数只有第一次出现的时候才会计入解中。
