```
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        if(nums.size()==0)
            return {};
        vector<vector<int>> rst;
        permute_nums(nums,0,rst);
        return rst;
    }
    void permute_nums(vector<int>& nums, int begin,vector<vector<int>>& rst) {
        if(begin == nums.size()-1)
            rst.push_back(nums);
        for(int i = begin; i < nums.size(); i++)
        {    
            int tmp = nums[begin];
            nums[begin] = nums[i];
            nums[i] = tmp;
            permute_nums(nums,begin+1,rst);
            tmp = nums[begin];
            nums[begin] = nums[i];
            nums[i] = tmp;
        }
    }
};
```

