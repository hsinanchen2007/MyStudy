思路：设dp1[i]是以i为终点的最大递增连续序列的长度，设dp2[i]是以i为起点的最大递减连续序列的长度，那么dp1[i]+dp2[i]-1就是i点的山脉长度，其中dp1[i]、dp2[i]根据题目要求，必须都大于1.
递推条件：
dp1[i+1] = dp1[i] + 1, if A[i] > A[i-1]
dp2[i] = dp1[i+1] + 1, if A[i] > A[i+1]
```
class Solution {
public:
    int longestMountain(vector<int>& A) {
        int size = A.size();
        vector<int> dp1(size, 1);
        vector<int> dp2(size, 1);
        for (int i = 0; i<size; i++) {
            if (i > 0 && A[i] > A[i-1]) {
                dp1[i] = dp1[i-1] + 1;
            }
            if (i > 0 && A[size-i] < A[size-1-i]) {
                dp2[size-1-i] = dp2[size-i] + 1;
            }
        }
        int res = 0;
        for (int i = 0; i<size; i++) {
            if (dp1[i] > 1 && dp2[i] >1) {
                res = max(res, dp1[i] + dp2[i] - 1);
            }
        }
        return res;
    }
};
```