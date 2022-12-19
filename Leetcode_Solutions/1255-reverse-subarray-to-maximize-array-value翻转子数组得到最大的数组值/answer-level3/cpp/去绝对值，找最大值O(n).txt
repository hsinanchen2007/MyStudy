
$\Delta =|a_r-a_{l-1}|+|a_l-a_{r+1}|-(|a_l-a_{l-1}|+|a_r-a_{r+1}|)$
去掉绝对值符号
$S_1=a_l-a_{l-1}-|a_l-a_{l-1}|-a_{r+1}+a_r-|a_r-a_{r+1}|$
$S_2=-a_l-a_{l-1}-|a_l-a_{l-1}|+a_{r+1}+a_r-|a_r-a_{r+1}|$
$S_3=a_l+a_{l-1}-|a_l-a_{l-1}|-a_{r+1}-a_r-|a_r-a_{r+1}|$
$S_4=-a_l+a_{l-1}-|a_l-a_{l-1}|+a_{r+1}-a_r-|a_r-a_{r+1}|$
$S_i$不就是$(\pm a_l+\pm a_{l-1}-|a_l-a_{l-1}|)$ 4种情况的最大值，每2个加在一起吗？

```
class Solution {
public:
    int maxValueAfterReverse(vector<int>& num) {
        int n=num.size();
        if(n==1)return num[0];
        int sum=0;
        for(int i=1;i<n;i++)sum+=abs(num[i]-num[i-1]);
        int mx=0;
        for(int i=1;i<n-1;i++){
            mx=max(mx,abs(num[i+1]-num[0])-abs(num[i+1]-num[i]));//单独考虑[1,i]翻转
            mx=max(mx,abs(num[n-1]-num[i-1])-abs(num[i]-num[i-1]));//单独考虑[i,n]区间翻转
        }
        int dp[4];for(int i=0;i<4;i++)dp[i]=-1e9;
        for(int i=1;i<n;i++){
            int x=abs(num[i]-num[i-1]);
            dp[0]=max(dp[0],num[i]-num[i-1]-x);
            dp[1]=max(dp[1],-num[i]-num[i-1]-x);
            dp[2]=max(dp[2],num[i]+num[i-1]-x);
            dp[3]=max(dp[3],-num[i]+num[i-1]-x);
        }
        mx=max(mx,max(dp[0]+dp[3],dp[1]+dp[2]));
        return sum+mx;
    }
};
```
