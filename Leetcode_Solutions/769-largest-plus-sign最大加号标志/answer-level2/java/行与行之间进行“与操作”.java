# 自己写的相关题目的题解
[221.最大正方形](https://leetcode-cn.com/problems/maximal-square/solution/xing-yu-xing-zhi-jian-jin-xing-yu-cao-zuo-zai-ji-s/)
[1139. 最大的以 1 为边界的正方形](https://leetcode-cn.com/problems/largest-1-bordered-square/solution/xing-yu-xing-zhi-jian-yu-cao-zuo-by-gfu/)
[1277. 统计全为 1 的正方形子矩阵](https://leetcode-cn.com/problems/count-square-submatrices-with-all-ones/solution/xing-yu-xing-yu-cao-zuo-by-gfu/)
# 思路：
选择**奇数数量**(从3开始：3, 5, 7, ……)个连续的行，将所有连续行进行“与操作”，最终得到**1行**结果(称为：**结果行**)。
同时记录**连续行**中的**中间行**，若“与操作”的**结果行**中存在1，则记录**结果行**中为1的下标，并观察此下标在**中间行**中的**左右两边**是否有足够数量的1。

比如：
00000
00100
01110
00100
00000

比如：目前奇数选3，**连续行**选取下标为1, 2, 3的行：
00100
01110
00100

将这3行进行“与操作”，得到**结果行**：00100；而**中间行**为01110。
记录**结果行**中值为1的下标，并观察此下标在**中间行**的**左右两边**是否有足够的1。
显然，**结果行**中1的下标为2，**中间行**中下标为2的1 的两侧各有1个1，满足要求，则更新所能找到的最大加号值。

# 代码：
```java
class Solution {
    private int global_N;
    private int[][] matrix;
    private int res;

    public int orderOfLargestPlusSign(int N, int[][] mines) {
        //若为0的下标数量 < N*N，则至少存在1个1；否则，直接返回0
        if (N * N == mines.length)
            return 0;

        res = 1;
        global_N = N;
        matrix = new int[N][N];
        for (int[] array : matrix)
            Arrays.fill(array, 1);

        for (int[] zero_idx : mines)
            matrix[zero_idx[0]][zero_idx[1]] = 0;

        for (int i = 0; i < N - res; ++i)
            and_operator(i);

        return res;
    }

    private void and_operator(int begin) {
        int[] base = matrix[begin].clone(), mid;
        int offset = 0;
        //奇数 累与
        for (int i = begin + 2; i < global_N; i += 2) {
            ++offset;
            //选取中间行
            mid = matrix[begin + offset];
            //得到 “与操作” 的结果行
            for (int j = 0; j < global_N; ++j)
                base[j] &= matrix[i - 1][j] & matrix[i][j];

            int idx = offset;
            boolean exist_one = false;
            Loop:
            //若结果行中存在1，则记录此1的下标，并观察该下标在中间行的左右两侧是否有足够的1，若有，则更新res
            while (idx + offset < global_N) {
                if (base[idx] == 0) {
                    ++idx;
                    continue;
                }
                exist_one = true;
                //查看中间行的两侧是否有足够的1
                for (int j = idx - offset; j <= idx + offset; ++j) {
                    if (mid[j] == 0) {
                        ++idx;
                        continue Loop;
                    }
                }
                //更新res值
                res = Math.max(offset + 1, res);
                break;
            }
            if (!exist_one)
                return;
        }
    }
}
```
