### 代码

```cpp
class Solution {
public:
    int longestMountain(vector<int>& A) {
        int n = A.size(), res = 0, top = 0, end = 0;
        if(n == 0) return res;
        vector<int> dp(n, 1);
        for(int i=1; i<n; i++){
            if(A[i] > A[i-1]){
                if(i == n-1) dp[i]=1;
                else if(!top) dp[i] = dp[i-1] + 1;
                else dp[i] = i-end;
            }
            else if(A[i] < A[i-1]){
                end = i-1;
                if(dp[i-1] > 1){
                    dp[i] = dp[i-1] + 1;
                    if(i>1 && A[i-1] > A[i-2]) top = i-1;
                }
                else{
                    dp[i] = 1;
                }
            }
            else end = i-1;
            res = max(res, dp[i]);
        }
        return top ? res : 0;
    }
};
```