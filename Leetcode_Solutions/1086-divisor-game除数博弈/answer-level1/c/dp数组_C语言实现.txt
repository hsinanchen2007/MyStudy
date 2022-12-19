bool divisorGame(int num){
if (num==1)
return false;
if (num==2)
return true;

int dp[1005];
dp[0]=0;//num=1
dp[1]=1;//num=2
int n;
for ( n=2;n<num;n++)
{
    if ((n%2==0&&dp[n-1]==1)||(n%2!=0&&dp[n-1]==1&&dp[n-2]==1))
    dp[n]=0;
    else dp[n]=1;

}
if(dp[n-1]==1)
return true;
else return false;


}