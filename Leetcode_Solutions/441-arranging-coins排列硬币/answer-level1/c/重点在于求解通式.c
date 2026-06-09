前n行最多包含(n * n + n) / 2个硬币。
int arrangeCoins(int n){
   long int i,j,k,left,right,mid;
    left=0;
    right=n/2+1;
    while(left<right)
    {
        mid=left+(right-left+1)/2;
        if(n < ((mid*mid+mid)/2))
        {
            right=mid-1;
        }
        else
        {
            left=mid;
        }
    }
    return left;
 
}  
    //动态规划失败，原因：超出内存限制；
/*   long int i,j,k;
   long int *dp;
    dp=(long int*)malloc(sizeof(long int));
    dp[0]=0;
    for(i=1;n-dp[i-1]>=0;i++)
    {
        dp=(long int*)realloc(dp,(i+1)*sizeof(long int));
        dp[i]=dp[i-1]+i;
    }
    return i-2;
}
*/
