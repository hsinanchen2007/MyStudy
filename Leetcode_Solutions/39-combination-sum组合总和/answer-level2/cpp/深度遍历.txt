### 解题思路
1、由于可以使用重复的数字，针对每个数字都递归一遍候选序列，直到满足要求或超过目标值。
2、在递归过程中，后面的数字会重复前面数字的递归序列，需要去除重复，即每层递归，当前数字只从当前值开始。

### 代码

```cpp
class Solution {
public:
void combinationSum(vector<vector<int>>& res, vector<int>& candidates, int target, vector<int>& vec, int start){
    for(int i = start; i < candidates.size(); i++){
        vector<int> iVec(vec);
        if(candidates[i] == target){
            iVec.push_back(candidates[i]);
            res.push_back(iVec);
        }else if(candidates[i] < target){
            iVec.push_back(candidates[i]);
            combinationSum(res, candidates, target - candidates[i], iVec, i);
        }
    }
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> res;
    vector<int> vec;
    combinationSum(res, candidates, target, vec, 0);
    return res;
}
};
```