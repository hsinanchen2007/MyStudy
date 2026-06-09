### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int n = A.size();
        if(n < 3) return 0;

        vector<int> dp(n,0);
        int sum = 0;
        for(int i = 2;i<n;++i){
            if(A[i]-A[i-1] == A[i-1]-A[i-2])
                dp[i] = dp[i-1]+1;          
            sum += dp[i];
        }

        return sum;
    }
};
```