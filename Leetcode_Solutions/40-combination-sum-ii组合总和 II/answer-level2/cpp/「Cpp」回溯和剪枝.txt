### 解题思路

剪枝1: 重复选择

例如，1',1'',2,5,7中, 其中1'和1''是相同的数字，因此同一分支里只需要有一个1，但是1'的分支下还可以有1'',

剪枝代码`if ( i != depth && candidates[i] == candidates[i-1]) continue;` 

剪枝2: 已经不对的分支。

例如，我们目标是2, 如果此时选了5，这套分支后面就没有必要继续分开了

### 代码

```cpp
class Solution {
private:
    vector<vector<int>> res;
    vector<int> comb;
    vector<int> candidates;
public:
    vector<vector<int>> combinationSum2(vector<int>& _candidates, int target) {

        candidates = _candidates;
        sort(candidates.begin(), candidates.end());
        
        DFS(0, 0, target);
        return res;

    }
    void DFS(int depth, int total, int target){
        if (target == total){
            res.push_back(comb);
            return;
        }

        for (int i = depth; i< candidates.size(); i++){
            if ( i != depth && candidates[i] == candidates[i-1]) continue;
            if ( total + candidates[i] > target) continue;

            comb.push_back(candidates[i]);
            DFS(i+1, total + candidates[i], target);
            comb.pop_back();
        }
        return ;
    }
};
```