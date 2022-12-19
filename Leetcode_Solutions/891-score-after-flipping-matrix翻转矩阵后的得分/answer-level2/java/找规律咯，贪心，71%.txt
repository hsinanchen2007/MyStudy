```
class Solution {
    public int matrixScore(int[][] A) {
        // 交替转行和列
        // 枚举所有可能吗
        // 还是交替？？
        // 有一定规律，40岔树太多了，而且不知道深度
        // 尽可能多的1也不一定对，1000 》 0111
        // 结果是尽可能把最高位变成1
        // 先遍历行，把最高位都变成1，在遍历列，得到尽可能多的1
        // row, make sure every highest bit is 1
        for(int r = 0; r < A.length; ++ r) {
            if(A[r][0] == 1)
                continue;
            for(int c = 0; c < A[0].length; ++ c) {
                A[r][c] ^= 1;
            }
        }
        int rs = 0;
        // col
        for(int c = 1; c < A[0].length; ++ c) {
            int zc = 0, oc = 0;
            for(int r = 0; r < A.length; ++ r) {
                if(A[r][c] == 0)
                    zc ++;
                else
                    oc ++;
            }
            if(zc > oc) {
                for(int r = 0; r < A.length; ++ r) {
                    A[r][c] ^= 1;
                }
            }
        }
        int t = 1;
        for(int c = A[0].length - 1; c >= 0; -- c) {
            for(int r = 0; r < A.length; ++ r) {
                rs += A[r][c] * t;
            }
            t *= 2;
        }
        return rs;
    }
}
```
