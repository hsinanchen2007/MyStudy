### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<int> candidates;
    vector<vector<int>> myVecVec;
    vector<int> paths;

void DFS(int start, int target){
    if(target == 0){
        myVecVec.push_back(paths);
        return;
    }

    for (int i = start; i < candidates.size(); ++i) {
        if(i > start){
            if(candidates[i] == candidates[i-1]){
                continue;
            }
        }
        if(candidates[i] <= target){
                paths.push_back(candidates[i]);
                DFS(i + 1, target - candidates[i]);
                paths.pop_back();
            }
            else{
                break;
            }
        }
        

}
vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    sort(candidates.begin(), candidates.end());
    this->candidates = candidates;
    DFS(0, target);
    return myVecVec;

}
};
```