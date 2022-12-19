### 解题思路

一开始我的思路是暴力硬刚：就是从终点开始回推，由于机器人只能向下和向右走，所以从终点开始回推，终点m[n-1][m-1]的路径数等于其左边的路径数和上边的路径数之和，结果这样做，时间还是超限了。于是想到用一个二维数组sum来保存每个格子的路径数来优化：
新建一个二维数组sum,sum[i][j]表示到m[i][j]的路径数。此路径的初始化是这样的：
i(1~n-1):sum[i][0]皆为1;
j(1~m-1):sum[0][j]皆为1;
这是由于机器人只能向右和下走，所以一到第0行或者第1行时，只有一种情况，就是只朝着一个方向一直走。
然后显然sum[i][j]=sum[i-1][j]+sum[i][j-1];只需按照逆推去递归就可以了。
具体结合代码，代码简单几行，看懂了就都懂了：
### 代码

```java
class Solution {
    private int[][] sum;

    private int bothSum(int row,int col)
    {
        
        if(sum[row][col]!=0)//优化的地方，只要有值就可以返回，不必重复寻找
            return sum[row][col];
        
        int leftsum=bothSum(row,col-1);
        int upsum=bothSum(row-1,col);
        
        sum[row][col]=upsum+leftsum;
        
        return sum[row][col];
    }

    public int uniquePaths(int m, int n) 
    {
        if(n==0)return 0;
        if(m==1||n==1)return 1;
        
        sum=new int[n][m];
        
        for(int i=1;i<n;i++)sum[i][0]=1;
        for(int i=1;i<m;i++)sum[0][i]=1;
        return bothSum(n-1,m-1);
    }
}
```