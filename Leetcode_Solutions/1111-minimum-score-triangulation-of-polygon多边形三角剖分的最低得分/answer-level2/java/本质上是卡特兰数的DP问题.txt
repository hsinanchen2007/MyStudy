### 解题思路
![QQ截图20200323170028.png](https://pic.leetcode-cn.com/5f3603cdb69ab82554f2e85c05c2ce9021148736f86c86eaa0eb3453c802372a-QQ%E6%88%AA%E5%9B%BE20200323170028.png)

*本质上是矩阵连乘积问题，A[i-1],A[i]即矩阵A的行数和列数,建议和矩阵连乘积问题放一起体会同一个数学问题下的不同应用场景*


(n+1)多边形用顶点集{v0,v1...vn}表示
m[i][j]表示多边形{vi-1,vi...vj}的最优解，
每一个多边形{vi-1,vi...vj}(j-(i-1)>=2),都可以划分成三部分：1.子多边形{vi-1,...vk};2.三角形{vi-1,vk,vj};3.子多边形{vk+1,...vj}，其中i<=k<=j-1;

最优子结构性质：若原多边形是最优划分，则1，3两个子多边形也必定是最优划分，而三角形的得分即三顶点之积

在已知两个子多边形的最优解的情况下，只需要找一个k(i<=k<=j-1),使得原多边形的三部分之和最优即为m[i][j]

原问题是求m[1][n]

动态规划方程：
m[i][j]={
0,if i==j(注：此时相当于定点对{vi-1,vj},是一条边，不满足最少三个顶点才能相乘的条件);
min(m[i][k]+m[k+1][j]+A[i-1]*A[k]*A[j]),if i<j(注：其中i<=k<=j-1)
}

填dp表的时候是沿着每一条从左上到右下的对角线，从最长那一条的填到最短的那一条，即m[1][n]
### 代码

```java
class Solution {
    public int minScoreTriangulation(int[] A) {
        int n=A.length-1;//(n+1)边形
        int [][] m=new int[n+1][n+1];//从下标1处开始使用，1...n
        for(int i=1;i<=n;i++) m[i][i]=0;

        for(int r=2;r<=n;r++){
            
            for(int i=1;i<=n-r+1;i++){
                int j=i+r-1;
                m[i][j]=m[i][i]+m[i+1][j]+A[i-1]*A[i]*A[j];
                for(int k=i+1;k<=j-1;k++){
                    if(m[i][k]+m[k+1][j]+A[i-1]*A[k]*A[j]<m[i][j]) m[i][j]=m[i][k]+m[k+1][j]+A[i-1]*A[k]*A[j];
                }
            }
        }
        return m[1][n];

    }
}
```