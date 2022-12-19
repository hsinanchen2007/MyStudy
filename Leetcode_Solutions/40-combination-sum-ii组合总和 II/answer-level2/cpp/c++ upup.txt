### 解题思路
此处撰写解题思路
执行用时 :
0 ms
, 在所有 C++ 提交中击败了
100.00%
的用户
内存消耗 :
9.1 MB
, 在所有 C++ 提交中击败了
63.15%
的用户
### 代码

```cpp
class Solution {
public:
vector<vector<int>> ans;
    void dps(vector<int>& candidates, int target, vector<int>& vec, int idx)
    {
        if (target == 0)
        {
            ans.push_back(vec);
            return;
        }

        for (int i = idx; i<candidates.size(); i++)
        {
            if (i>idx && candidates[i] == candidates[i-1]) continue;
            if (candidates[i] > target) continue;
            
            vec.push_back(candidates[i]);
            dps(candidates, target-candidates[i], vec, i+1);
            vec.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> vec;
        dps(candidates, target, vec, 0);
        return ans;
    }
};
```