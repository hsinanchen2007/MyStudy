### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<int> dp;
    int countNumbersWithUniqueDigits(int n) {
        if(n==0)
          return 1;
        if(n==1)
          return 10;
        if(n==2)
          return 91;
        dp.resize(n+1);
        dp[1]=10;
        dp[2]=81;
        int sum=91;
        for(int i=3;i<=n;++i){
            dp[i]=dp[i-1]*(10-i+1);
            sum=sum+dp[i];
        }
        return sum;
    }
};
```