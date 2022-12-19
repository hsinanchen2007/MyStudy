 我的思路：
1. 遍历grid，遇到1，就计算它所在岛屿面积：
2. 把它的(x,y)下标对儿进队列，
3. 对队头寻找其四个正方向上的1，把是1的土地进队，进队的下标对应grid置0，防止重复访问。
4. 然后队头出队，每出队一个，计算的面积就+1。
5. 循环操作3，4直到队列空，比较当前最大面积和本岛屿面积，大的那个赋值给我们全局变量
6. 然后继续1.的遍历直到over

我这个方法是BFS？感觉看了其他人的题解，我有点迷糊了。。欢迎指正，谢谢。

  ——————————————————————————————————————————
- DFS：对1的土地，找他的四个正方向上的1，总面积+1。
       然后对这个新的土地重复刚刚的操作，即：递归调用此函数，也就是说从一个方向从起始点的邻居向外走到头，再去换个方向继续找
       然后maxArea = max(area,maxArea)
——————————————————————————————————————————
- BFS：我的应该是属于广度优先，把四个正方向的土地 是1的就进队列，
       然后逐个再去找它们的四个方向，一层层向外铺开，在出队列时统计面积，即：进过队列的元素总个数
——————————————————————————————————————————

```
class Solution {
private: int maxArea = 0; // 全局变量记录最大面积
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int lines = (int)grid.size();
        int columns =(int)grid[0].size();
        for( int l = 0; l < lines; l++ ){ // 逐行
            for( int c = 0; c < columns; c++ ){ // 遍历该行                
                if( grid[l][c] == 1 ){ // 当遇到1，计算面积，然后同一行继续遍历
                    maxAreaTemp(grid, l, c, lines, columns);  
                }
            }
        }
        return maxArea;
    }
    
    // 计算岛屿面积，更新全局变量maxArea；
    void maxAreaTemp(vector<vector<int>>& grid, int x0, int y0, int xtotal, int ytotal){
        int x[] = {0,0,-1,1}; // 上下左右四个方向
        int y[] = {1,-1,0,0};
        queue<pair<int,int>> isl;
        pair<int,int> nowpos(x0,y0); // 从x0,y0开始寻找同一片岛屿
        isl.push(nowpos); // 进队列，并将它置0，防止重复
        grid[x0][y0] = 0;
        int area = 0;
        while( !isl.empty() ){
            for( int i=0; i<4; i++ ){ // 以当前点为基准判断四个方向
                int xtemp = isl.front().first + x[i];
                int ytemp = isl.front().second + y[i];
                if( xtemp>=0 && xtemp<xtotal && ytemp>=0 && ytemp<ytotal && grid[xtemp][ytemp] ){ // 非零且不越界
                    pair<int,int> topush(xtemp,ytemp);
                    isl.push(topush);                    
                    grid[xtemp][ytemp] = 0; // 将遍历过的元素清零，防止重复计算
                }
            }
            area++; // 记录本岛屿面积
            isl.pop();
        }
        maxArea = (maxArea > area) ? maxArea : area; // 更新最大面积
    }
};
```
