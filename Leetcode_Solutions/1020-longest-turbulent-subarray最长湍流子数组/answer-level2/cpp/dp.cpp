### 解题思路


### 代码

```cpp
class Solution {
public:
    int maxTurbulenceSize(vector<int>& A) {
        if(A.size() <= 1)
            return A.size();
        int dp[A.size()] = {0};
        dp[0] = 1;
        dp[1] = A[0] == A[1] ? 1 : 2;
        int ans = dp[1];
        for(int i = 2 ; i < A.size() ; ++i)
        {   
            if((long long)(A[i] - A[i - 1]) * (A[i - 1] - A[i - 2]) < 0)
                dp[i] = dp[i - 1] + 1;
            else
            {
                if(A[i - 1] != A[i])
                    dp[i] = 2;
                else
                    dp[i] = 1;
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};
```