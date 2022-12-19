### 解题思路
这道题目的就是DFS+剪枝，稍微有点技巧的地方在于剪枝, 比如[2,3] target = 7

###
```cpp 
                            2                           3
                          /   \                       /   \
                         2     3                     2     3
                        / \   / \                   / \   / \
                       2   3 2   3                 2   3  2  3
                      / \ 
                     2   3
```

如果不剪枝，那么遍历到叶子节点的结果如上，会产生3个有效的vector，[2,2,3], [2,3,2], [3,2,2]

我们只需要其中的[2,2,3]即可，如何只要[2,2,3]？
- 只要保证遍历的叶子节点在candidates中的idx一定 >= 之前的叶子节点在candidates中的idx即可

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> candidate_array;
        getCombination(res, candidates, candidate_array, 0, target, 0);
        return res;
    }
    void getCombination(vector<vector<int>> &res, vector<int>& candidates, vector<int> &candidate_array, int partial_sum, int &target, int idx){
        if(partial_sum == target){
            res.push_back(candidate_array);
        }else if(partial_sum > target){
            return;
        }else{// partial_sum < target
            for(int i = idx; i < candidates.size(); ++i){
                candidate_array.push_back(candidates[i]);
                getCombination(res, candidates, candidate_array, partial_sum + candidates[i], target, i);
                candidate_array.pop_back();
            }
        }
    }
};
```

### 结果
执行用时 : 8 ms , 在所有 C++ 提交中击败了 88.11% 的用户 
内存消耗 : 7.5 MB , 在所有 C++ 提交中击败了 100.00% 的用户