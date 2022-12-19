刚开始做的时候题意理解错了，认为只需要判断字符'9'是否满足数独
然后按照这个逻辑写了代码，提交过后测试用例居然还通过了204个

后来发现原来是要判断所有的字符是否都满足，于是就简单粗暴的在外层套了一个循环，判断所有字符
效率还非常高, 4ms跑完, 排名还是前0.2。

= =太暴力了，代码如下：
```
package com.medium;

/**
 * @author qinzhu
 * @since 2019/10/31
 */
public class 有效的数独 {
    // 解题思路1.0（先从简单的写起，就判断字符'9'是否满足要求）：
        // 第一步，判断行列重复：
            // 使用两个一维数组
            // 遍历一遍数独，遇到9就把它的行数记录在`行数组`中，把它的列记录在`列数组中`
            // 遍历的时候要检查是否在`行数组`或者`列数组`中存在，存在的话那就肯定不合格了
        // 第二步，判断9格子内重复
            // 使用一个大小为3*3的二维数组，用来存储9个区域中是否出现了字符'9'
    // 解题思路2.0
        // 由于解题思路1.0只能判断一个字符是否满足条件
        // 所以再在外层加上循环，判断所有的字符是否满足条件即可

    public static void main(String[] args) {
        char[][] a = {{'8', '3', '.', '.', '7', '.', '.', '.', '.'}, {'6', '.', '.', '1', '9', '5', '.', '.', '.'}, {'.', '9', '8', '.', '.', '.', '.', '6', '.'}, {'8', '.', '.', '.', '6', '.', '.', '.', '3'}, {'4', '.', '.', '8', '.', '3', '.', '.', '1'}, {'7', '.', '.', '.', '2', '.', '.', '.', '6'}, {'.', '6', '.', '.', '.', '.', '2', '8', '.'}, {'.', '.', '.', '4', '1', '9', '.', '.', '5'}, {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};
        有效的数独 o = new 有效的数独();
        System.out.println(o.isValidSudoku(a));
    }

    private boolean[] useRow;
    private boolean[] useCol;
    private boolean[][] useArea;

    public boolean isValidSudoku(char[][] board) {
        for (int i = 0; i < 9; i++) {
            char ch = (char) ('1' + i);
            useRow = new boolean[9];
            useCol = new boolean[9];
            useArea = new boolean[3][3];
            if (judgeSingleChar(board, ch)) {
                return false;
            }
        }
        return true;
    }

    private boolean judgeSingleChar(char[][] board, char c) {
        for (int i = 0; i < board.length; i++) {
            char[] chars = board[i];
            for (int j = 0; j < chars.length; j++) {
                char ch = chars[j];
                if (ch != c) {
                    continue;
                }
                // 判断行列是否重复
                if (useRow[i] || useCol[j]) {
                    return true;
                }
                useRow[i] = true;
                useCol[j] = true;
                // 判断九格内是否重复
                int x = i / 3;
                int y = j / 3;
                if (useArea[x][y]) {
                    return true;
                }
                useArea[x][y] = true;
            }
        }
        return false;
    }

}

```
