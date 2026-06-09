### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    void backtracking(vector<vector<int>> &res, vector<int> &temp, vector<int> &candidates, int target, int start)
    {
        if(target < 0)return;
        if(target == 0)
        {
            res.push_back(temp);
        }
        for(int i = start; i < candidates.size(); ++i)
        {
            if(i > start && candidates[i] == candidates[i-1])  //这次取的数和上一个数一样，不取！
                continue;  //防止取相同的数，重要的判断条件！！！
            temp.push_back(candidates[i]);
            backtracking(res, temp, candidates, target-candidates[i], i+1);  //禁止重复，因此从i+1开始取
            temp.pop_back();  //回溯
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        if(candidates.size()==0 || target<=0)return {};
        sort(candidates.begin(), candidates.end());  //排序更方便后面的操作
        vector<vector<int>> res;
        vector<int> temp;
        backtracking(res, temp, candidates, target, 0);  //从0开始
        return res;
    }
};
```