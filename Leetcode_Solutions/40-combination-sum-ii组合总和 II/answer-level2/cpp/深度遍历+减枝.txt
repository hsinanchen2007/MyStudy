### 解题思路
1、采用深度递归遍历，每次遍历子序列；若符合要求，加入返回序列；若当前数值小于目标，进入下一轮递归；若大于目标值，退出递归。
2、题目要求，每个解中，数列中的数字只能出现一次；所以每次需要子递归需要从当前值的下一个值开始。
3、由于数列中存在重复值，需要去除重复值，前面数值的递归包含后面的重复数值的递归，所以需要跳过后面的重复值，在最好开始时，就排序数列，重复值相邻，便于处理。

### 代码

```cpp
class Solution {
public:
void dfs(vector<vector<int>>& res, vector<int>& candidates, int target, vector<int>& vec, int starter){
    for(int i = starter; i < candidates.size(); i++){ 
        if(i - 1 >= starter && candidates[i - 1] == candidates[i]) //去除后续数列中的重复值
            continue;
        vector<int> iVec(vec);
        if(candidates[i] == target){
            iVec.push_back(candidates[i]);
            res.push_back(iVec);
        }else if(candidates[i] < target){
            iVec.push_back(candidates[i]);
            dfs(res, candidates, target - candidates[i], iVec, i + 1); //子递归从下一个值开始，去重，同时数值只能出现一次。
        }
    }
}

vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    sort(candidates.begin(), candidates.end());
    vector<vector<int>> res;
    vector<int> vec;
    dfs(res, candidates, target, vec, 0);
    return res;
}
};
```