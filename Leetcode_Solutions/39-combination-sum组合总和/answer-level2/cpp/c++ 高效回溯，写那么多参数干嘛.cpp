```
执行用时 :4 ms, 在所有 C++ 提交中击败了97.96%的用户
内存消耗 :7.7 MB, 在所有 C++ 提交中击败了100.00%的用户
```


### 代码

```cpp
class Solution {
public:
    vector<vector<int>>res;
    vector<int>tmp;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        backtrack(candidates,target,0);
        return res;
    }

    void backtrack(vector<int>& candidates, int target,int s)
    {
        if(target<=0)
        {
            if(target==0) res.push_back(tmp);
            return ;
        }

        for(int i=s;i<candidates.size();i++)
        {
            tmp.push_back(candidates[i]);
            backtrack(candidates,target-candidates[i],i);
            tmp.pop_back();
        }
    }
};
```