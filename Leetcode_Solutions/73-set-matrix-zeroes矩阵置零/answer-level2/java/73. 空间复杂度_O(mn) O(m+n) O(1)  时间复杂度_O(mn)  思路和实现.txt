### 思路一（暴力，空间不达标O(mn)）：
遍历矩阵，记录所有的0元素的行和列。然后对于这些行和列，都置零。
```java []
class Solution {
    class Pos {
        public int x;
        public int y;
        Pos(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }

    // 给定坐标(x, y), 横竖都置零
    private void setVH(int[][] matrix, int x, int y) {
        // y列 置0
        for (int i = 0; i < matrix.length; i++) {
            if (matrix[i][y] != 0) {
                matrix[i][y] = 0;
            }
        }

        // x行 置0
        for (int i = 0; i < matrix[0].length; i++) {
            if (matrix[x][i] != 0) {
                matrix[x][i] = 0;
            }
        }
    }

    public void setZeroes(int[][] matrix) {
        if (matrix == null) {
            return;
        }

        List<Pos> zeros = new ArrayList<>();
        for (int i = 0; i < matrix.length; i++) {
            for (int j = 0; j < matrix[0].length; j++) {
                if (matrix[i][j] == 0) {
                    zeros.add(new Pos(i, j));
                }
            }
        }

        for (int i = 0; i < zeros.size(); i++) {
            Pos p = zeros.get(i);
            setVH(matrix, p.x, p.y);
        }
    }
}
```

### 思路二（空间不达标O(m+n)）
用两个Set分别记录所有0元素的行和列，最后把所有的行和列置成0。

### 思路三（原地 O(1)）
遍历第一次，每遇到一个零，就把其行和列不为0的元素都置成一个矩阵中不存在的数（如-1）。第二遍遍历，把所有的-1变成0.  （方法不适用，题目没有规定范围）

### 思路四（原地 O(1)）
先不看第一行和第一列。遍历剩余所有的元素，如果遇到元素0，就把其第一行和第一列都置成0。遍历第一行和第一列，如果是0就把其对应的一整行（列）置成0。 （但是要在开始单独记录第一行和第一列是否有0，有0就要标记对应的行和列）。若标记过第一行（列），就把其整行（列置成0）。
```java []
class Solution {
    public void setZeroes(int[][] matrix) {
        if (matrix == null || matrix.length == 0 || matrix[0].length == 0) return;
        boolean row = false, column = false;    // 最后是否要把第一行row，第一列column置零
        
        // mark 0
        for (int i = 0; i < matrix.length; i++)
            for (int j = 0; j < matrix[i].length; j++) {
                if (matrix[i][j] == 0) {
                    if (i == 0) row = true;    // 如果是第一行有零，记录最后是否要把行置零
                    if (j == 0) column = true;    // 如果是第一列有零，记录最后需要把列置零
                    matrix[0][j] = matrix[i][0] = 0;    // 其他就把行首和列首置0
                }
            }
                
        // 遍历除第一行，把第一行是0的列全部置0
        for (int j = 1; j < matrix[0].length; j++)
            if (matrix[0][j] == 0)
                setV(matrix, j);

        // 遍历除第一列，把第一列是0的行都置成0
        for (int i = 1; i < matrix.length; i++)
            if (matrix[i][0] == 0)
                setH(matrix, i);

        if (row) setH(matrix, 0);    // 如果第一行需要置0，把第一行置0
        if (column) setV(matrix, 0);    // 如果第一列需要置0，把第一列置0
        
    }


    // 把矩阵第j列都置0
    private void setV(int[][] matrix, int j) {
        for (int i = 0; i < matrix.length; i++) 
            matrix[i][j] = 0;
    }
    
    // 把矩阵第i行都置0
    private void setH(int[][] maxtrix, int i) {
        for (int j = 0; j < maxtrix[i].length; j++)
            maxtrix[i][j] = 0;
    }
}
```



第一次写题解，不懂得可以讨论一下~