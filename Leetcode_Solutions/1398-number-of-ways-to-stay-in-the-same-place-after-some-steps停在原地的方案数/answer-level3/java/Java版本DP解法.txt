```
class Solution {
    private static int MOD = 1_000_000_007;

    public int numWays(int steps, int arrLen) {
        /**
         s: steps
         l：经过s步，停留的坐标
         p[s][l]: 经过s步，停留在坐标l的总方案数
         arrLen: 数组长度

         动态规划解法三要素：
         1、最优子结构
         指针可以向左、向右、停在原地，所有最后一步可以前面的基础上往这三个方向前进，即子结构为：
         p[s-1][l], p[s-1][l-1] , p[s-1][l+1]   PS: 原地、向右、向左
         2、状态转移方程
         p[s][l] = p[s-1][l] + p[s-1][l-1] + p[s-1][l+1]
         3、边界条件
         p[0][0] = 1;
         p[s][l] = 0 if s < l  

         问题求解：
         p[s][0]
         arrLen


         注意点：
         1、 中间结果数组，注意边界条件p[s][l] = 0 if s < l  ，所以只需要定义int[steps+1][steps+1] 而不需要是int[steps+1][arrLen]，不然会超出内存限制；
         2、 结果是返回模 10^9 + 7 后的结果，p[s][l] = p[s-1][l] + p[s-1][l-1] + p[s-1][l+1]  状态方程是两两相加就要求mod，而不是三个求和之后再求mod，之前结果总有用例不过
         就是因为三个求和之后再求的mod。
         */
        int p[][] = new int[steps+1][steps+1];

        p[0][0] = 1;
        for (int s=1; s<=steps; s++) {
            for (int l=0; l < Math.min(steps+1, arrLen); l++) {                        
                if (s == l) {
                    p[s][l] = 1;
                    break;
                }
                if (s < l) {
                    break;
                }
                p[s][l] = p[s-1][l];
                if (l-1 > -1) {
                    p[s][l] += p[s-1][l-1];
                    p[s][l] %= MOD;
                }
                if (l+1 < arrLen) {
                    p[s][l] += p[s-1][l+1];
                    p[s][l] %= MOD;
                }
            }
        }
        return p[steps][0];
    }
}
```


