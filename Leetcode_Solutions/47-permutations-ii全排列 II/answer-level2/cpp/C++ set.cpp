### 解题思路
此处撰写解题思路
与上题类似 需要增加判断 防止多次以同一数字开头进行排列 这里用到了set 如果已经使用某个数字进行了排序就不再次排序

### 代码

```cpp
class Solution {
public:
    void backtrack(int n, vector<int> &nums, vector<vector<int>> &res, int first)
    {
        set<int>hasback;
        if(first == n)  res.push_back(nums);
        for(int i = first; i < n; i++)
        { 
            if(i!=first&&hasback.find(nums[i])!=hasback.end()) continue;
            hasback.insert(nums[i]);
            swap(nums[first], nums[i]);
            backtrack(n, nums, res,  first+1);
            swap(nums[first], nums[i]);
        }
        
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(),nums.end());
        backtrack(nums.size(), nums, res, 0);
        return res;
    }
};

```