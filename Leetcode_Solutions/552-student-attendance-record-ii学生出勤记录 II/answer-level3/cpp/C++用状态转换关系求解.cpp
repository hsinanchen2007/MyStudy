// ### 解题思路
// 1. 状态转换图：
// ![image.png](https://pic.leetcode-cn.com/d335d90c288377628ea51ca01aaa99022858eb43cb72773582377a4979e2016b-image.png)
// 依据状态转换关系得到：
// A = P + L + LL;
// AP = P + AP + AL + ALL;
// AL = A + AP;
// ALL = AL;
// P = P + L + LL;
// L = P;
// LL = L


// ### 代码

// ```cpp
class Solution {
public:
    int checkRecord(int n) {
        /* |  |       |P          |L   |LL 
        *  |A |P+L+LL |A+AP+AL+ALL|A+AP|AL
        *  |!A|0      |P+L+LL     |P   |L
        *  上面是7个状态之间的转换关系
        */
        int K[2][4];
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 4; j++) {
                K[i][j] = 0;
            }
        }
        // n=1时,只有三种情况：A、P、L
        K[0][0] = 1;
        K[1][1] = 1;
        K[1][2] = 1;

        int BASE = 1000000007;

        int BAK[2][4] = {0};
        for (int t = 2; t <= n; t++) {
            BAK[0][3] = K[0][2];
            BAK[0][2] = (K[0][0] + K[0][1]) % BASE;
            BAK[0][1] = ((BAK[0][2] + K[0][2]) % BASE + K[0][3]) % BASE;
            BAK[0][0] = ((K[1][1] + K[1][2]) % BASE + K[1][3]) % BASE;

            BAK[1][0] = 0;
            BAK[1][1] = BAK[0][0];
            BAK[1][2] = K[1][1];
            BAK[1][3] = K[1][2];
            for (int i = 0; i < 2; i++) {
                for (int j = 0; j < 4; j++) {
                    K[i][j] = BAK[i][j];
                }
            }
        }

        int S = 0;
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 4; j++) {
                S = (S + K[i][j]) % BASE;
            }
        }

        return S;
    }
};
// ```


// 2. 题目中说的“两个连续的'L'（迟到）”容易产生误解。
// - 两个-连续的L=》”LL“最多出现两次？即连续迟到两次不能超过两次（😓，有点晕，包含了LLL的情况呢）。用动态规划求解，测试结果比答案大好多。
// - 后来仔细琢磨了下，我以为是：两个连续的-L=》“LL”最多出现一次？即连续迟到两次不能超过一次（这里就不能包含LLL的情况）。用动态规划求解了下，比答案要小。

// 上面两种情况，还蛮有意思的，可以用状态转换和动态规划两种方法解。
// 方程先记在这了：
// 定义F[n,i,j,k]表示最后的考勤记录为k，此时A的次数为i，LL的次数为j。
// `F[n,i,j,A] = F[n-1,i-1,j,P] + F[n-1,i-1,j,L],这里i必然为1；`
// `F[n,i,j,P] = F[n-1,i,j,A](i=1) + F[n-1,i,j,P] + F[n-1,i,j,L];`
// `F[n,i,j,L] = F[n-1,i,j,A](i=1) + F[n-1,i,j,P] + F[n-1,i,j-1,L](j>=1);`