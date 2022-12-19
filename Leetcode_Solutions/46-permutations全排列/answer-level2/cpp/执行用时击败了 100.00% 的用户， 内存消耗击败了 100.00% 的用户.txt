### 解题思路
就是最基本DFS+hash去重

为何可以击败100%？
- 因为我在递归中，对每个vector都使用了引用，减少了开辟内存的时间

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> table(nums.size(), 0);
        vector<vector<int>> res;
        vector<int> combination;
        getCombination(res, nums, combination, table);
        return res;
    }

    void getCombination(vector<vector<int>>& res, vector<int>& nums, vector<int> &combination, vector<int> &table){//这里要用引用
        if(combination.size() >= nums.size()){
            res.push_back(combination);
            return;
        }
        for(int i = 0; i < nums.size(); ++i){
            if(table[i] == 0){
                combination.push_back(nums[i]);
                table[i] = 1;
                getCombination(res, nums, combination, table);
                combination.pop_back();
                table[i] = 0;
            }
        }
    }
};
```

### 结果
执行用时 : 0 ms , 在所有 C++ 提交中击败了 100.00% 的用户 
内存消耗 : 7.1 MB , 在所有 C++ 提交中击败了 100.00% 的用户