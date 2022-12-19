### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> result;
    vector<int> temp;
    
    vector<vector<int>> subsets(vector<int>& nums) 
    {
        for(int up = 0; up <= nums.size(); up++)
            backtrack(0, nums, up);
        return result;
    }

    void backtrack(int start, vector<int>& nums, int up)
    {
        if(temp.size() == up)
        {
            result.push_back(temp);
            return;
        }

        for(int i = start; i < nums.size(); i++)
        {
            temp.push_back(nums[i]);
            backtrack(i + 1, nums, up);
            temp.pop_back();
        }
    }
};
```