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
            if(!sign[i]) num++,DFS(M,i);
        
        return num;
    }

    void DFS(vector<vector<int>>& M,int pre)
    {
        sign[pre]=1;
        for(int next=0;next<M[pre].size();next++)
            if(M[pre][next]==1 && !sign[next]) DFS(M,next);
    }
};
```