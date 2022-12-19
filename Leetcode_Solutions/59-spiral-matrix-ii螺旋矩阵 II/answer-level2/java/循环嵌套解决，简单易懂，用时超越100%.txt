首先做n/2次循环，每次循环里对矩阵的四个边各遍历填充一次；选择n/2是因为当n为偶数时刚好遍历完，当n为奇数时，矩阵最中心的那个值直接在循环结束后加上去，这样比较简单而且容易理解。

大循环里面四个小循环，就是对矩阵的每条边进行遍历填充值，注意，每一行的最后一个值不填充而是把它当作下一次小循环的第一个值来填充，这样比较有规律。直接上代码

![image.png](https://pic.leetcode-cn.com/9915adb18dfd2810085b6ca05b800da9817ccb9f1aa87a53630fb774f6f88bae-image.png)


```
class Solution {
    public int[][] generateMatrix(int n) {
        int[][] res=new int[n][n];
        int v=1;
        for(int i=0;i<n/2;i++){
            for(int j=i;j<n-1-i;j++){
                res[i][j]=v++;
            }
            for(int j=i;j<n-1-i;j++){
                res[j][n-1-i]=v++;
            }
            for(int j=n-1-i;j>i;j--){
                res[n-1-i][j]=v++;
            }
            for(int j=n-1-i;j>i;j--){
                res[j][i]=v++;
            }
        }
        if(n%2==1)res[n/2][n/2]=n*n;
        return res;
    }
}
```
