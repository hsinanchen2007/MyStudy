### 解题思路
深搜

### 代码

```cpp
class Solution {
private:
    vector<vector<int>> res;
    vector<int> tmp;

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        generate(candidates, target, 0);

        return res;
    }

    void generate(vector<int>& candidates, int target, int start) {
        int sum = accumulate(tmp.begin(), tmp.end(), 0);
        if (sum == target) {
            res.push_back(tmp);
            return;
        }

        if (sum > target) {
            return;
        }

        for (int i = start; i < candidates.size(); i++) {
            if (i > start && candidates[i] == candidates[i - 1]) {
                continue;
            }
            if (candidates[i] > target - sum) {
                return;
            }
            tmp.push_back(candidates[i]);
            generate(candidates, target, i + 1);
            tmp.pop_back();
        }
    }
};
```