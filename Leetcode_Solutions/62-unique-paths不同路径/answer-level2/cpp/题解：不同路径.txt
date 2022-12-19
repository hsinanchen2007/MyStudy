### 解题思路
使用$a$数组。

将$a_{ij}$表示前$i$行$j$列的方案数。

### 代码

```cpp
#define fs(i,x,y,z) for(int i=x;i<=y;i+=z)
class Solution {
public:
    int uniquePaths(int m, int n) {
        int a[1001][1001];
        a[1][1]=1;
        fs(i,1,n,1){
    	    fs(j,1,m,1){
    	    	if(!a[i][j]) a[i][j]=a[i-1][j]+a[i][j-1];
		    }
	    }
        return a[n][m];
    }
};
```