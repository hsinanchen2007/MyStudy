### 解题思路
像这种结果要求返回**所有符合要求解的题**十有八九都是要利用到递归，而且解题的思路都大同小异。

如果仔细研究这些题目发现都是一个套路，都是需要**另写一个递归函数**，这里我们新加入三个变量，start记录当前递归到的下标，out为一个解，res保存所有已经得到的解，每次调用新的递归函数时，此时的target都要减去当前数组里的数。

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int> > res;
        vector<int> out;
        sort(candidates.begin(), candidates.end());

        combinationSumDFS(candidates, target, 0, out, res);
        return res;
    }
    void combinationSumDFS(vector<int> &candidates, int target, int start, vector<int> &out, vector<vector<int>> &res) {
        if (target < 0) 
        {
            return;
        }
        else if (target == 0) 
        {
            res.push_back(out);
        }
        else 
        {
            for (int i = start; i < candidates.size(); ++i)
            {
                out.push_back(candidates[i]);
                combinationSumDFS(candidates, target - candidates[i], i, out, res);
                out.pop_back();
            }
        }
    }
};
```