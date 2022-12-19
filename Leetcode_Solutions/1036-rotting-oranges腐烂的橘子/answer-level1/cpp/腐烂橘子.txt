### 解题思路
用queue<pair<int,int>>存放烂掉橘子的行和列
注意queue不能遍历。。。

### 代码

```cpp
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        //vector<vector<int>>v;
        queue<pair<int,int>>q;
        for(int i = 0;i < grid.size();i++){             //先找初始时刻的烂橘子
            for(int j = 0;j < grid[0].size();j++){      //把他们放入队列队尾
                if(grid[i][j] == 2)
                  q.push(make_pair(i,j));  
            }
        }
        
        int count = 0;
        while(!q.empty()){                  //队列不为空时，访问队列中的每一个烂橘子
            int size = q.size();            //查看它们的四个方向上是否可以感染
            for(int k = 0;k < size;k++){ 
                auto it = q.front();
                int i = it.first;
                int j = it.second;
                if(i-1>=0&&i-1<grid.size()&&j>=0&&j<grid[0].size()&&grid[i-1][j]==1){
                    grid[i-1][j] = 2;
                    q.push(make_pair(i-1,j));
                }
                if(i+1>=0&&i+1<grid.size()&&j>=0&&j<grid[0].size()&&grid[i+1][j]==1){
                    grid[i+1][j] = 2;
                    q.push(make_pair(i+1,j));
                }
                if(i>=0&&i<grid.size()&&j-1>=0&&j-1<grid[0].size()&&grid[i][j-1]==1){
                    grid[i][j-1] = 2;
                    q.push(make_pair(i,j-1));
                }
                if(i>=0&&i<grid.size()&&j+1>=0&&j+1<grid[0].size()&&grid[i][j+1]==1){
                    grid[i][j+1] = 2;
                    q.push(make_pair(i,j+1));
                }
                q.pop();                    //查看后出队
            }
            if(!q.empty())                  //若队列为空，则没有可以感染的橘子，就不用再计时了
                count++;
        }
        
        for(int i = 0;i < grid.size();i++){ //是否有没感染的橘子
            for(int j = 0;j < grid[0].size();j++){
                if(grid[i][j] == 1)     
                    return -1;
            }
        }
        return count;
        
    }
};
```