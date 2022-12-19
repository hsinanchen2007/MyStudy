# 相似题目题解
[221.最大正方形](https://leetcode-cn.com/problems/maximal-square/solution/xing-yu-xing-zhi-jian-jin-xing-yu-cao-zuo-zai-ji-s/)
[764.最大加号标志](https://leetcode-cn.com/problems/largest-plus-sign/solution/xing-yu-xing-zhi-jian-jin-xing-yu-cao-zuo-by-gfu/)
[1277. 统计全为 1 的正方形子矩阵](https://leetcode-cn.com/problems/count-square-submatrices-with-all-ones/solution/xing-yu-xing-yu-cao-zuo-by-gfu/)
![微信图片_20191220152636.png](https://pic.leetcode-cn.com/d0ef171b76c192d398e23b5f6759ff2d350066d69bb824c111655d04373c405d-%E5%BE%AE%E4%BF%A1%E5%9B%BE%E7%89%87_20191220152636.png)

# 思路
先选定**首尾2行**，将**首尾2行**之间(包含**首尾2行**)的所有行 进行**与操作** 得到**1行结果**(称为 **结果行**)。
将首尾2行 做 与操作，得到 **首尾结果行**。
在**结果行**中**记录**所有 值为1的**下标**，而利用每对下标，可以构成区间。
判断在**首尾结果行**中的区间内是否都为1，且区间长度 == 正方形高度，则更新结果值。

如：
1 1 1
1 0 1
1 1 1
**首行**选为下标为0的行(1 1 1)，**尾行**选为下标为2的行(1 1 1)。
**首尾结果行**的结果为：
相与：
    1 1 1
    1 1 1
得到：1 1 1。

**结果行**：
1 1 1
1 0 1
1 1 1
得到：1 0 1

**结果行**刚好有2个1，下标分别为0和2，构成**1个区间**。
判断**首尾结果行**在该区间内是否全为1，显然确实都为1，则**区间长度 == 正方形高度**，则**更新结果值**。

```java
class Solution {
    private int global_row, global_col;
    private int[][] global_grid;
    private int res = 0;

    public int largest1BorderedSquare(int[][] grid) {
        global_grid = grid;
        global_row = grid.length;
        global_col = grid[0].length;

        for (int i = 0; i < global_row - res; ++i)
            and_operate(i);

        return res * res;
    }

    private void and_operate(int cur_idx) {
        int[] first_row = global_grid[cur_idx], base = first_row.clone();
        if (res < 1) {
            for (int num : first_row)
                if (num > 0) {
                    res = 1;
                    break;
                }
        }
        int offset = 0;
        for (int i = cur_idx + 1; i < global_row; ++i) {
            ++offset;
            int[] last_row = global_grid[i];
            for (int j = 0; j < global_col; ++j)
                base[j] &= global_grid[i][j];

            //存结果行中符合要求的区间的 左侧下标
            List<Integer> idx_list = new ArrayList<>();
            int count = 0, temp_idx = 0;
            for (; temp_idx < global_col - offset; ++temp_idx) {
                if (base[temp_idx] == 1) {
                    ++count;
                    if (base[temp_idx + offset] == 1)
                        idx_list.add(temp_idx);
                }
            }
            if (count < 2) {
                for (; temp_idx < global_col; ++temp_idx)
                    if (base[temp_idx] == 1 && ++count == 2)
                        break;
                //区间都无法构成(< 2个下标)，直接return
                if (count < 2)
                    return;
            }
            //判断first_row和last_row是否在 结果行中1的下标所构成的区间内 有连续的1
            Loop:
            for (int begin_idx : idx_list) {
                int end_idx = begin_idx + offset;
                for (int l = begin_idx + 1; l < end_idx; ++l)
                    if (first_row[l] < 1 || last_row[l] < 1)
                        continue Loop;

                res = Math.max(res, offset + 1);
            }
        }
    }
}
```
