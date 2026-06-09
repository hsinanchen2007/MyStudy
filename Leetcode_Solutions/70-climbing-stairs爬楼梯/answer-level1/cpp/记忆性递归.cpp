### 方法1. 解题思路

```cpp
class Solution {
public:
    int climbStairs(int n) {
        f_=vector<int>(n+1,0);
        f_[0]=1;
        f_[1]=1;
        return dp(n);
    }
private:
    vector<int> f_; // 记忆化递归
    int dp(int n){  //动态规划
        if(f_[n]>0) return f_[n];
        else{
            f_[n]=dp(n-1)+dp(n-2);
            return f_[n];
        }
    }
};
```


### 方法二 常量时间

```
class Solution {
public:
    int climbStairs(int n) {
        if(n < 2) return 1;
        int preOne=1;
        int preTwo=1;
        int iCur;
        for(int i=2;i<=n;i++){
            iCur=preOne+preTwo;
            preTwo=preOne;
            preOne=iCur;
        }
        return iCur;
    }
}
```