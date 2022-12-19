### 1. 暴力破解（时间超限）
暴力解法很简单：
1. 先遍历得到所有陆地和海洋
2. 对一个海洋求它到所有陆地的距离，其中最小的为当前海洋到最近陆地的距离
3. 求出所有海洋到陆地最近距离中最大的那一个
### 时间/空间复杂度
时间复杂度：O（n2）
空间复杂度：O（n2）
### 代码
```cpp
class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int rows=grid.size(),cols=grid[0].size();
        vector<pair<int,int>> lands;//i,j
        vector<pair<int,int>> ocean;//i,j
        for(int i=0;i<rows;++i){
            for(int j=0;j<cols;++j){
                if(grid[i][j]) lands.push_back(make_pair(i,j));
                else ocean.push_back(make_pair(i,j));
            }
        }
        if(ocean.size()==0 || lands.size()==0) return -1;
        int res=0;
        for(int i=0;i<ocean.size();++i){
            int min_dist=INT_MAX;
            for(int j=0;j<lands.size();++j){
                int dist=abs(ocean[i].first-lands[j].first)+abs(ocean[i].second-lands[j].second);
                min_dist=min(min_dist,dist);
            }
            res=max(res,min_dist);
        }
        return res;
    }
};
```
### 2. 广度优先/海洋开始（时间超限）
思路其实和暴力破解差不多
1. 对于每一块海洋我们使用广度优先遍历求得最近的陆地距离
2. 找到所有海洋到陆地最近距离中最大的那一个
* **注意：**
1. 由于广度优先遍历先天决定了是最近距离，因此广度优先遍历的时候，不用等到队列为空
2. 实际时间复杂度大概再O（n3）到O（n4）左右，比暴力破解还差一些。
### 时间/空间复杂度
时间复杂度：O（n3）到O（n4）左右
空间复杂度：O（n2）
### 代码
```cpp
class Solution {
public:
    int bfs(vector<vector<int>> &grid,int i,int j){
        int rows=grid.size(),cols=grid[0].size();
        queue<pair<int,int>> Q;
        vector<vector<bool>> isVisited(rows,vector<bool>(cols,false));
        Q.push(make_pair(i,j));
        isVisited[i][j]=1;
        vector<int> dx={0,1,-1,0};
        vector<int> dy={1,0,0,-1};
        while(!Q.empty()){
            auto cur=Q.front();Q.pop();
            int ii=cur.first,jj=cur.second;
            for(int k=0;k<4;++k){
                int new_i=ii+dx[k],new_j=jj+dy[k];
                if(new_i>=0&&new_i<rows&&new_j>=0&&new_j<cols&&!isVisited[new_i][new_j]){
                    Q.push(make_pair(new_i,new_j));
                    isVisited[new_i][new_j]=true;
                    if(grid[new_i][new_j]==1) return abs(new_i-i)+abs(new_j-j);
                }
            }
        }
        return -1;
    }
    int maxDistance(vector<vector<int>>& grid) {
        int rows=grid.size(),cols=grid[0].size();
        int res=-1;
        for(int i=0;i<rows;++i){
            for(int j=0;j<cols;++j){
                if(grid[i][j]==0){
                    res=max(res,bfs(grid,i,j));
                }
            }
        }
        return res;
    }
};
```
### 广度优先/陆地开始
采用多源深度优先遍历，每走一步将当前的海洋置为陆地，直到所有的海洋都变成陆地，那么这样所执行的广度优先的循环次数就是海洋区域到所有陆地区域的最远距离。因为最远的那一块到最后一步才会被填满。
* **注意**：
由于最后一批海洋也会被push到队列里面，因此最后的结果应该是循环次数减去1.
### 时间/空间复杂度
时间复杂度：
空间复杂度：
### 代码

```cpp
class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int rows=grid.size(),cols=grid[0].size();
        queue<pair<int,int>> q;//i,j
        int landCount=0;
        int totalCount=rows*cols;
        int res=-1;
        for(int i=0;i<rows;++i){
            for(int j=0;j<cols;++j){
                if(grid[i][j]){
                     q.push(make_pair(i,j));
                     landCount++;
                }
            }
        }
        if(q.empty()) return -1;
        if(q.size()==totalCount) return -1;
        vector<int> dx{0,1,-1,0};
        vector<int> dy{1,0,0,-1};
        int count=0;
        while(!q.empty()){
            for(int c=q.size()-1;c>=0;--c){
                auto cur=q.front();q.pop();
                for(int k=0;k<4;++k){
                    int i=cur.first+dx[k],j=cur.second+dy[k];
                    if(i>=0&&i<rows&&j>=0&&j<cols&&grid[i][j]!=1){
                        q.push(make_pair(i,j));
                        grid[i][j]=1;
                    }
                }
            }
            count++;
        }
        return count-1;
    }
};
```