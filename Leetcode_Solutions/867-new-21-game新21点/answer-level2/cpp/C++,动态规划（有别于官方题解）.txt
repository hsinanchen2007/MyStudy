#### 老实说，官方以及和官方的题解相似的文章没有看懂，主要不理解为什么 f(x)=1/w*(f(x+1)+f(x+2)+...f(x+w));所以我换了一种思路，就是自下往上进行求解。
#### 具体思路：以 n=21,k=17,w=3为例讲解：
#### dp[i]表示的是当总共分数为i时的概率为dp[i],所以最终的解是dp[17]+dp[18]+dp[19]+dp[20]+dp[21],那么dp[21]可以如何求得呢？
#### dp[21]可能是18+3，19+2，20+1转移求得的，所以dp[21]的概率为之前去的18，19，20概率之和乘上1/w(1/w表示的是w个数取得其中一个)，公式就是dp[21]=dp[20]*1/w+dp[19]*1/w+dp[18]*1/w=1/w*(dp[18]+dp[19]+dp[20]);

```
typedef double db;
class Solution {
public:
    double new21Game(int n, int k, int w) {
        if(k==0)return 1;
        if(n==0||k>n)return 0;
        vector<db>dp(n+1,0.0);
        //dp[i]表示的是当总分为i的时候的概率，最终的答案一定是k<=i<=n的所有概率之和，表示的是当取到分数大于k小于n的概率
        db sum=1.0;
        db res=0.0;
        dp[0]=1.0;
        for(int i=1;i<=n;i++){
            dp[i]=1.0*sum/w;
            if(i<k){
                sum+=dp[i];
            }else{
                res+=dp[i];//表示当前选的点是符合要求的，那么将其加入到符合条件的概率当中
            }
            if(i>=w){
                sum-=dp[i-w];//sum表示的是中间只能有w个数据，
            }
        }
        return res;
    }
};
```