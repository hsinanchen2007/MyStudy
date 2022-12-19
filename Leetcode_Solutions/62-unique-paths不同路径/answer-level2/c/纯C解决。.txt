首先我想吐个槽.....各位大佬们，你们都是神仙嘛？？？速度辣么快？？？8ms的我竟然是垫底了.....击败5%......

大家就稍微看一下我的思路吧，其实我觉得这道题是**easy难度**，确实没啥难点(可能是时间加快是难点...)

直接上状态转移方程：dp[i][j]=dp[i-1][j-1];

我觉得看到这个就基本明了了。通往某一个方格，肯定是从上面或者左边，因为咱们就只能走下或者走右。

边界条件，那么就是第一行和第一列，只能走下或者走右，只有一种方式。

```
int uniquePaths(int m, int n){
    if(m==0||n==0)
    return 0;
    //path[i][j]记录通往元素nums[i][j]的路径数
    int **path=(int **)malloc(sizeof(int *)*n);//一共有n行
    int i,j;
    for(i=0;i<n;i++)
    path[i]=(int *)malloc(sizeof(int)*m);//一共有m列
    //初始化
    for(i=0;i<n;i++)
    path[i][0]=1;
    for(j=0;j<m;j++)
    path[0][j]=1;
    for(i=1;i<n;i++)
        for(j=1;j<m;j++)
        path[i][j]=path[i-1][j]+path[i][j-1];
    return path[n-1][m-1];
}   
```
