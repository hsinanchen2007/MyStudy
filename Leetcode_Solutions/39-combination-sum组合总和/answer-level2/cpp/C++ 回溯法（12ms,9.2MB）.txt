```
class Solution {
public:
    void backtrack(vector<int> &candidates, vector<vector<int>> &result, vector<int>& path, int num, int i)
    {
        if (num < 0 || i >= candidates.size())
            return;
        if (num == 0)
        {
            result.push_back(path);
            return;
        }
        for (int j = i; j < candidates.size(); j++)
        {
            path.push_back(candidates[j]);
            num -= candidates[j];
            backtrack(candidates, result, path, num, j);
            path.pop_back();
            num += candidates[j];
        }
    }

    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> result;
        if (candidates.front() > target)
            return result;
        vector<int> path;
        backtrack(candidates, result, path, target, 0);
        return result;
    }
};
```
