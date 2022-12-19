# 相似题目题解：
[221. 最大正方形](https://leetcode-cn.com/problems/maximal-square/solution/xing-yu-xing-zhi-jian-jin-xing-yu-cao-zuo-zai-ji-s/)
[764.最大加号标志](https://leetcode-cn.com/problems/largest-plus-sign/solution/xing-yu-xing-zhi-jian-jin-xing-yu-cao-zuo-by-gfu/)
[1139. 最大的以 1 为边界的正方形](https://leetcode-cn.com/problems/largest-1-bordered-square/solution/xing-yu-xing-zhi-jian-yu-cao-zuo-by-gfu/)
![微信图片_20191220141010.png](https://pic.leetcode-cn.com/3c7c24ee2b8f798d2b4a6f816e9f7f6fa0d1b788c3bcae74e2863154a34c1c4b-%E5%BE%AE%E4%BF%A1%E5%9B%BE%E7%89%87_20191220141010.png)


# 思路
详情请见[221. 最大正方形](https://leetcode-cn.com/problems/maximal-square/solution/xing-yu-xing-zhi-jian-jin-xing-yu-cao-zuo-zai-ji-s/)
# 代码
```java
class Solution {
    private int[][] global_matrix;
    private int global_row, global_col;
    private int res = 0;

    public int countSquares(int[][] matrix) {
        global_matrix = matrix;
        global_row = matrix.length;
        global_col = matrix[0].length;

        for (int i = 0; i < global_row; ++i)
            and_operate(i);

        return res;
    }

    //每行进行与操作
    private void and_operate(int row) {
        int[] base = global_matrix[row].clone(), next;
        calculate(base, 1);
        for (int i = row + 1; i < global_row; ++i) {
            next = global_matrix[i];
            for (int j = 0; j < global_col; ++j)
                base[j] &= next[j];//直接与，得到1或0
            //若相邻的1的个数 < limit，则没必要继续往下与操作
            if (!calculate(base, i - row + 1))
                return;
        }
    }

    //计算1连续出现的次数
    private boolean calculate(int[] array, int limit) {
        int count = 0;
        boolean found = false;
        for (int j = 0; j < global_col; ++j) {
            if (array[j] == 0) {
                count = 0;
                continue;
            }

            if (++count >= limit) {
                ++res;
                found = true;
            }
        }
        return found;
    }
}
```
