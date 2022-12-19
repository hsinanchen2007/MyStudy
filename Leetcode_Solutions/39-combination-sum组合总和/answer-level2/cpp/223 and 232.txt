2 3 6 7
遍历到23之后，不要再从2开始取值，而是从3开始取值。

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        if (candidates.empty()) return {};
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ret;
        vector<int> aux;
        dfs(candidates, target, 0, aux, ret);
        return ret;
    }
    
    void dfs(vector<int>& candidates, int target, int start, vector<int>& aux, vector<vector<int>>& ret) {
        if (target == 0) {
            ret.push_back(aux);
            return;
        }
        for (int i = start; i < candidates.size() && target - candidates[i] >= 0; ++i) {
            aux.push_back(candidates[i]);
            dfs(candidates, target - candidates[i], i, aux, ret);
            aux.pop_back();
        }
    }
};