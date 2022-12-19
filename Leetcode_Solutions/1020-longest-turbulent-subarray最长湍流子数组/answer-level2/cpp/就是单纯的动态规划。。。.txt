注意：这个dp的含义是以A[i]为结尾(必须包含A[i])的湍流数组长度，不是记录前i个数中(不一定要包含A[i])最大的湍流数组的长度
```
class Solution {
public:
    int maxTurbulenceSize(vector<int>& A) {
        std::ios::sync_with_stdio(false);
        if (A.size() == 0) {
            return 0;
        }
   
        if (A.size() == 1) {
            return 1;
        }

        int ans = 0;
        /*注意：这个dp的含义是以A[i]为结尾(必须包含A[i])的子数组的湍流长度，不是前i个数的子数组中最大的湍流长度*/
        vector<int> dp(A.size(), 0);
        dp[0] = 1;//只有1个数，无论如何都是1
        dp[1] = (A[0] == A[1] ? 1 : 2);//[9,9]这种相等的就是1，否则不等是2
        ans = dp[1];
        for (int i = 2; i < dp.size(); ++i) {
            if ((A[i - 2] < A[i - 1] && A[i - 1] > A[i]) ||
                (A[i - 2] > A[i - 1] && A[i - 1] < A[i])) {
                    dp[i] = dp[i - 1] + 1;//符合湍流条件，+1
            } else {
                /*不符合湍流条件，如果当前数是跟前一个数相等，则只能从当前开始重新计算，长度为1，
                如果不相等则当前数和前一个数已经组成了湍流条件，长度已经有2了*/
                dp[i] = (A[i] == A[i - 1] ? 1 : 2); 
            }

            ans = max(ans, dp[i]);//动态更新最大结果
        }

        return ans;
    }
};
```
