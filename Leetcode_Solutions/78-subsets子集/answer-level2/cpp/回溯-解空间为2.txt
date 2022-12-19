### 解题思路
关键点：数字不重复。不能包含重复子集
思路：
1、不重复子集：同一组合不能多次选。
2、每个数字仅有2种情况：被选中或不被选中
3、每层递归两种选择。即**该题每次决策的解空间为2.**

### 代码

```cpp
class Solution {
public:
    void FindSubset(int i, vector<int>& nums, vector<int>& subset, vector<vector<int>>& sets)
    {
        if (i >= nums.size()) {
            sets.push_back(subset);
            return ;
        }
        subset.push_back(nums[i]);
        FindSubset(i + 1, nums, subset, sets);
        subset.pop_back();
        FindSubset(i + 1, nums, subset, sets);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> sets;
        vector<int> subset;

        FindSubset(0, nums, subset, sets);
        return sets;
    }
};
```