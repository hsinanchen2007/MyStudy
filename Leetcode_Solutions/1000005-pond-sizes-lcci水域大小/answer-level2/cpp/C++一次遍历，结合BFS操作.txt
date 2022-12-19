### 解题思路
设返回向量res;
遍历一次矩阵；
    每次遇到0后开始向各个方向BFS遍历统计相邻的0的个数，且每访问一次0都把这个0值变为1；把0的个数的值追加到res之后。
这样总体上访问一次矩阵就能找到所有的海拔为0的pool。
最后把res排序输出。

### 代码

```cpp
class Solution {
     vector<std::pair<int,int>> go{{-1,0},{0,-1},{1,0},{0,1},{1,1},{-1,-1},{-1,1},{1,-1}};
public:
    vector<int> pondSizes(vector<vector<int>>& land) {
        vector<int> res;
        //vector<std::queue<std::pair<int,int>>> pool;
        for(int i = 0; i < land.size(); i++){
            for(int j = 0; j < land[0].size() ;j++){
                if(land[i][j] == 0){
                    int pool_size = 0;
                    std::queue<std::pair<int,int>> q;
                    land[i][j] = 1;
                    q.push(make_pair(i,j));
                    while(!q.empty()){                       
                        pair<int,int> now = q.front();
                        q.pop(); pool_size++;
                        for(int k = 0; k < 8; k++){
                            int nx = now.first + go[k].first;
                            int ny = now.second + go[k].second;
                            if(nx>=0 && nx<land.size() && ny>=0 && ny<land[0].size() 
                               && land[nx][ny] == 0){
                                   land[nx][ny] = 1;
                                   q.push(make_pair(nx,ny));
                            }
                        }

                    }
                    if(pool_size > 0)res.push_back(pool_size);
                }
            }
        }
        sort(res.begin(),res.end());
        return res;
    }
};
```