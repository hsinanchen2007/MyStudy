受大佬们的启发，写一个c++版的
就是比较复杂。。。

```
struct Point{
    int x;  //行
    int y;  //列
};

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<Point> queue_Grid;
        int M = grid.size();            //获取行数
        int N = grid[0].size();         //获取列数
        int fresh_num = 0;              //新鲜水果数量

        //第一轮(初始化) 遍历数组
        for(int i = 0; i < M; i++){
            for(int j = 0; j < N; j++){
                if(grid[i][j] == 2)     //检测为腐烂水果，入队
                    queue_Grid.push(Point{i,j});
                else if(grid[i][j] == 1) //检测为新鲜水果，记录数量
                    fresh_num++;
            }
        }

        //1.一轮遍历队列中所有腐烂的水果；
        //2.判断腐烂水果的四个方向，将他们变腐烂
        //3.下一轮待遍历的腐烂水果进队
        //直到某一轮过后无新鲜水果或队列为空(无腐烂水果进队)=》循环结束
        int round = 0;                   //轮数or分钟数
        while(fresh_num > 0 && !queue_Grid.empty()){
            round++;
            int n = queue_Grid.size(); //获取每一轮的队列长度
            for(int i = 0; i < n; i++){
                Point temp = queue_Grid.front();
                queue_Grid.pop();
                int r = temp.x, c = temp.y;   //获取腐烂苹果的位置，行r列c
                if(r - 1 >= 0 && grid[r-1][c] == 1){ //上
                    fresh_num--;
                    grid[r-1][c] = 2;
                    queue_Grid.push(Point{r-1,c});
                }
                if(r + 1 < M && grid[r+1][c] == 1){  //下
                    fresh_num--;
                    grid[r+1][c] = 2;
                    queue_Grid.push(Point{r+1,c});
                }
                if(c - 1 >= 0 && grid[r][c-1] == 1){  //左
                    fresh_num--;
                    grid[r][c-1] = 2;
                    queue_Grid.push(Point{r,c-1});
                }
                if(c + 1 < N && grid[r][c+1] == 1){  //右
                    fresh_num--;
                    grid[r][c+1] = 2;
                    queue_Grid.push(Point{r,c+1});
                }
            }
        }

        if(fresh_num > 0)
            return -1;
        else
            return round;
    }
};
```
