### 解题思路
数组包含重复数字。90基础上加上target和判断。

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        set<vector<int>> ansSet;
        vector<vector<int>> results;
        vector<int> res;
        int sum = 0;
        m_candidates = candidates;
        m_target = target;
        sort(m_candidates.begin(), m_candidates.end());
        FindSum(0, sum, ansSet, res, results);

        return results;
    }
private:
    void FindSum(int i , int sum, set<vector<int>>& ansSet, vector<int>& res, vector<vector<int>>& results)
    {
        if (sum > m_target) {
            return ;
        }
        if (i >= m_candidates.size()) {
            if (sum == m_target && ansSet.find(res) == ansSet.end()) {
                results.push_back(res);
                ansSet.insert(res);
            }
            return ;
        }
        sum += m_candidates[i];
        if (sum <= m_target) {
            res.push_back(m_candidates[i]);
            FindSum(i + 1, sum, ansSet, res, results);
            res.pop_back();
        }
        sum -= m_candidates[i];
        FindSum(i + 1, sum, ansSet, res, results);
    }

    int m_target;
    vector<int> m_candidates;
};
```