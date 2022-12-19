```
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> pre;
        sort(nums.begin(), nums.end());
        find(nums, 0, nums.size(), pre, res);
        return res;
    }
    void find(vector<int>& nums, int start, int left, vector<int>pre, vector<vector<int>>& res)
    {
        vector<int> ret;
        res.push_back(pre);
        while(start<nums.size())
        {
            ret = pre;
            ret.push_back(nums[start]);
            find(nums, start+1, left-1, ret, res);
            while(start+1<nums.size() && nums[start] == nums[start+1])
            {
                start++;
            }
            start++;
        }
    }
};
```
