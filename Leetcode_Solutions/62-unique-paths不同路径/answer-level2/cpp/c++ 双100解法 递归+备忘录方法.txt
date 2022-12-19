递归思路:由于每次只能往下或条者往右走，故要求(m,n)这个点有多少条路径可以到达，只需判断(m-1,n)和(m,n-1)有多少点路径可以到达，最后将这两条路径相加就是能到达(m,n)的路径数。
备忘录:保存当前点(a,b)的路径条数，避免重复计算。
```
class Solution {
public:
    int endx ,  endy ;
    int path[105][105];
    int dp(int m , int n ){
       if(m > endx ||  m < 0) return 0;
       if(n > endy ||  n < 0) return 0;
       if(n == 1 &&  m == 1 ) return 1;
       if(path[m][n]) return path[m][n]; 
       path[m][n] = dp(m - 1 , n) + dp(m , n - 1);
       return   path[m][n];
   }
    int uniquePaths(int m, int n) {
        if(m == 0 || n == 0) return 0;
        memset(path , 0 , sizeof(path));
           endx = m ;
           endy = n ;
           return dp(m,n);
    }
};
```
