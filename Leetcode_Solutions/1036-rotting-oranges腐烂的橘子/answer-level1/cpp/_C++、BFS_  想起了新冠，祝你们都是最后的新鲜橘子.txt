### 解题思路
1.遍历一遍网格，数一下多少个新鲜橘子，并把腐烂橘子放到队列中
2.用广度优先遍历每一个烂橘子相邻的橘子，如果是新鲜橘子，则腐烂它
3.感染一轮加一次时间，最后一轮没有新鲜橘子可以腐烂了，注意时间不要增加了
4.判断是否还剩下新鲜橘子，输出结果
最后，武汉加油，中国加油！

### 代码

```cpp
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();//行数
        int n = grid[0].size();//列数
        int dir[4][2] = {{0,-1},{-1,0},{0,1},{1,0}};//方向数组，左上右下
        int count_fresh = 0;//新鲜橘子的数量
        queue<pair<int,int>> rotten_orange;//用于存放烂橘子，pair存放坐标
        for(int i = 0;i < m;i++){//遍历网格，记录新鲜橘子数量，将初始的腐烂橘子入队
            for(int j = 0;j < n;j++){
                if(grid[i][j] == 1)
                    count_fresh++;
                else if(grid[i][j] == 2)
                    rot_orange.push({i,j});
            }
        }
        //开始BFS
        int minutes = 0;//记录感染的时间
        while(!rotten_orange.empty() && count_fresh >= 0){
            int num =rotten_orange.size();
            //开始感染
            for(int i = 0;i < num;i++){
                pair<int,int> q = rotten_orange.front();//烂橘子
                rotten_orange.pop();//烂橘子出队
                for(int j = 0;j < 4;j++){//感染四个方向的橘子
                    int x = q.first + dir[j][0];
                    int y = q.second + dir[j][1];
                    if(x >= 0 && y >= 0 && x < m && y < n && grid[x][y] == 1){
                        rotten_orange.push({x,y});//被感染的橘子进队
                        count_fresh--;
                        grid[x][y] = 2;
                    }
                }
            }
            if(!rotten_orange.empty())//最后一次循环没有感染新鲜橘子，时间不需要加
                minutes++;
        }
        if(count_fresh == 0)
            return minutes;
        else
            return -1;
    }
};
```