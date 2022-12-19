求最少反转次数，实质是求最短路径，可使用广度优先搜索。目标状态是全零矩阵，如果从初始状态开始能够达到全零矩阵的目标状态，则返回全零矩阵对应的反转次数，否则返回`-1`。
从初始状态开始搜索，每步搜索，对当前状态的每个单元格分别进行反转操作（该单元格的值反转以及该单元格的所有相邻单元格的值反转），判断反转操作后的矩阵是否已经被搜索过，如果已经被搜索过则跳过，如果没有被搜索过则更新反转操作后的矩阵的状态和反转次数。搜索停止的条件有两个：一是达到全零矩阵的状态，返回全零矩阵对应的反转次数；二是所有状态都搜索过但是未达到全零矩阵的状态，说明不可能通过反转操作达到全零矩阵，返回`-1`。
```
class Solution {
    public int minFlips(int[][] mat) {
        int rows = mat.length, columns = mat[0].length;
        int[][] zeroMatrix = new int[rows][columns];
        String zeroMatrixStr = matrixToString(zeroMatrix);
        final int WHITE = 0;
        final int GRAY = 1;
        final int BLACK = 2;
        Map<String, Integer> colorMap = new HashMap<String, Integer>();
        Queue<int[][]> queue = new LinkedList<int[][]>();
        queue.offer(mat);
        Queue<Integer> flipsQueue = new LinkedList<Integer>();
        flipsQueue.offer(0);
        String matStr = matrixToString(mat);
        colorMap.put(matStr, GRAY);
        while (!queue.isEmpty()) {
            int[][] curMatrix = queue.poll();
            int flip = flipsQueue.poll();
            String curStr = matrixToString(curMatrix);
            if (zeroMatrixStr.equals(curStr))
                return flip;
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < columns; j++) {
                    int[][] flipMatrix = flip(curMatrix, i, j);
                    String flipStr = matrixToString(flipMatrix);
                    int color = colorMap.getOrDefault(flipStr, WHITE);
                    if (color == WHITE) {
                        queue.offer(flipMatrix);
                        flipsQueue.offer(flip + 1);
                        colorMap.put(flipStr, GRAY);
                    }
                }
            }
            colorMap.put(curStr, BLACK);
        }
        return -1;
    }

    public String matrixToString(int[][] mat) {
        String str = "[";
        int rows = mat.length;
        for (int i = 0; i < rows; i++) {
            int[] row = mat[i];
            String rowStr = Arrays.toString(row);
            if (i > 0)
                str += ", ";
            str += rowStr;
        }
        str += "]";
        return str;
    }

    public int[][] flip(int[][] mat, int row, int column) {
        int rows = mat.length, columns = mat[0].length;
        int[][] flipMat = new int[rows][columns];
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++)
                flipMat[i][j] = mat[i][j];
        }
        flipMat[row][column] = 1 - flipMat[row][column];
        if (row > 0)
            flipMat[row - 1][column] = 1 - flipMat[row - 1][column];
        if (row < rows - 1)
            flipMat[row + 1][column] = 1 - flipMat[row + 1][column];
        if (column > 0)
            flipMat[row][column - 1] = 1 - flipMat[row][column - 1];
        if (column < columns - 1)
            flipMat[row][column + 1] = 1 - flipMat[row][column + 1];
        return flipMat;
    }
}
```

