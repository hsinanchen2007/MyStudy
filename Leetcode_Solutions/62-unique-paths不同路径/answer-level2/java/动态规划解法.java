
![image.png](https://pic.leetcode-cn.com/569aa7e35454ac28b9020eaf1b1f29c8963199f6756f856a1d9e76334cae7e2f-image.png)

代码：

```java
class Solution {
    public int uniquePaths(int m, int n) {
        int[][] mtx =new int[n][m];
        for(int i=0;i<mtx[0].length;i++){
            mtx[0][i]=1;
        }

        for(int i=0;i<mtx.length;i++){
            mtx[i][0]=1;
        }
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                mtx[i][j]=mtx[i][j-1]+mtx[i-1][j];
            }
        }
        return mtx[n-1][m-1];

    }
}
```