### 解题思路
看了其他人的解法,没看明白为何要用二分分治,自己采用暴力法求解.通俗易懂.后面再思考思考其他人解法的巧妙.
时间击败36.71%%,内存击败89.66%
![图片.png](https://pic.leetcode-cn.com/46ea24b90ffedbd7e0a7b247fa0bcf4a64c2d2ce0fd896b40d44dde38b50448a-%E5%9B%BE%E7%89%87.png)


### 代码

```java
/*
 * Copyright (c) 2019
 * @Author:xiaoweixiang
 */


import java.util.Arrays;
import java.util.TreeSet;

public class Solution {
    public int maxSumSubmatrix(int[][] matrix, int target) {
        int row = matrix.length;
        if (row == 0) {
            return 0;
        }
        int col = matrix[0].length;
        if (col == 0) {
            return 0;
        }
        int result = Integer.MIN_VALUE;
        boolean key = col > row ? false : true;
        int m = Math.min(row, col);
        int n = Math.max(row, col);
        TreeSet<Integer> treeSet = new TreeSet<>();
        //一行一行的找
        for (int i = 0; i < m; i++) {
            //找从第i行开始一直到第0行这i+1行的可能组成的矩形长度
            int[] array = new int[n];//这个矩阵为了保存每一列上第j行到第i行的和
            for (int j = i; j >= 0; j--) {
                for (int k = 0; k < n; k++) {
                    if (key) {
                        array[k] += matrix[k][j];
                    } else {
                        array[k] += matrix[j][k];
                    }
                }
                int k = findMaxSubTarget(array, target);
                treeSet.add(k);
            }
        }
        return treeSet.last();
    }

    /**
     * 找到array中的小于等于target的最大连续子序列的和
     *
     * @param array
     * @param target
     * @return
     */
    private int findMaxSubTarget(int[] array, int target) {
        int n = array.length;
        // dp[i]表示以i为结尾的小于等于target的最大值.如果没有则为Integer.MIN_VALUE
        int[] dp = new int[n];
        for (int i = 0; i < dp.length; i++) {
            int k = 0;
            dp[i] = Integer.MIN_VALUE;
            for (int j = i; j >= 0; j--) {
                k += array[j];
                if (k <= target) {
                    dp[i] = Math.max(dp[i], k);
                }
            }
        }
        Arrays.parallelSort(dp);
        return dp[n - 1];
    }


}
```