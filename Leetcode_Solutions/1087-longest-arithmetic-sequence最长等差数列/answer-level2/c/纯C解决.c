根据0 <= A[i] <= 10000，这里两者的差值dif，-10000 <=dif <= 10000

这里创建一个二维数组dp[Asize][20001];其中dp[i][20001]表示记录数组的第i个数与i前面的数之间

差值的数组。其实这里就有些像hash表中的拉链法，只是这里的链条的长度已经固定了。

dp[i][dif]=dp[i][dif]>dp[j][dif]+1?dp[i][dif]:dp[j][dif]+1;这里注重分析。

前j个数如果已经记录了步长为dif，然后长度已经记录下来，由于j>i，这条等式是成立的。或者长度直

接为2；
```


int longestArithSeqLength(int* A, int ASize){
    if(ASize<2)
    return ASize;
    int i,j,max=0,dif; 
    int **dp=(int **)malloc(sizeof(int *)*ASize);
    for(i=0;i<ASize;i++)
    dp[i]=(int *)malloc(sizeof(int)*20001);  
    for(i=0;i<ASize;i++)//初始化
        for(j=0;j<20001;j++)
        dp[i][j]=0;
    for(i=1;i<ASize;i++)
        for(j=0;j<i;j++)
        {
            dif=A[i]-A[j]+10000;//转换为正数
            if(dp[j][dif]>0)
            {
            dp[i][dif]=dp[i][dif]>dp[j][dif]+1?dp[i][dif]:dp[j][dif]+1;
            }
            else{
                dp[i][dif]=2;
            }
            if(dp[i][dif]>max)
            max=dp[i][dif];
        }
    return max;
}


```
