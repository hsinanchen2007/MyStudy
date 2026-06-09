# 相似题目 题解
[764.最大加号标志](https://leetcode-cn.com/problems/largest-plus-sign/solution/xing-yu-xing-zhi-jian-jin-xing-yu-cao-zuo-by-gfu/)
[1139. 最大的以 1 为边界的正方形](https://leetcode-cn.com/problems/largest-1-bordered-square/solution/xing-yu-xing-zhi-jian-yu-cao-zuo-by-gfu/)
[1277. 统计全为 1 的正方形子矩阵](https://leetcode-cn.com/problems/count-square-submatrices-with-all-ones/solution/xing-yu-xing-yu-cao-zuo-by-gfu/)
![TIM图片20191220135413.png](https://pic.leetcode-cn.com/a14f7c17ba0929c982a94d98633960f4f62c3cb41ea8c259223c4e700e419fe7-TIM%E5%9B%BE%E7%89%8720191220135413.png)

# 思路：
假设现有如下的矩阵(共4行)：

第1行：1 0 1 0 0
第2行：1 0 ***1 1*** 1
第3行：1 1 ***1 1*** 1
第4行：1 0 0 1 0

上例中的**最大正方形**出现在**第2行**和**第3行**，很容易想明白的一点是，**最大正方形**的**边长** 即 第2行和第3行的“与”操作后，**相邻的1**。看不明白的话下面的计算可以说明：

“与”操作：
第2行：1 0 ***1 1*** 1
第3行：1 1 ***1 1*** 1
结 果 ：1 0 ***1 1*** 1

或许有人会问，与操作后的结果明明有**3个**相邻的1，为何只算其中**2个**？
答：因为只使用了2行(即**第2行**和**第3行**)进行**与操作**，即正方形的“**高**”为2，此时虽然相邻的1有**3个**，但为了保证它是“正方形”，“宽”最多只能取到2，而不能取3。

又或许有人问：那万一能取到3呢？很简单，只需将第2行和第3行相与的 **结果**，再和**第4行** 相与，此时“**高**”为3，而结果为：

“与”操作：
1 0 1 1 1 (第2行与第3行相与的结果)
1 0 0 1 0 (第 4 行)
1 0 0 1 0 (结 果)

可知，相邻的1的个数仅为1.
# 具体实现：
第1行分别和2~n行相与，第2行分别和3~n行相与，……直到第n-1行和第n行相与。
每次计算 **相邻的1** 的个数时，将limit值设为当前“正方形”的**高**，若存在正方形的**宽** == **高**，则更新res，并返回**true**。
若**不存在**正方形的**宽** == **高**，则返回**false**。

与操作的**最好结果**就是**保持不变**，即**1 0 1** 和 **1 1 1**相与，还是**1 0 1**。
与操作除了**最好结果**以外的**任何结果**，都会使1的个数变少，即**1 0 1**和 **0 1 1**相与，得到**0 0 1**。

既然当前所能找到的正方形的**宽 < 高**，则继续往下进行与操作的**最好结果**也是**保持不变**。
**保持不变**就意味着：若x < 5，则x < 6也肯定成立，所以没必要继续进行**与操作**，直接return即可。
PS: 上述的x指正方形的宽，5指正方形当前的高，6指正方形在下一轮与操作后的高(5 + 1)。

# 代码
'1'的**int值**为49(二进制**110001**)，'0'的**int值**为48(二进制**110000**)，相与结果是和0和1是相似的。
即：'1'与'1'相与得'1'，其余情况结果为'0'。
```java
class Solution {
    private char[][] global_matrix;
    private int global_row, global_col;
    private int res = 0;

    public int maximalSquare(char[][] matrix) {
        global_matrix = matrix;
        if ((global_row = matrix.length) == 0)
            return 0;
        global_col = matrix[0].length;

        for (int i = 0; i < global_row - res; ++i)
            and_operate(i);

        return res * res;
    }

    //每行进行与操作
    private void and_operate(int row) {
        char[] next, base = global_matrix[row].clone();
        if (res < 1)
            calculate(base, 1);
        for (int i = row + 1; i < global_row; ++i) {
            next = global_matrix[i];
            for (int j = 0; j < global_col; ++j)
                base[j] &= next[j];//直接与，得到'1'或'0'(都为'1'则为'1')
            //若相邻的1的个数 < limit，则无需继续进行与操作，直接return
            if (!calculate(base, i - row + 1))
                return;
        }
    }

    //计算1连续出现的次数
    private boolean calculate(char[] array, int limit) {
        int count = 0;
        for (int j = 0; j < global_col; ++j) {
            if (array[j] == '0') {
                count = 0;
                continue;
            }//array[j]为'1'
            if (++count == limit) {
                res = Math.max(res, limit);
                return true;
            }
        }
        return false;
    }
}
```
