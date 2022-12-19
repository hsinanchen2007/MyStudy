### 解题思路
用st数组记录是否已经在一个朋友圈了。循环所有人，若不在任何一个朋友圈中，则执行BFS(),把他的朋友，朋友的朋友...加入到一个朋友圈中。执行一次BFS就加sum++，这样就可以计算出朋友圈数量

### 代码

```cpp
class Solution {
    private:
    bool st[210];
    int sum=0;

public:
    int findCircleNum(vector<vector<int>>& M) 
    {
        for(int i=0;i<M.size();i++)
        {
            if(!st[i])
            {
                st[i]=true;
                bfs(i,M);
                sum++;
            }
        }
        return sum;
    }

    void bfs(int x,vector<vector<int>>& M)
    {
        queue<int> q;
        q.push(x);

        while(!q.empty())
        {
            int t = q.front();
            q.pop();
            for(int i=0;i<M[t].size();i++)
            {
                if(!st[i]&&M[t][i]==1)
                {
                    st[i]=true;
                    q.push(i);
                }
            }
        }
    }
};
```