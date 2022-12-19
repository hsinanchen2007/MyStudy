一开始我是新建个二维数组来进行存储求解的，效果也还可以，就是代码稍多。后来我想能不能用一维数组来解决，因为官方没有给出这种解法。
其实这种解法和`不同路径 I`中用一维数组的解法大同小异，不同的地方在于需要增加一些对障碍物的判断的代码。

__算法__

1、新建一个长度为列数的一维数组，并赋初始值，第一行的障碍物前的格子都赋值为1；
<br>2、逐行、逐列进行遍历。
<br>3、在进行列的遍历之前，需要对当前行的第一个格子进行判断，如果是障碍物的话，则置为0；
<br>4、进行列遍历时，判断当前格子是否为障碍物，是则置为0，否则再判断上一个格子是否为障碍物，不是的话就`dp[j]+=dp[j-1]`，此时dp[j]的值便是可到达`obstacleGrid[i][j]`的所有不同的路径总数
<br>5、遍历结束之后，`dp[n-1]`便是总的不同的路径数了。

小优化：针对最右下角的格子是障碍物的特殊情况直接返回0；
```
int m=obstacleGrid.length,n=obstacleGrid[0].length;
        
        if(obstacleGrid[m-1][n-1]==1)
            return 0;
        
        int[] dp=new int[n];
        for(int i=0;i<n;i++)
            if(obstacleGrid[0][i]==1)
                break;
            else dp[i]=1;
        
        for(int i=1;i<m;i++){
            dp[0]=obstacleGrid[i][0]==0?dp[0]:0;
            for(int j=1;j<n;j++){
                if(obstacleGrid[i][j]==0){
                dp[j] += obstacleGrid[i][j-1]==1?0:dp[j-1];
                }else dp[j]=0;
            }
        }
        return dp[n-1];
```

时间复杂度：__O(mn)__
<br>空间复杂度：__O(n)__
