### 解题思路
排序后回溯,Set进行结果集去重

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>> numsSet;
        vector<int> subset;
        vector<vector<int>> sets;
        sort(nums.begin(), nums.end());
        FindSubset(0, nums, numsSet, subset, sets);

        return sets;
    }
private:
    void FindSubset(int i, vector<int>& nums, set<vector<int>>& numsSet, vector<int>& subset, vector<vector<int>>& sets)
    {
        if (i >= nums.size()) {
            if (numsSet.find(subset) == numsSet.end()) {
                numsSet.insert(subset);
                sets.push_back(subset);
            }
            return ;
        }
        subset.push_back(nums[i]);
        FindSubset(i + 1, nums, numsSet, subset, sets);
        subset.pop_back();
        FindSubset(i + 1, nums, numsSet, subset, sets);
    }
};
```