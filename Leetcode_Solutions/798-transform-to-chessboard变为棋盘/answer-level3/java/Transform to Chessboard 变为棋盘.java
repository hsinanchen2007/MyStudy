题目：

An N x N board contains only 0s and 1s. In each move, you can swap any 2 rows with each other, or any 2 columns with each other.

What is the minimum number of moves to transform the board into a "chessboard" - a board where no 0s and no 1s are 4-directionally adjacent? If the task is impossible, return -1.

一个 N x N的 board 仅由 0 和 1 组成 。每次移动，你能任意交换两列或是两行的位置。

输出将这个矩阵变为 “棋盘” 所需的最小移动次数。“棋盘” 是指任意一格的上下左右四个方向的值均与本身不同的矩阵。如果不存在可行的变换，输出 -1。

分析：

这个题目说白了，就是把一个矩阵的行、列都排成1、0间隔的有序数字，下面是分析过程

第一，行有序和列有序是完全独立的，交换两行，可以调节列是否有序，但是一行内数字顺序不会改变，同样，交换两列，可以调节行是否有序，但是一列内数字顺序不会改变。因此可以将行、列的交换分开考虑，计算调节到行有序和调节到列有序需要的最小步骤，相加即可

第二，现在只考虑通过交换列，让每一行都是有序的，以下面这个矩阵为例，排列成行有序是什么样呢，第一行是10011，它后面一行必然是01100，再后面一行必然是10011，这样循环下去，也就是说可以通过交换列变成行有序的board必须要满足的条件是，行只有两种模式，这两种模式正好互补，且两种模式的数量必须相等（board为偶数行）或相差1（board为奇数行）

考虑能不能通过交换行达到列有序的检测方法是一样的，不过在已经检测了行符合要求的情况下，检测列符合要求可以简单一些，如果行只有两种模式，列必然也只有两种模式了，所以列只需要检测模式的数量是否正确


![图片.png](https://pic.leetcode-cn.com/2258db5799fd601bfc37c31c900d3eabcc7f7635741d4492e25f9e66ae250473-%E5%9B%BE%E7%89%87.png)


第三，已经知道了行只有两种相反的模式，分别称为模式0和模式1，最终排列的效果就是模式1模式0模式1……或者模式0模式1模式0，不需要考虑一整行，只要选每行的第一个数字作为代表参与排序就可以了

第四，如何计算交换所需的最小次数，最快排序的方法，就是每次都交换两个放在错误位置上的行，所以只需要统计在错误位置的行有多少个，除以2即可

代码：

```
/**
 * 变为棋盘
 * Transform to Chessboard
 * 
 * @author DongWei
 * @date 2019/5/21
 */
public class Solution {
    public int movesToChessboard(int[][] board) {
        // 检测是否可以变为棋盘
        if (check(board)) {
            // 取出第一行和第一列，检测最小交换次数
            int[] row = board[0];
            int[] col = new int[board.length];
            for (int i = 0; i < board.length; i ++) {
                col[i] = board[i][0];
            }
            return find(row) + find(col);
        } else {
            return -1;
        }
    }

    /**
     * 检测两个数组是否完全相同
     *
     * @param a 待比较数组
     * @param b 待比较数组
     * @return 数组相同返回 true，否则返回 false
     */
    private boolean isSame(int[] a, int[] b) {
        for (int i = 0; i < a.length; i ++) {
            if (a[i] != b[i]) {
                return false;
            }
        }
        return true;
    }

    /**
     * 检测两个数组是否完全相反
     *
     * @param a 待比较数组
     * @param b 待比较数组
     * @return 数组相反返回 true，否则返回 false
     */
    private boolean isOpposite(int[] a, int[] b) {
        for (int i = 0; i < a.length; i ++) {
            if (a[i] + b[i] != 1) {
                return false;
            }
        }
        return true;
    }

    /**
     * 检测board是否可以通过行列交换变成棋盘
     *
     * @param board 棋盘
     * @return 可以变成棋盘返回 true，否则返回 false
     */
    private boolean check(int[][] board) {
        // 检测行是否只有两种模式
        // 以第一行为基准，检测其余所有的行，这些行要么和第一行完全相同，要么和第一行完全相反，否则不可能变换成棋盘
        int[] first = board[0];
        int cntSame = 1;
        int cntOpposite = 0;
        for (int i = 1; i < board.length; i ++) {
            if (isSame(first, board[i])) {
                cntSame ++;
            } else if (isOpposite(first, board[i])){
                cntOpposite ++;
            } else {
                return false;
            }
        }
        // 检测两种模式的数量分布是否正确
        if (cntSame == cntOpposite || cntSame == cntOpposite + 1 || cntSame == cntOpposite - 1) {
            // 行只有两种模式，且分布正确，进行列检测，
            // 行只有两种模式的情况下列必然也只有两种模式，只检测列的两种模式数量分布是否正确，只用第一个数字代表不同的两种模式进行计数
            int cnt0 = 0;
            int cnt1 = 0;
            for (int i : first) {
                if (i == 0) {
                    cnt0 ++;
                } else {
                    cnt1 ++;
                }
            }
            // 检测第一行中 0 和 1 的数量（代表两种模式的数量）是否分布正确
            if (cnt0 == cnt1 || cnt0 == cnt1 + 1 || cnt0 == cnt1 - 1) {
                return true;
            } else {
                return false;
            }
        } else {
            return false;
        }
    }

    /**
     * 检测数据需要最少交换多少次成为有序
     *
     * @param tmp 待检测数组
     * @return 数组达到有序需要的最小交换次数
     */
    private int find(int[] tmp) {
        // 只检测 10101010…… 情况的错位数
        int start = 1;
        int error = 0;
        for (int i : tmp) {
            // 统计有多少错位
            if (i != start) {
                error ++;
            }
            start = 1 - start;
        }

        // 需要交换的次数是错位的一半，因为一次交换可以消除两个错位
        // 排列为有序有两种可能，一种是 10101010……，一种是 01010101……
        // 两种情况下计算的错位数相加等于行数，所以我们只需要计算一种
        if (tmp.length % 2 == 0) {
            // 如果行数是偶数，排列为 10101010…… 或 01010101…… 都是可能的
            // 取两种情况下错位数的最小值
            return Math.min(tmp.length - error, error) >> 1;
        } else {
            // 如果行数是奇数，其实只可能排列成一种情况，这取决于 1 和 0 的数量
            // 1 比较多，必然只可能排成 10101010……，0 比较多，只能排成 01010101……
            // 不可能排列成的那种情况下计算出来的错位数是一个奇数，所以可以通过检测错位数是否为奇数来判断采取哪个情况
            if (error %2 == 0) {
                return error >> 1;
            } else {
                return (tmp.length - error) >> 1;
            }
        }
    }
}

```

这个代码运行时间是2~3ms