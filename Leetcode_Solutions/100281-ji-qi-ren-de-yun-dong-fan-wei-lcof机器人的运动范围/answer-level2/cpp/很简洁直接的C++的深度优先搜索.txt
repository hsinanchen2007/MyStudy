### 解题思路
用矩阵v保存访问过的节点，深度搜索所有节点

### 代码

```cpp
class Solution {
public:
    int s=0;
    int movingCount(int m, int n, int k) {
        vector<vector<int>>v(m,vector<int>(n));
        dfs(0,0,m,n,k,v);
        return s;
    }
    void dfs(int x,int y,int m,int n,int k,vector<vector<int>>& v){
        if(x>=m||y>=n||x<0||y<0||x/10+x%10+y/10+y%10>k||v[x][y]==1)return ;
        s++;
        v[x][y]=1;
        dfs(x+1,y,m,n,k,v);
        dfs(x,y+1,m,n,k,v);
    }
};
```