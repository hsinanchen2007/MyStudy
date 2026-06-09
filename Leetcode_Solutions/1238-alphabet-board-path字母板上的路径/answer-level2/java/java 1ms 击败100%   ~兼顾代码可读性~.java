
![image.png](https://pic.leetcode-cn.com/c40205d4424eeb0e7d414ec9fb30261121aa618c36c969a3cfe3d9d71766b8df-image.png)

# 思路
（1）首先，字母板的字母是按顺序排列的，这个很关键，这样就可以计算每个字母在字母板上位置了，如下：
```java
    int row = (curChar - 'a') / 5;
    int col = (curChar - 'a') % 5;
```
（2）然后，由于z那一行比较特殊，因此对z单独处理。这里为了更大程度的减小重复代码，我把处理左右移动和上下移动的操作单独抽取出来变成一个方法。具体代码如下：

```java
 private int handleRow(StringBuilder sb, int row, int lastRow) {
        // D or U
        if (row != lastRow) {
            int count = Math.abs(row - lastRow);
            while ((count--) > 0) {
                sb.append(row > lastRow ? 'D' : 'U');
            }
        }

        return row;
    }

    private int handleCol(StringBuilder sb, int col, int lastCol) {
        // L or R
        if (col != lastCol) {
            int count = Math.abs(col - lastCol);
            while ((count--) > 0) {
                sb.append(col > lastCol ? 'R' : 'L');
            }
        }

        return col;
    }

    public String alphabetBoardPath(String target) {
        char[][] board = new char[6][5];
        board[0] = "abcde".toCharArray();
        board[1] = "fghij".toCharArray();
        board[2] = "klmno".toCharArray();
        board[3] = "pqrst".toCharArray();
        board[4] = "uvwxy".toCharArray();
        board[5] = "z".toCharArray();

        int len = target.length();
        int lastRow = 0;
        int lastCol = 0;
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < len; i++) {
            char curChar = target.charAt(i);

            int row = (curChar - 'a') / 5;
            int col = (curChar - 'a') % 5;

            if (lastRow == 5) {
                // 上个字符是z，先行后列
                lastRow = handleRow(sb, row, lastRow);
                lastCol = handleCol(sb, col, lastCol);
            } else {
                lastCol = handleCol(sb, col, lastCol);
                lastRow = handleRow(sb, row, lastRow);
            }

            sb.append('!');
        }

        return sb.toString();
    }
```