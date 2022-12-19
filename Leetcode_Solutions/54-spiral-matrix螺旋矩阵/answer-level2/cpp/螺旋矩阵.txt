
从初始点(0,0)开始，按照当前方向dir计算下一个点的坐标，如果下一个点的坐标超出数组范围或者已经被访问过，改变方向（向右走时变为向下走，向下走时变为向左走，向左走时变为向上走，向上走时变为向右走）


```c++ []
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        if(m==0)
            return {};
        int n = matrix[0].size();
        int cnt = 0, nums = m*n;
        int vis[m][n];  // 标志数组
        memset(vis,0,sizeof(vis));
        int dx[4] = {-1,0,1,0}; // X方向数组
        int dy[4] = {0,1,0,-1}; // Y方向数组
        int dir = 1 , x = 0, y =0;
        vector<int> res;
        
        while(cnt < nums){
            res.push_back(matrix[x][y]);
            cnt++;
            vis[x][y] = 1; // vis[x][y]==1 代表已经访问过该点
            /* 如果当前方向走到尽头（超出数组范围或者下一个点已经访问过），改变方向 */
            if(dir==2 && (x+dx[dir]>=m || vis[x+dx[dir]][y]))
                dir = 3;
            if(dir==0 && (x+dx[dir]<0 || vis[x+dx[dir]][y]))
                dir = 1;
            if(dir==1 && (y+dy[dir]>=n || vis[x][y+dy[dir]]))
                dir = 2;
            if(dir==3 && (y+dy[dir]<0 || vis[x][y+dy[dir]]))
                dir = 0;
            /* 计算下一个点的坐标 */
            x += dx[dir]; 
            y += dy[dir];
       }
       return res;
    }
};
```