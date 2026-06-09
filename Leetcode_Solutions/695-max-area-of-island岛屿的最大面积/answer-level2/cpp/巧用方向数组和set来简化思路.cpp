### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution 
{
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) 
    {
        set<pair<int,int> > s;
        int line=grid.size();
        int row=grid[0].size();
        for(int i=0;i<line;i++)
        {
            for(int j=0;j<row;j++)
            {
                if(grid[i][j]==1)
                {
                    s.insert(make_pair(i,j));
                }
            }
        }
        vector<pair<int,int> > dirs;
        dirs.push_back(make_pair(0,1));
        dirs.push_back(make_pair(1,0));
        dirs.push_back(make_pair(0,-1));
        dirs.push_back(make_pair(-1,0));
        int re=0;
        for(int i=0;i<line;i++)
        {
            for(int j=0;j<row;j++)
            {
                if(s.find(make_pair(i,j))!=s.end())
                {
                    int templength=1;
                    queue<pair<int,int> > tempqu;
                    s.erase(make_pair(i,j));
                    tempqu.push(make_pair(i,j));
                    while(tempqu.size()!=0)
                    {
                        for(int ii=0;ii<dirs.size();ii++)
                        {
                            if(s.find(make_pair(tempqu.front().first+dirs[ii].first,tempqu.front().second+dirs[ii].second))!=s.end())
                            {
                                tempqu.push(make_pair(tempqu.front().first+dirs[ii].first,tempqu.front().second+dirs[ii].second));
                                s.erase(make_pair(tempqu.front().first+dirs[ii].first,tempqu.front().second+dirs[ii].second));
                                templength++;
                            }
                        }
                        // if(tempqu.size()>re)
                        // {
                        //     re=tempqu.size();
                        // }
                        // templength=tempqu.size();
                        tempqu.pop();
                    }
                    if(templength>re)
                    {
                        re=templength;
                    }
                }
            }
        }
        return re;
    }
};
```