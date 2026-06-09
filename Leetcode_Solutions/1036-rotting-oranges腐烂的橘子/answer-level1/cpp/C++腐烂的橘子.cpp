### 解题思路
用的BFS水过去得，性能稀烂，后续要改进一下

### 代码

```cpp
class Solution {
public:

 struct VectorPred
{
    bool operator()(const vector<int>& lhs, const vector<int>& rhs)
    {
        return *max_element(lhs.begin(), lhs.end()) < *max_element(rhs.begin(), rhs.end());
    }
};

    int orangesRotting(vector<vector<int>>& grid) {

        if(grid.empty() || grid[0].empty() || (grid[0][0]==0 && grid[0].size()==1 && grid.size()==1))
            return 0;

        vector<vector<int>> mask(grid.size(),vector<int>(grid[0].size(),0));
        queue<pair<int,int>> myqueue;

        int result=0,total=0;
        for(int i=0;i<grid.size();i++)
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]==2)
                {
                    myqueue.push(make_pair(i,j));
                    mask[i][j]=1;
                }
                if(grid[i][j]!=0)
                    total++;
            }
        if(myqueue.empty())
            return -1;
        while(!myqueue.empty())
        {
            pair<int,int> P=myqueue.front();
            if(P.first-1>=0 && grid[P.first-1][P.second]==1 && mask[P.first-1][P.second]==0)
            {
                mask[P.first-1][P.second]=mask[P.first][P.second]+1;
                myqueue.push(make_pair(P.first-1,P.second));
                //total--;
            }
            if(P.second-1>=0 && grid[P.first][P.second-1]==1 && mask[P.first][P.second-1]==0)
            {
                mask[P.first][P.second-1]=mask[P.first][P.second]+1;
                myqueue.push(make_pair(P.first,P.second-1));
                //total--;
            }
            if(P.first+1<grid.size() && grid[P.first+1][P.second]==1 && mask[P.first+1][P.second]==0)
            {
                mask[P.first+1][P.second]=mask[P.first][P.second]+1;
                myqueue.push(make_pair(P.first+1,P.second));
                //total--;
            }
            if(P.second+1<grid[0].size() && grid[P.first][P.second+1]==1 && mask[P.first][P.second+1]==0)
            {
                mask[P.first][P.second+1]=mask[P.first][P.second]+1;
                myqueue.push(make_pair(P.first,P.second+1));
                //total--;
            }
            myqueue.pop();
            total--;
        }

        vector<vector<int> >::iterator maxIt = max_element(mask.begin(), mask.end(), VectorPred());
        result = *max_element(maxIt->begin(), maxIt->end());

        if(total==0)
            return result-1;
        else
            return -1;
    }
};
```