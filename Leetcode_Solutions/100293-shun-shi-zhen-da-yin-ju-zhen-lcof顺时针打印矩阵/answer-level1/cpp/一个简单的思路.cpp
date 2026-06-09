### 解题思路
数组dir模拟四个方向，从题可知顺时针遍历时，方向转换的顺序是固定的 右 下 左 上不断循环 因此方向的变化时可以用 (d+1)%4来模拟
那么方向为什么会转换 只有触碰到边界或者下一个访问的元素是已经访问过的，因此用一个二维数组来标记元素是否访问过。
结束条件设定为访问到所有元素时结束即可。

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> dir={{0,1},{1,0},{0,-1},{-1,0}};
    vector<int> result;
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m=matrix.size();
        if(m==0) return{};
        int n=matrix[0].size();
        vector<vector<int>> vis(m,vector<int>(n,0));
        int d=0;
        dfs(matrix,vis,d,0,0,m,n);
        return result;
    }
    void dfs(vector<vector<int>>& matrix,vector<vector<int>> &vis,int &d,int now_x,int now_y,int m,int n)
    {
        int flag=m*n;
        while(flag)
        {
            result.push_back(matrix[now_x][now_y]);
            vis[now_x][now_y]=1;
            if(now_x+dir[d][0]>=m || now_x+dir[d][0]<0 || now_y+dir[d][1]>=n || now_y+dir[d][1]<0 || vis[now_x+dir[d][0]][now_y+dir[d][1]]==1) d=(d+1)%4;
            now_x +=dir[d][0];
            now_y +=dir[d][1];
            flag--;
        }
    }
};
```