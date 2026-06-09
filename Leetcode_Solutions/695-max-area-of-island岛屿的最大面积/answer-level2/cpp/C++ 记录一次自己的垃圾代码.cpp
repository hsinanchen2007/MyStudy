### 递归

首先放出一份递归解法，很多题解都是这样的，但是这不是我**最初的解法**。

递归的思路也很简单：

**选定一个陆地，作为起点，向四周扩散，而对这个起点则反水，数值变为0；接下来以扩散后的点从新作为起点，再向四周进行扩散，再反水~~~**

代码：
```cpp
class Solution {
private:
    int dfs(vector<vector<int>>&v, int i, int j){
        if(i<0 || j<0 || i>=v.size() || j>=v[0].size() || v[i][j]==0){
            return 0;
        }
        v[i][j] = 0;
        return dfs(v, i-1, j) + dfs(v, i, j-1) + dfs(v, i+1, j) + dfs(v, i, j+1) +1;
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        vector<vector<int>> v(grid);
        int result = 0;
        for(int i=0; i<v.size(); ++i){
            for(int j=0; j<v[0].size(); ++j){
                if(v[i][j]==1){
                    result = max(result, dfs(v,i,j));
                }
            }
        }
        return result;
    }
};
```

### 用栈做深度优先搜索

其实这个才是我最开始提交的代码，用一句话来概括它的思想，就是**不撞南墙绝不回头**。

我提前说明，这份代码效率很低，小妹不耽误各位哥哥的时间~~~

我说一下这个思想，核心就是**维护一个栈【记录走过的路径】**，这里且叫它路径栈吧。

+ 定义四个移动方向，这里的顺序是 ：下->右->上->左（这个不重要）
+ 将grid数组中陆地的横纵坐标压入一个栈`s`，因为每一个陆地都应该被访问到
+ 建立一个数组`isVisitedArray`代表陆地是否被访问过，直接拷贝参数grid即可
+ 从栈`s`中弹出一个坐标，作为路径栈`curMove`的起点；如果这个起点被访问过则跳出本次循迹
+ 上述起点合法时，开始朝着预定的方向移动；**直到边界或者遇到水或者遇到被访问的陆地时**开始变换移动方向，移动的同时需要对访问过的陆地坐标压栈`curMove`
+ 如果有这样一块陆地，上下左右都不运行被访问，则说明走到了岛屿的边界，需要弹出路径栈`curMove`栈顶坐标；将下一个栈顶坐标作为新的起点并重复上述移动过程
+ 直到所有的陆地都被访问过即结束



代码：

```cpp
class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int row = grid.size();
        // 空数组
        if(row == 0) return 0;
        int col = grid[0].size();
        // 建立一个数组代表陆地是否被访问过
        vector<vector<int>> isVisitedArray(grid);
        int maxArea = 0;
        stack< vector<int> > s;
        // 将二维数组中所有陆地的横纵坐标压栈
        for(int i = 0; i<row; ++i){
            for(int j = 0; j<col; ++j){
                if(grid[i][j]) s.push( vector<int>{i,j} );
            }
        }
        // 开始深度优先搜索, 直到当前运行方向的下一格为水
        while(!s.empty()){
            vector<int> point = s.top(); s.pop();
            int x = point[0], y = point[1];
            int curArea = 1;
            if(!isVisitedArray[x][y]) continue;  // 节点访问过, 直接退出
            // 建立当前路径栈
            stack<vector<int>> curMove; curMove.push(point);
            isVisitedArray[x][y] = 0;
            while(!curMove.empty()){
                // 记录该陆地是否是岛屿的边界
                bool isEdge = true;
                for(int i = 0; i<4; ++i){
                    // 朝着一个方向走, 直到边界或者遇到水或者遇到被访问的陆地
                    while(x+dx[i]>=0 && x+dx[i]<row && 
                            y+dy[i]>=0 && y+dy[i]<col && 
                                    grid[x+dx[i]][y+dy[i]] ==1 && 
                                        isVisitedArray[x+dx[i]][y+dy[i]] ==1){
                        x += dx[i]; y += dy[i]; isVisitedArray[x][y] = 0;  // 该陆地已被访问 
                        curArea += 1;
                        curMove.push(vector<int>{x,y});
                        isEdge = false;
                    }
                }
                // 当前陆地上下左右都不能访问
                if(isEdge){
                    curMove.pop();
                    if(!curMove.empty()){
                        x = curMove.top()[0]; y = curMove.top()[1];
                    }
                }
            }
            maxArea = max(maxArea, curArea);
        }
        return maxArea;
    }
private:
    // 四个方向移动, 下->右->上->左
    int dx[4] = {1,0,-1,0};
    int dy[4] = {0,1,0,-1};
};
```