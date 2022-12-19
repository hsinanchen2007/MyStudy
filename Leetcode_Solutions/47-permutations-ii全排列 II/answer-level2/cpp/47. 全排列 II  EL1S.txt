这道题和46题很相似，这两题的区别是，46题没有重复数字，47有重复数字。
重复数字带来的问题，某一个位置如果相同数字重复出现，并且不用set来剔除的话，答案就会有很多的重复。
因此这里用了last来避免同一个位置有多次相同数字的出现。

```
class Solution {
    vector<int> nums;
    vector<int> v;
    vector<vector<int>> res;

    void dfs(long long state)
    {
        if(state == (1 << nums.size()) - 1)
        {
            res.push_back(v);
            return;
        }
        long long last = -100000000;//上一步选择的是什么
        for(int i = 0; i < nums.size(); i++)
        {
            if(!((1 << i) & state))
            {
                if(nums[i] != last)
                {
                    state ^= (1 << i);
                    v.push_back(nums[i]);
                    last = nums[i];
                    dfs(state);
                    v.pop_back();
                    state ^= (1 << i);
                }
                
            }
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& _nums) {
        nums = _nums;
        sort(nums.begin(), nums.end());
        long long state = 0;    
        dfs(state);
        // return vector<vector<int>>();
        return res;
    }
};
```
