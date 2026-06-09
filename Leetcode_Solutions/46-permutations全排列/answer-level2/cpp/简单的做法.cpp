```
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) 
    {
        if(nums.size() == 0) return {};
        if(nums.size() == 1) return {{nums[0]}};
        vector<vector<int>> res;        
        for(int i=0; i<nums.size(); i++)
        {
            vector<int> temp = nums;
            temp.erase(temp.begin() + i);
            vector<vector<int>> sol = permute(temp);
            for(auto s: sol)
            {
                s.insert(s.begin(), nums[i]);
                res.push_back(s);
            }
        }
        return res;
    }
};
```