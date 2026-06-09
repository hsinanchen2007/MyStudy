### 解题思路
参考周赛大佬刀刀的思路，利用三个二维数组(dp,left,top)存储正方形的信息，其中，dp[i][j]表示以(i,j)为右下角顶点的正方形内部的元素和，初始时，正方形长度为1，所以初始时dp数组存储的就是mat数组的对应元素。left数组表示以(i,j)为右下角顶点的正方形最后一行的和，初始时，正方形长度为1，所以left数组存储的就是mat数组的对应元素。top数组表示以(i,j)为右下角顶点的正方形最后一列的和，初始时，正方形长度为1，所以top数组存储的就是mat数组的对应元素。枚举可能的正方形边长，并更新不同边长下以(i,j)为右下角顶点的正方形的元素和。
### 代码

```java
class Solution {
    public int maxSideLength(int[][] mat, int threshold) {
        int m = mat.length;
        int n = mat[0].length;
        int[][] dp = new int[m][n];
        int[][] left = new int[m][n];
        int[][] top = new int[m][n];
        int ans = 0;
        for(int i = 0;i < m;i++){
            for(int j = 0;j < n;j++){
                left[i][j] = mat[i][j];
                top[i][j] = mat[i][j];
                dp[i][j] = mat[i][j];
                //有满足条件的长度为1的正方形
                if(dp[i][j] <= threshold) ans = 1;
            }
        }
        for(int len = 2;len <= Math.min(m,n);len++){
            int[][] ndp = new int[m][n];
            for(int i = 0;i < m;i++){
                for(int j = 0;j < n;j++){
                    if(i + 1 < len || j + 1 < len){
                        //不能构成长度为len正方形时
                        ndp[i][j] = dp[i][j];
                    }else{
                        //能够成长度为len的正方形
                        left[i][j] += mat[i - len + 1][j];
                        top[i][j] += mat[i][j - len + 1];
                        //由于在left数组和top数组里加了两次mat[i][j]的值，所以需要减去一次
                        ndp[i][j] = left[i][j] + top[i][j] + dp[i - 1][j - 1] - mat[i][j];
                        if(ndp[i][j] <= threshold) ans = len;
                    }        
                }
            }
            //如果长度为len的正方形不满足阈值条件或者不能构成长度为len的正方形，那么长度为len + 1的肯定也不满足要求了，所以直接返回
            if(ans != len) return ans;
            for(int i = 0;i < m;i++){
                for(int j = 0;j < n;j++){
                    dp[i][j] = ndp[i][j];
                }
            }
        }
        return ans;
    }
}
```