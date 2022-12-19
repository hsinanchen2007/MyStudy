### 解题思路
dp 和 回溯

### 代码
回溯
```cpp
class Solution {
public:
    int translateNum(int num) {
        return help(num);
    }
    int help(int num){
        if(num == 0)
            return 1;
        int two = num%100;
        if(two >=10 && two <= 25)
            return help(num/10)+help(num/100);
        else
            return help(num/10);
        
    }
};
```

dp
```cpp
class Solution {
public:
    int translateNum(int num) {
        string s = to_string(num);
        int size = s.size();
        vector<int>dp(size+1,0);         //dp[i]代表 0到i-1间有多少中方法
        dp[0] = 1;
        dp[1] = 1;
        for(int i = 2;i < size+1;i++){
            dp[i] = dp[i-1];
            int n = stoi(s.substr(i-2,2));
            if(n>9 && n < 26)
                dp[i] += dp[i-2];
        }
        return dp[size];
    }
};
```