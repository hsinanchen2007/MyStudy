### 解题思路
和47题方法类似: https://leetcode-cn.com/problems/permutations-ii/solution/qu-zhong-tiao-jian-vectorzuo-bian-de-yi-ding-yao-b/

去重条件: 如果是重复的元素，访问这个元素时候，左边的元素一定已经被访问过了, 比如[2,2]，访问右边的2时，左边的2一定已经被访问过了。

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        vector<bool> table(nums.size(), false);
        vector<int> combination;
        getCombination(res, nums, combination, table, 0);
        return res;
    }

    void getCombination(vector<vector<int>> &res, vector<int>& nums, vector<int> &combination, vector<bool> &table, int idx){
        if(combination.size() > res.size()){
            return;
        }else{
            res.push_back(combination);
        }
        for(int i = idx; i < nums.size(); ++i){
            if(table[i] == true) continue;
            if(i > 0 && nums[i] == nums[i-1] && !table[i-1]) continue;
            combination.push_back(nums[i]);
            table[i] = true;
            getCombination(res, nums, combination, table, i+1);
            combination.pop_back();
            table[i] = false;
        }
    }
};
```

### 结果
执行用时 : 0 ms , 在所有 C++ 提交中击败了 100.00% 的用户 
内存消耗 : 7.2 MB , 在所有 C++ 提交中击败了 100.00% 的用户