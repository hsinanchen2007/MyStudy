没加排序的时候48ms，加了排序后24ms，recursive的curCombine参数改成引用后8ms，一开始没注意值传递了，vector<int>一直在复制，很慢。
```
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> curCombine;
        std::sort(candidates.begin(), candidates.end());
        recursive(candidates, target, 0, curCombine);
        return m_vecRes;
    }

    void recursive(vector<int>& candidates, int target, int startPos, vector<int>&curCombine)
    {
        if (target == 0)
        {
            m_vecRes.push_back(curCombine);
            return;
        }

        for (int i = startPos; i < candidates.size(); ++i)
        {
            int next = target - candidates[i];
            if (next < 0) break;
            curCombine.push_back(candidates[i]);
            recursive(candidates, target - candidates[i], i, curCombine);
            curCombine.pop_back();
        }
    }

    vector<vector<int>> m_vecRes;
};
```
