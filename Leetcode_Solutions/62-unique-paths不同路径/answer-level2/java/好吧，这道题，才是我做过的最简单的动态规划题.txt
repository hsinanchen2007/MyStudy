### 解题思路
![QQ截图20200315211506.png](https://pic.leetcode-cn.com/59546f44f45784299879ff969e99f803beac5a449098a86c7a3a35ff8cb7bf33-QQ%E6%88%AA%E5%9B%BE20200315211506.png)


这还用写动态规划方程？
route_amount[i][j]:从[0][0]到[i][j]的路径总和,是从上边来的路径和从左边来的路径之和
route_amount[i][j]=route_amount[i-1][j]+route_amount[i][j-1]

这题。。。。比64.求最小路径和还简单

对了，空间上是可以优化成O(n)，但是鉴于我耐不住想去打彩6了，就尼给路达油
### 代码

```java
class Solution {
    public int uniquePaths(int m, int n) {
        int [][] route_amount=new int[m][n];
        route_amount[0][0]=1;
        for(int i=0;i<m;i++) route_amount[i][0]=1;//只能从上面来
        for(int i=0;i<n;i++) route_amount[0][i]=1;//只能从左面来
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                route_amount[i][j]=route_amount[i-1][j]+route_amount[i][j-1];
            }
        }
        return route_amount[m-1][n-1];
    }
}
```