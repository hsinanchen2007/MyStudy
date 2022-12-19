```c++
class Solution {
public:
    int target, sum;
    vector<int> candidates, tmp;
    vector<vector<int>> res;
    void dfs(int step) 
    {
        if (sum == target) {
            res.push_back(tmp);
            return;
        }
        if (sum > target) return;
        for (int i = step; i < candidates.size(); i++) {
            sum += candidates[i];
            tmp.push_back(candidates[i]);
            dfs(i);
            sum -= candidates[i];
            tmp.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        this->target = target;
        this->candidates = candidates;
        dfs(0);
        return res;
    }
};
```
![1568864268412.jpg](https://pic.leetcode-cn.com/36609453f8b37469a6d7ea58bfead73a8605a1bb6e681df1a91be33988543aeb-1568864268412.jpg)

