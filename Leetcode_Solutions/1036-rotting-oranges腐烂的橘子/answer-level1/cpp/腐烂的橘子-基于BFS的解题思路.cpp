首先，我们分析题目得知，有两点我们需要注意：
一、腐烂的橘子会将相邻橘子腐烂，即上下左右四个方向上的新鲜橘子会被腐烂；可以理解为数据结构中的迷宫问题，每一次只能移动一步
二、涉及到时间问题，每分钟腐烂的橘子会将相邻新鲜橘子腐烂。

从以上两点，我们可以得出每一分钟腐烂的橘子就是一层父节点，可以理解为父子结点的关系，由上到下。那么我们可以想到BFS思想，进一步可以通过队列的方式求解该问题。即通过先进先出的方式，进行逐层访问，前面一层的橘子先出列，后腐烂的橘子放入队列作为下一层，后压入的后出列，每一层橘子在队列中排在一起。

首先我们先了解一下BFS
BFS：广度优先搜索，就是从起点出发，每次都尝试访问同一层的节点，如果同一层都访问完了，再访问下一层，最后广度优先搜索找到的路径就是从起点开始的最短合法路径.上下左右相邻的新鲜橘子就是该腐烂橘子尝试访问的同一层的节点，路径长度就是新鲜橘子被腐烂的时间。

用队列实现的基本思路：
1.创建队列，找出所有烂橘子
2.将所有烂橘子的坐标添加到队列中
3.循环访问,每次弹出一个橘子，进行上下左右访问，将能够腐烂的橘子入队，循环判定条件为队列不为空

PY代码:
```
class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        row = len(grid);
        col = len(grid[0]);
        queue = [];
        directions = [(-1,0),(1,0),(0,-1),(0,1)];
        time = 0;
        for i in range(row):
            for j in range(col):
                if(grid[i][j] == 2):
                    queue.append((i,j,time));
        while queue:
            i,j,time = queue.pop(0);
            for dx,dy in directions:
                x = i+dx;
                y= j+dy;
                if(0 <= x < row and 0 <= y < col and grid[x][y] == 1):
                    grid[x][y] = 2;
                    queue.append((x,y,time+1));

        for row in grid:
            if 1 in row: return -1
        return time
```


C++代码：
```
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid){ 
        int row = grid.size();
        int col = grid[0].size();
        int dir_x[]={-1,1,0,0};
        int dir_y[]={0,0,-1,1};
        // 记录腐烂橘子数目
        int count = 0; 
        // pair是将2个数据组合成一组数据, pair的实现是一个结构体，主要的两个成员变量是first second 因为是使用struct不是class，所以可以直接使用pair的成员变量。
        queue <pair <int,int>> que;
        
        for(int i =0 ;i<row;i++){
            for(int j =0;j<col;j++)
            {
                 if(grid[i][j] == 2){
                     que.push({i,j});
                     count++;
                 }     
            }
               
        }
        int time =0;
        while(count!=0){
            int n = 0;
            auto p = que.front();
            que.pop();
            count--;
            int x;
            int y;
            for(int i=0;i<4;i++){
                x=p.first+dir_x[i];
                y=p.second+dir_y[i];
                if(x>=0 && x<row &&y>=0 && y< col && grid[x][y]==1){
                    grid[x][y] = 2;
                    que.push({x,y});
                    n++;
                }
            }
            if(count == 0 && n != 0 ){
                count = n;
                time++;
            }
        }
        for(int i =0 ;i<row;i++)
            for(int j =0;j<col;j++)
                if(grid[i][j] == 1)
                    return -1;
        return time;

    }
};
```


PS:
一、C++队列，每次入队插入多个元素的实现
    可以使用pair， pair是将2个数据组合成一个数据， pair的实现是一个结构体，访问pair第一个和第二个数值，可使用成员变量first second。
    eg:   queue <pair <int,int>> que;
    注意入队和出队时的用法,入队在两个变量外面加{}传入push参数，出队使用auto变量获取值。
    入队：que.push({第一个值,第二个值})
    出队：auto p =  que.front();
二、stl容器的vector作为二维数组的用法;
    二维数组（无大小限制）：vector<vector<int>>  Array;
三、重置vector容器大小
    使用resize(传递size)函数