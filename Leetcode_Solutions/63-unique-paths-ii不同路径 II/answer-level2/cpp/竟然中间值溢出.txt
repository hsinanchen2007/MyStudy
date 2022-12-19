
这个题边界处理相对上一题要麻烦点，拆开分别处理要清晰些。


```
class Solution {
public:
int uniquePathsWithObstacles(vector<vector<int>>& p){
      int m = p.size();
      int n = p[0].size();
      long long  f[m][n];

      if (p[0][0] == 0)
	    f[0][0] = 1;
      else
	    f[0][0] = 0;

      for (int i = 1; i < n; ++i) {
	    if (p[0][i] == 0)
		  f[0][i] = f[0][i-1];
          else
          f[0][i] = 0;
      }

      for (int i = 1; i < m; ++i) {
	    if (p[i][0] == 0)
		  f[i][0] = f[i-1][0];
          else
          f[i][0] = 0;
      }

      
      for (int i = 1; i < m; ++i) {
	    for (int j = 1; j < n; ++j){
		  if (p[i][j] == 0)                
			f[i][j] = f[i-1][j] + f[i][j-1];
        else
            f[i][j] = 0;                  
	    }                  
      }
      return f[m-1][n-1];

}
};

```

结果还不错：
![image.png](https://pic.leetcode-cn.com/aa73347fdb9ed3b1d5c0008bcdaeed8560d53ba370161229017768c5541bec9f-image.png)
