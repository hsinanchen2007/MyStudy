方法一 递归
```
class Solution {
public:
    int fib(int N) {
        if(N==0||N==1) return N;
        return fib(N-1)+fib(N-2);
    }
};
```
方法二 备忘录递归
```
class Solution {
public:
    vector<int> a;
    int fib(int N) {
        a=vector<int> (N+1,-1);
        return helper(N);
    }
    int helper(int N){
        if(N==0||N==1) return N;
        if(a[N]!=-1) return a[N];
        a[N]=helper(N-2)+helper(N-1);
        return a[N];
    }
};
```
方法三 动态规划
```
class Solution {
public:
    int fib(int N) {
        if(N==0||N==1) return N;
        int dp[N+1];
        for(int i=0;i<=N;i++){
            if(i==0||i==1) dp[i]=i;
            else dp[i]=dp[i-1]+dp[i-2];
        } 
        return dp[N];
    }
};
```


