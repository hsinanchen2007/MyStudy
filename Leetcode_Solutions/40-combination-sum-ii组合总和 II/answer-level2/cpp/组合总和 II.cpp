### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int> > res;
        vector<int> item;
        DFS(candidates, 0, res, target, item);
        return res;
    }

    void DFS(vector<int>& candidates, int index, vector<vector<int>>& res, int remain, vector<int>& item) {
        if (remain == 0) {
            res.push_back(item);
            return;
        } 

        if (index == candidates.size() || remain < 0) {
            return;
        }
        for(int i = index; i < candidates.size(); ++i) {
            //cout<<i<<endl;
            if (i > index && candidates[i] == candidates[i-1]) {
                continue;
            }
            item.push_back(candidates[i]);
            DFS(candidates, i+1, res, remain-candidates[i], item);
            item.pop_back();
        }
    }
};
```