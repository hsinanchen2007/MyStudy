// ### 解题思路
// 逆流思维很秀(我也是看了别人的评论😁)，很优秀，长见识了！！
// 思路:
// 用两个数组来表示，大西洋或太平洋流过的足迹。如果这两个足迹👣数组在某一个位置有重叠，说明太平洋的水可以流到该点，大西洋的水也可以流到该点，那么反过来，这个点上如果有水就可以到达太平洋或着大西洋。就是这个思想。计算这个足迹数组时，计算的条件是水往高处流。😋
// 注意：
// 思路还是深度遍历，遍历四个方向，注意一点，还需要一个数组来表示该点是否遍历过，不然会无线递归下去的。

// ### 代码

// ```java
class Solution {
    public List<List<Integer>> pacificAtlantic(int[][] matrix) {
        List<List<Integer>> result = new ArrayList<>();
        if (matrix.length <= 0) {
            return result;
        }
        boolean[][] isVisited = new boolean[matrix.length][matrix[0].length];
        int [][] pacificPath = new int [matrix.length][matrix[0].length];
        int [][] atlanticPath = new int [matrix.length][matrix[0].length];
        
        int X = matrix.length;
        int Y = matrix[0].length;
        for (int i = 0; i < X; i++) {
            getResult(matrix, X, Y, i, 0, isVisited, pacificPath);
            getResult(matrix, X, Y, i, Y-1, isVisited, atlanticPath);
        }
        for (int j = 0; j < Y; j++) {
            getResult(matrix, X, Y, 0, j, isVisited, pacificPath);
            getResult(matrix, X, Y, X-1, j, isVisited, atlanticPath);
        }
        for (int i = 0; i < X; i++) {
            for (int j = 0; j < Y; j++) {
                if (pacificPath[i][j] == 1 && atlanticPath[i][j] == 1) {
                    List<Integer> one = new ArrayList<>();
                    one.add(i);
                    one.add(j);
                    result.add(one);
                }
            }
        }
        return result;
    }

    public void getResult(int[][] matrix, int X, int Y, int curX, int curY,  boolean[][] isVisited, int [][] path) {
        if (curX < 0 || curX >= X || curY < 0 || curY >= Y || path[curX][curY] == 1) {
            return;
        }
        if (!isVisited[curX][curY]) {
            path[curX][curY] = 1;
            isVisited[curX][curY] = true;
            if (curX+1 < X && matrix[curX+1][curY] >= matrix[curX][curY]) {
                getResult(matrix, X, Y, curX+1, curY, isVisited, path);
            }
            if (curX-1 >= 0 && matrix[curX-1][curY] >= matrix[curX][curY]) {
                getResult(matrix, X, Y, curX-1, curY, isVisited, path);
            }
            if (curY+1 < Y && matrix[curX][curY+1] >= matrix[curX][curY]) {
                getResult(matrix, X, Y, curX, curY+1, isVisited, path);
            }
            if (curY-1 >= 0 && matrix[curX][curY-1] >= matrix[curX][curY]) {
                getResult(matrix, X, Y, curX, curY-1, isVisited, path);
            }
            isVisited[curX][curY] = false;
        }
    }
}
// ```