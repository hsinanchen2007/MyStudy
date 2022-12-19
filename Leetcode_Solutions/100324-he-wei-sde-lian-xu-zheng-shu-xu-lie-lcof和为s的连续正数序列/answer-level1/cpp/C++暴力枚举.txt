### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> findContinuousSequence(int target) {
        for(int i=1; i<=target/2; ++i)
        {
            vector<int> cur;
            dfs(i,cur,target);
        }

        return res;

    }

    void dfs(int start, vector<int>& cur, int cur_sum)
    {
        if(cur_sum==0)
        {
            res.push_back(cur);
            return;
        }

        if(cur_sum<0) return;

        cur.push_back(start);
        dfs(start+1,cur,cur_sum-start);

        return;
    }
};
```