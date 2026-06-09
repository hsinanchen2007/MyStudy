### 解题思路
看了几个优秀题解后自己默写出来的。
加了好多注释，为了让自己以后也能看懂，希望对大家有帮助。
### 代码

```cpp
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int minute = 0;
        int fresh = 0;
        int row = grid.size();//矩阵行数
        int col = grid[0].size();//矩阵列数
        queue<pair<int,int>> Q;
        int dirx[] = {-1,0,1,0};
        int diry[] = {0,-1,0,1};//用于辅助计算4个正方向

        for(int i = 0;i<row;i++){//遍历整个矩阵
            for(int j = 0;j<col;j++){
                if(grid[i][j] == 2)
                    Q.push(make_pair(i,j));//橘子腐烂，入队列
                if(grid[i][j] == 1)
                    fresh++;//计新鲜橘子数
            }    
        }

        while(!Q.empty()){//队列不空，进循环
            int len = Q.size();//当前队列中的腐烂橘子数   
            int rot = 0;        
            for(int n=0; n<len; n++){
                pair<int,int> x = Q.front();//取队首
                Q.pop();//出队列
                for(int m=0; m<4; m++){//在四个方向上的传染
                    int newx = x.first + dirx[m];
                    int newy = x.second + diry[m];
                    if(newx>=0 && newx<row && newy>=0 && newy<col && grid[newx][newy] == 1)
                    {//去掉边界情况,符合被腐烂的一切客观条件时
                        grid[newx][newy] = 2;//标记为腐烂
                        Q.push(make_pair(newx,newy));//新的腐烂的要入队列
                        fresh--;//新鲜橘子减少一个
                        rot = 1;//如果有新被腐烂的，则rot置1，表示这一轮传染有效，时间应加1
                    }
                }               
            }
            if(rot)
                minute++;
        }
        if(fresh)
            return -1;
        return minute;
    }
};
```