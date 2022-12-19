这道题和生成有效括号对的解法类似，都是每一层可以有两个选择。在这一题中，每一个元素可以选择有或无，并产生一个新的子集。

```
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> subset;
        resub(0, result, subset, nums);
        return result;
    }

    void resub(int level, vector<vector<int>>& result, vector<int>& subset, vector<int>& nums)
    {
        if(level == nums.size())
        {
            result.push_back(subset);
            return ;
        }

        subset.push_back(nums[level]); //该元素为有
        resub(level + 1, result, subset, nums);
        subset.pop_back(); //该元素为无
        resub(level + 1, result, subset, nums);
    }
};
```
