![image.png](https://pic.leetcode-cn.com/0f6d878b8caf859bf9aaf6ccd39dafc4452d4b07002a801f3fbdf7431d733aad-image.png)

思路：不妨从（m,n）倒着推，不难得出状态转移方程:a[m][n]=a[m-1][n]+a[m][n-1] =>
   a[i][j]=a[i-1][j]+a[i][j-1];
//**a[i][j]代表从（1，1）到（i,j）有a[i][j]条路径**。
则有如下代码
```
class Solution {
public:
     // int cn=0;
      int  dfs(int x,int y){
          if(x<1||y<1)return 0;//递归边界，返回道路数0；
         if(x==1&&y==1)return 1;//初始默认（1，1）到（1，1）就一条路。
          if(a[x][y])return a[x][y];
           a[x][y]=dfs(x-1,y)+dfs(x,y-1);//状态转移方程
           return a[x][y];
      }
    int uniquePaths(int m, int n) {
           queue<pair<int,int> >q;
           q.push(make_pair(1,1));
        return  dfs(m,n);
         
    }
    
};
```
