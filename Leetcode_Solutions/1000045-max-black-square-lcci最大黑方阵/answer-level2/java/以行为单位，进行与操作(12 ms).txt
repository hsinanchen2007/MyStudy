![微信图片_20200224002749.png](https://pic.leetcode-cn.com/50258c398f318f62327a292a6cbbfcbbebf67569c302896107e83905579aa961-%E5%BE%AE%E4%BF%A1%E5%9B%BE%E7%89%87_20200224002749.png)


# 思路
略。毕竟我非主流。
主流是动态规划，想要跑得快用动归吧。
[相关题目题解](https://leetcode-cn.com/problems/largest-1-bordered-square/solution/xing-yu-xing-zhi-jian-yu-cao-zuo-by-gfu/)

# 代码
```java
class Solution {
    private int global_row, global_col;
    private int[][] global_matrix;
    private int[] res = new int[3];

    public int[] findSquare(int[][] matrix) {
        global_matrix = matrix;
        if ((global_row = matrix.length) < 1) return new int[0];
        global_col = matrix[0].length;
        for (int i = 0; i < global_row - res[2]; ++i)
            and_operate(i);

        return res[2] > 0 ? res : new int[0];
    }

    private void and_operate(int cur_idx) {
        int[] first_row = global_matrix[cur_idx], base = first_row.clone();
        if (res[2] < 1)
            for (int i = 0; i < global_col; ++i)
                if (first_row[i] < 1) {
                    res[2] = 1;
                    res[0] = cur_idx;
                    res[1] = i;
                    break;
                }
        int offset = 0;
        for (int i = cur_idx + 1; i < global_row; ++i) {
            ++offset;
            int[] last_row = global_matrix[i];
            for (int j = 0; j < global_col; ++j)
                base[j] |= global_matrix[i][j];

            //存结果行中符合要求的区间的 左侧下标
            List<Integer> idx_list = new ArrayList<>();
            int count = 0, temp_idx = 0;
            for (; temp_idx < global_col - offset; ++temp_idx) {
                if (base[temp_idx] == 0) {
                    ++count;
                    if (base[temp_idx + offset] == 0)
                        idx_list.add(temp_idx);
                }
            }
            if (count < 2) {
                for (; temp_idx < global_col; ++temp_idx)
                    if (base[temp_idx] == 0 && ++count == 2)
                        break;
                //区间都无法构成(< 2个下标)，直接return
                if (count < 2)
                    return;
            }
            //判断first_row和last_row是否在 结果行中0的下标所构成的区间内 有连续的0
            Loop:
            for (int begin_idx : idx_list) {
                int end_idx = begin_idx + offset;
                for (int l = begin_idx + 1; l < end_idx; ++l)
                    if (first_row[l] > 0 || last_row[l] > 0)
                        continue Loop;

                if (res[2] < offset + 1) {
                    res[2] = offset + 1;
                    res[0] = cur_idx;
                    res[1] = begin_idx;
                }
            }
        }
    }
}
```
