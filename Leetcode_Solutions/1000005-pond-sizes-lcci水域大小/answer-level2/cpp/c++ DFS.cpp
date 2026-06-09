### 解题思路
此处撰写解题思路
咋一看这个题，容易想错，其实这个题可以这么理解。如果你做过dfs求解迷宫问题应该很容易想到这一点.把0当成迷宫中可以走的点，把大于零的数当成迷宫中不能走的点，那么只需要取一个没有遍历过的0当成起点，设置递归结束条件，那么就很容易得到答案。如果我们遍历整个land数组把其中所有的等于零的点都拿出来遍历就能解决问题，但是这样同样有一个问题，就是可能会重复，因此这里我们只需要设置一个全局二维数组来标记避免重复就行了。有不足的地方请指教
### 代码

```cpp
class Solution {
public:
    int dir[8][2]={{-1,0},{1,0},{0,-1},{0,1},{-1,-1},{-1,1},{1,-1},{1,1}};
    //上走，下走，左走，右走
    int size_=0;
    bool In_map(int i,int j,vector<vector<int>>& land)
    {
        return (i<land.size())&&(i>=0)&&(j>=0)&&(j<land[0].size());
    }
    void DFS(vector<vector<int>>& land,int i,int j,vector<vector<int>>& map)
    {
       if(In_map(i,j,land)==false||land[i][j]>0||map[i][j]==1)
       return;
        size_++;
       for(int m=0;m<8;m++)
       {
            map[i][j]=1;
            int col=i+dir[m][0];
            int raw=j+dir[m][1];
            DFS(land,col,raw,map);
       }
    }
    vector<int> pondSizes(vector<vector<int>>& land) {
        vector<vector<int>> map(land.size(),vector<int>(land[0].size(),0));
        vector<int> res;
        for(int i=0;i<land.size();i++)
        {
            for(int j=0;j<land[0].size();j++)
            {
                if(land[i][j]==0&&map[i][j]==0)
                {
                      size_=0;
                       DFS(land,i,j,map);
                       if(size_)
                       {
                        res.push_back(size_);
                       }
                }
            }
        }
        sort(res.begin(),res.end());
        return res;
    }
};
```