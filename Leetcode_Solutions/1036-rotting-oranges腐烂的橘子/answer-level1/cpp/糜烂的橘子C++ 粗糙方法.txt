### 解题思路
一开始写了那么长的代码，觉得有点奇怪，就在想会不会是自己想得复杂了，但最后还是做了出来。
我的做法是属于比较笨的做法，用bad和good2个数组保存烂的和没烂的橘子的坐标。
遍历bad，将烂的上下左右的好的变成烂的，将变成烂的橘子的坐标加入新的数组ne，移出good数组，在grid上变成2；
交换ne和bad，重复上面的操作。
但遍历bad数组后没有产生变化，则退出。
如果good数组不为0，说明还有好的，则返回-1；
否则就返回num
另外我真的觉得这题应该算中等题。

### 代码

```cpp
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        vector<pair<int ,int >> bad;
        vector<pair<int ,int >> good;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j]==2)
                    bad.push_back(make_pair(i,j));
                else if(grid[i][j]==1)
                    good.push_back(make_pair(i,j));
            }
        }
        bool flag;
        int num=0;
        do{
            vector<pair<int ,int >> ne;
            flag=false;
            for(int i=0;i<bad.size();i++)
            {
                if(bad[i].first-1>=0 && grid[bad[i].first-1][bad[i].second]==1)
                {
                    ne.push_back(make_pair(bad[i].first-1,bad[i].second));
                    vector<pair<int ,int >>::iterator it=good.begin();
                    for(int j=0;j<good.size();j++)
                    {
                        if((*it).first==bad[i].first-1 && (*it).second==bad[i].second)
                        {
                            good.erase(it);
                            break;
                        }
                        it++;
                    }
                    grid[bad[i].first-1][bad[i].second]=2;
                    flag=true;
                }
                if(bad[i].first+1<grid.size() && grid[bad[i].first+1][bad[i].second]==1)
                {
                    ne.push_back(make_pair(bad[i].first+1,bad[i].second));
                    vector<pair<int ,int >>::iterator it=good.begin();
                    for(int j=0;j<good.size();j++)
                    {
                        if((*it).first==bad[i].first+1 && (*it).second==bad[i].second)
                        {
                            good.erase(it);
                            break;
                        }
                        it++;
                    }
                    grid[bad[i].first+1][bad[i].second]=2;
                    flag=true;
                }
                if(bad[i].second+1<grid[0].size() && grid[bad[i].first][bad[i].second+1]==1)
                {
                    ne.push_back(make_pair(bad[i].first,bad[i].second+1));
                    vector<pair<int ,int >>::iterator it=good.begin();
                    for(int j=0;j<good.size();j++)
                    {
                        if((*it).first==bad[i].first && (*it).second==bad[i].second+1)
                        {
                            good.erase(it);
                            break;
                        }
                        it++;
                    }
                    grid[bad[i].first][bad[i].second+1]=2;
                    flag=true;
                }
                if(bad[i].second-1>=0 && grid[bad[i].first][bad[i].second-1]==1)
                {
                    ne.push_back(make_pair(bad[i].first,bad[i].second-1));
                    vector<pair<int ,int >>::iterator it=good.begin();
                    for(int j=0;j<good.size();j++)
                    {
                        if((*it).first==bad[i].first && (*it).second==bad[i].second-1)
                        {
                            good.erase(it);
                            break;
                        }
                        it++;
                    }
                    grid[bad[i].first][bad[i].second-1]=2;
                    flag=true;
                }
            }
            bad.swap(ne);
            num++;
        }
        while(flag);
        if(good.size()!=0)
            return -1;
        return num-1;
    }
};
```