乍一看是动态规划题目，转移方程是
dp[i] = max(dp[j] * dp[i-j]) j< i 
先不管复杂度，照着这个思路写一遍看看。
1.搜索版本（搜索版本加上map标记的复杂度等同于dp）：
```
class Solution {
public:
    map<int,int> mp;
    int dfs(int n) {
        if(mp.count(n))
            return mp[n];
        int ans=0;
        for(int i=1;i<=n/2;i++){
            mp[i]=dfs(i);
            mp[n-i]=dfs(n-i);
            ans = max(ans,mp[i]*mp[n-i]);
        }
        return ans;
    }
    int cuttingRope(int n) {
        if(n==2||n==3)
            return n-1;
        mp[1]=1;
        mp[2]=2;
        mp[3]=3;
        return dfs(n);
    }
};
```
2.dp版本：
```
class Solution {
public:
    int cuttingRope(int n) {
        if(n==1)
            return 1;
        if(n==2||n==3)
            return n-1;
        vector<int> dp(n+1);
        dp[1]=1;
        dp[2]=2;
        dp[3]=3;
        for(int i=4;i<=n;i++)
            for(int j=1;j<=i/2;j++)
                dp[i] = max(dp[i],dp[j]*dp[i-j]);
        return dp[n];
    }
};
```

3.核能解法：
这一题的数据范围是2,58，我们通过上面的代码输出所有的值，然后放到数组里面，这样就达到了理论上的最优解了。
只要输入58，然后
        for(int i=0;i<=n;i++)
            cout<<dp[i]<<",";
然后
```
class Solution {
public:
    int cuttingRope(int n) {
        int dp[] = {0,1,1,2,4,6,9,12,18,27,36,54,81,108,162,243,324,486,729,972,1458,2187,2916,4374,6561,8748,13122,19683,26244,39366,59049,78732,118098,177147,236196,354294,531441,708588,1062882,1594323,2125764,3188646,4782969,6377292,9565938,14348907,19131876,28697814,43046721,57395628,86093442,129140163,172186884,258280326,387420489,516560652,774840978,1162261467,1549681956};
        return dp[n];
    }
};
```
轻松打败双100%
4.贪心
尽量分解成2和3，原数除3，余数为0就全部分解成3，余数为1就把一个3变成4，余数为2就多分解一个2.
```
class Solution {
public:
    int cuttingRope(int n) {
        if(n<=3)
            return n-1;
        int a = n/3,b=n%3;
        if(b==0)
            return (int)pow(3,a);
        if(b==1)
            return (int)pow(3,a-1)*4;
        return (int)pow(3,a)*2;
    }
};
```