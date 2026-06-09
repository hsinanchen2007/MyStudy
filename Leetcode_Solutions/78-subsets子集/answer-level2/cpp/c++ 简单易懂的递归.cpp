### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        if(nums.size()==0) return {{}};
        int n = nums[0];
        nums.erase(nums.begin());
        vector<vector<int>> dp = subsets(nums);
        vector<vector<int>> res;
        for(auto i:dp){
            res.push_back(i);
            i.push_back(n);
            res.push_back(i);
        }
        return res;  
    }
};
```