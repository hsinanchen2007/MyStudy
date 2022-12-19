### 解题思路

### 代码

```cpp
class Solution 
{
public:
    vector<int> sign;
    int num=0;

    int findCircleNum(vector<vector<int>>& M) 
    {
        sign=vector<int>(M.size(),0);
        
        for(int i=0;i<M.size();i++)
            if(!sign[i]) num++,BFS(M,i);
        
        return num;
    }

    void BFS(vector<vector<int>>& M,int pre)
    {
        queue<int> q;
        sign[pre]=1;
        q.push(pre);

        while(!q.empty())
        {
            pre=q.front();
            q.pop();

            for(int next=0;next<M[pre].size();next++) 
            {
                if(M[pre][next]==1 && !sign[next]) 
                {
                    sign[next]=1;
                    q.push(next);
                }
            }
        }
    }
};
```