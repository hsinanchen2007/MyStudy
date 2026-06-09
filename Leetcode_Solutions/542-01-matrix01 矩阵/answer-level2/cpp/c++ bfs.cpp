### 解题思路
建立并初始化1个与输入相同行列的矩阵。用广度优先搜索，两遍遍历搞定。

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
                int m=matrix.size();
        int n=0;
        if(m)n=matrix[0].size();
        queue<vector<int>> q;
        vector<vector<int>> res=matrix;
        //int num=0;
        //初始化矩阵
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(res[i][j]==0)
                {
                    q.push({i,j});
                    //num++;
                }
                else{
                    res[i][j]=-1;
                }
            }
        }
        while(!q.empty())
        {
            vector<int> root;
            root=q.front();
            int x=root[0];
            int y=root[1];
            q.pop();
            if(x+1<m&&res[x+1][y]==-1)
            {
                res[x+1][y]=res[x][y]+1;
                q.push({x+1,y});
            }
            if(x-1>=0&&res[x-1][y]==-1)
            {
                res[x-1][y]=res[x][y]+1;
                q.push({x-1,y});
            }
            if(y+1<n&&res[x][y+1]==-1)
            {
                res[x][y+1]=res[x][y]+1;
                q.push({x,y+1});
            }
            if(y-1>=0&&res[x][y-1]==-1)
            {
                res[x][y-1]=res[x][y]+1;
                q.push({x,y-1});
            }
        }
        return res;
        
    }
};
```