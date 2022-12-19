### 解题思路
a[i]<=a[i-1] || b[i]<=b[i-1] 当前列或者前一列必须发生交换
a[i]<=b[i-1] || b[i]<=a[i-1] 前一列发生交换时当前列也必须发生交换
a[i]>a[i-1]&&b[i]>b[i-1] 可以交换也可以不交换

条件状态转移方程：
dp[i][0]=dp[i-1][1] dp[i][1]=dp[i-1][0]+1
dp[i][0]=dp[i-1][0] dp[i][1]=dp[i-1][1]+1
dp[i][0]=min(dp[i-1][0],dp[i-1][1]) dp[i][1]=min(dp[i-1][0],dp[i-1][1])+1
### 代码

```cpp
class Solution {
public:
/*int minSwap(vector<int>& A, vector<int>& B) {
    int dp0 = 0;
    int dp1 = 1;
    
    for(int i = 1; i < A.size(); i++){
        if(A[i - 1] >= A[i] || B[i - 1] >= B[i]){
            int dp = dp0;
            dp0 = dp1;
            dp1 = dp + 1;
        } else if(A[i - 1] >= B[i] || B[i - 1] >= A[i]){
            dp1 = dp1 + 1;
        } else {
            dp0 = min(dp0, dp1);
            dp1 = dp0 + 1;
        }
        
    }
    
    return min(dp0 ,dp1);
}*/

    int minSwap(vector<int>& A, vector<int>& B) {
        // n: natural, s: swapped
        int n1 = 0, s1 = 1;
        for (int i = 1; i < A.size(); ++i) {
            int n2 = INT_MAX, s2 = INT_MAX;
            if (A[i-1] < A[i] && B[i-1] < B[i]) {
                n2 = min(n2, n1);
                s2 = min(s2, s1 + 1);
            }
            if (A[i-1] < B[i] && B[i-1] < A[i]) {
                n2 = min(n2, s1);
                s2 = min(s2, n1 + 1);
            }
            n1 = n2;
            s1 = s2;
        }
        return min(n1, s1);
    }

};
```