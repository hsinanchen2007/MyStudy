### 解题思路

### 代码

```cpp
class Solution 
{
public:
    vector<vector<int>> m;
    vector<bool> sign;

    bool findWhetherExistsPath(int n, vector<vector<int>>& G, int start, int target) 
    {
        sign=vector<bool>(n,false);
        m=vector<vector<int>>(n);
        for(auto e:G) m[e[0]].push_back(e[1]); 
        BFS(start);
        return sign[target];
    }

    void BFS(int start)
    {
        queue<int> q;
        q.push(start);

        while(!q.empty())
        {
            int pre=q.front();
            q.pop();
            sign[pre]=true;

            for(int next:m[pre]) 
                if(!sign[next]) q.push(next);
        }
    }
};
```