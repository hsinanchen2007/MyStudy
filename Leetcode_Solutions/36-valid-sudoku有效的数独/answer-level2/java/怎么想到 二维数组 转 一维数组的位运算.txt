- 暴力解法（代码其他题解可参考，也很好理解）
    - 遍历 81 格
    - 若有值，则再检查 **它的** 行、列、3*3方格是否有重复
    - 此时发现，同一个格子会因为后续格子的判断，而出现重复遍历
    - 思考，是否可以找几个秘书，一边遍历，**秘书们一遍分别记录 "此行/列/3*3方格" 曾经出过谁**
    - 遍历过程中，每个秘书都需要知道两个维度
        - 当前是哪一行/列/3*3方格
        - 当前出现了谁
        - 是否还需要第三个维度记录出现的次数？
            - 当然可以，但没有必要，因为如果重复出现直接 `return false;`
- 二维数组
    - `boolean[][] row = new boolean[9][9]` 表示每一行的每个数字，是否出现过
    - `char` 转数字使用 `c - '0'`
```java
public boolean isValidSudoku(char[][] board) {
    boolean[][] row = new boolean[9][9], col = new boolean[9][9], cube = new boolean[9][9];
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            char c = board[i][j];
            if (c == '.') continue;
            int num = c - '1';

            // row秘书行动
            if (row[i][num]) return false;
            else row[i][num] = true;

            // col秘书
            if (col[j][num]) return false;
            else col[j][num] = true;
            
            // cube秘书
            int ci = (i / 3) * 3 + (j / 3);
            if (cube[ci][num]) return false;
            else cube[ci][num] = true;
        }
    }
    return true;
}
```
- 一维数组位运算
    - 在上述 `boolean[][]` 中，不难发现，二维数组中的值，只有两种情况：是 `true` 与 否 `false`
    - 凡是只有两种情况的，都能考虑 位运算
        - 有的题解使用 `Set` 或 `Map` 是根据情况的 **目的**：需要唯一，来思考的
        - 而位运算是根据情况的 **种数**：两种，来思考的
    - 此时思考，二维数组中第二个维度 "出现了谁" 的 `int[]` 改为 `_ _ _ _ _ _ _ _ _` 九个**下划线**，每个下划线代表原来 `int[]` 数组中的一个 **占了的位置**
    - 九个下划线最终形态如：`100100101`，至于哪边开始是 `1`，那边结束是 `9`，看你心情咯~
        - 一般我们从右边算起（二进制右边为低位，后面做 `<<` 位移运算就方便了）
    - 九个下划线明显是二进制嘛，来吧，直接用 `int` 表示，此时可得 `int[] row = new int[9];`
    - 再进一步，`int` 可以表示 32 个 **下划线** ，只用 9 个有点浪费啊，`short` 来咯
```java
public boolean isValidSudoku(char[][] board) {
    short[] row = new short[9], col = new short[9], cube = new short[9];
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            char c = board[i][j];
            if (c == '.') continue;
            int num = c - '1'; // 原来二维数组第二维度的下标
            // 怎么玩？
        }
    }
    return true;
}
```
- 完善二进制位移代码
    - 九个下划线 `_ _ _ _ _ _ _ _ _` 我们需要直到现在遍历到了 **谁** (原来二维数组中第二维度的下标 `c - '1'`)
        - 遍历到 `1` 则 `_ _ _ _ _ _ _ _ 1`
        - 遍历到 `3` 则 `_ _ _ _ _ _ 1 _ _`
        - 遍历到 `8` 则 `_ 8 _ _ _ _ _ _ _`
    - 直接把 `1` **向左**位移
        - 遍历到 `1`，则 `1 << 0`，得 `_ _ _ _ _ _ _ _ 1`
        - 遍历到 `3` 则 `1 << (3 - 1)`，得 `_ _ _ _ _ _ 1 _ _`
        - 遍历到 `8` 则 `1 << ('8' - '1')`，得 `_ 8 _ _ _ _ _ _ _`
        - 遍历到 `c` 则 `1 << num`
    - 判断某一下划线，反着**向右**位移，看最后一个下划线是不是 `1`，则表示是否出现过
        - `if (((row[i] >> num) & 1) == 1) return false;`
        - 向右移 `(row[i] >> num)`
        - 看最后一个下划线 `((row[i] >> num) & 1)`
    - 没有，则标记占用
        - 原来二维数组的 `row[i][c - '1'] = true;`
        - `row[i] = row[i] | (1 << num);` 逻辑或运算符
        - 简写 `row[i] |= 1 << num;`
```java
public boolean isValidSudoku(char[][] board) {
    short[] row = new short[9], col = new short[9], cube = new short[9];
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            char c = board[i][j];
            if (c == '.') continue;
            int num = c - '1';

            // row秘书行动
            if (((row[i] >> num) & 1) == 1) return false;
            else row[i] |= 1 << num;
            
             // col秘书
            if (((col[j] >> num) & 1) == 1) return false;
            else col[j] |= 1 << num;

            // cube秘书
            int bi = (i / 3) * 3 + (j / 3);
            if (((cube[bi] >> num) & 1) == 1) return false;
            else cube[bi] |= 1 << num;
        }
    }
    return true;
}
```
- *喜欢位运算和棋盘游戏的朋友，一起来 [位运算解华容道](http://blog.lzh.today/klotski-solver/)*