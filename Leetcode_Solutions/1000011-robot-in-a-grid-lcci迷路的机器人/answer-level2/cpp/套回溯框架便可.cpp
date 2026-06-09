### 解题思路
设置一个访问数组，看注释已经很清楚了就不多讲了嘻嘻
### 代码

```cpp
class Solution {
public: //动态规划了
    vector<vector<int>> result;
    bool flag=true; //设置一个标志是否还需遍历
    void  backtrace(vector<vector<int>>& obstacleGrid,int x,int y ,vector<vector<int>>& visited,vector<vector<int>>& buffer)
    {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        if(!flag) return;                   //已经探寻到终点了返回
        if(x>m-1||y>n-1) return ;           //越界返回
        if(obstacleGrid[x][y]==1) return;   //障碍物返回
        if(visited[x][y]==1) return ;       //已经访问过返回。
            visited[x][y]=1;

        if(x==0&&y==0)buffer.push_back({0,0});
        if(x==m-1&&y==n-1)                  //到达终点
        {
           flag=false;
            result=buffer;
            return ;
        }
        //这里写成一个for循环的形式也可以，因为这里只有两个选择 我就直接罗列出来了
        buffer.push_back({x,y+1});   //压入做出的选择             
        backtrace(obstacleGrid,x,y+1,visited,buffer); //向右边
        buffer.pop_back();          //退出时要弹出做过的选择
        buffer.push_back({x+1,y});
        backtrace(obstacleGrid,x+1,y,visited,buffer);  //向下边
        buffer.pop_back();

    }
    vector<vector<int>> pathWithObstacles(vector<vector<int>>& obstacleGrid) {
    int m=obstacleGrid.size();
    int n=obstacleGrid[0].size();
    
    vector<vector<int>> visited(m,vector<int>(n,0));//访问数组
    vector<vector<int>> buffer;                     //缓存数组
    backtrace(obstacleGrid,0,0,visited,buffer);
    return result;
    }
};
```