榜首的大佬说的很清楚了，回溯加剪枝。
这里谈下自己的理解，若有不对还请多多指出。

先给数组排序，从candidates某一个元素candidates[i]开始，如果它比target小，candidates[i]可以暂存到path中，从candidates[i]处继续开始dfs，因为candidates 中的数字可以无限制重复被选取。如果target==0，这是一个满足条件的组合。如果target比candidates[i]还小了，说明这次暂存的元素不合理，把它弹出(pop_back())，那它就会从candidates的下一个元素出发，继续dfs，直到结束整个过程。

```cpp
class Solution {
public:
    vector<int> path;
    vector<vector<int>> res;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        dfs(candidates,target,0);
        return res;
    }
    void dfs(vector<int>& candidates, int target,int start){
        if(target == 0){
            res.push_back(path);
            return ;
        }
        for(int i=start;i<candidates.size();i++){
            if(target >= candidates[i]){
                path.push_back(candidates[i]);
                dfs(candidates,target-candidates[i],i);
                path.pop_back();
            }
        }
    }
};
```