### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int climbStairs(int n) {
        if(n==0) return 0;
        if(n==1) return 1;
        if(n==2) return 2;
        // 爬n级可以有多少种方法
        vector<int>dp(n,0);
        dp[0]=1;
        dp[1]=2;
        for(int i=2;i<n;++i) {
            // 爬i级楼梯的方法 = 爬i-1级楼梯的方法 + 爬i-2级楼梯的方法
            dp[i]=dp[i-1]+dp[i-2];
        }
        return dp[n-1];
    }

    // 斐波那契数列
    int climbStairs_1(int n) {
        if (n == 1) return 1;
        else if(n == 2)return 2;
        int result;
        int x,y;
        x = 1; y = 2;
        for (int i = 3; i <= n; i++) {
            result = x + y;
            x = y;
            y = result;
        }
        return result;
    }
};



#include <iostream>
#include <vector>

using namespace std;

int climbStairs(int n) {
    if(n==0) return 0;
    if(n==1) return 1;
    if(n==2) return 2;
    vector<int>dp(n,0);
    dp[0]=1;
    dp[1]=2;
    for(int i=2;i<n;++i) {
        dp[i]=dp[i-1]+dp[i-2];
    }
    return dp[n-1];
}

int main() {
    cout << climbStairs(3) << endl;
}


```