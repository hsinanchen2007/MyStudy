执行用时 :28 ms, 在所有 java 提交中击败了90.74%的用户
内存消耗 :33.1 MB, 在所有 java 提交中击败了100.00%的用户
```
//把符合条件的情况分为以下几类计算:
//A:以A结尾的
//P0：以P结尾，且含0个A;
//P1：以P结尾，且含1个A;
//L01:以1个L结尾，且含0个A;
//L02:以2个L结尾，且含0个A;
//L11:以1个L结尾，且含1个A;
//L12:以2个L结尾，且含1个A;
class Solution {
    public int checkRecord(int n) {
        int i, A, P0, P1, L01, L02, L11, L12, lastP1;
        final int M = 1000000007;

        A = 1;
        P0 = 1;
        P1 = 0;
        L01 = 1;
        L02 = 0;
        L11 = 0;
        L12 = 0;
        for(i = 1; i < n; i++){
            lastP1 = P1;
            P1 = (((A + lastP1) % M + L11) % M + L12) % M;
            L12 = L11;
            L11 = (A + lastP1) % M;
            A = ((P0 + L01) % M + L02) % M;
            L02 = L01;
            L01 = P0;
            P0 = A;
        }
        return ((((((A + P0) % M + P1) % M + L01) % M + L02) % M + L11) % M + L12) % M;
    }
}
```
时间复杂的O(n),空间复杂度O(1)
