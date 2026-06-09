### 解题思路
1. 回溯算法大同小异，根据框架实现即可，只不过要理解回溯算法较为困难
2. 在递归调用过程中，如果想保存中间结果，必须将递归数组进行拷贝才能保存，因为该数组在递归过程中始终是同一对象，下一次递归结果会覆盖里面内容
3. 为了节约内存，使用一维数组存储皇后摆放位置，数组下标表示行号，数组下标对应值表示列号
4. 判断已摆放皇后位置与当前检测位置是否在对角线上，只需根据对角线规则进行位置计算即可，不需要循环检测，左上角至右下角对角线行列是按比例递增的（row2-row1==col2-col1），右上角至左下角对角线行列互相消减（row1+col1==row2+col2）。

### 代码

```java
class Solution {

    /**
     * Find all solutions of n-queen problem
     *
     * @param n board size
     * @return all solution display strings
     */
    public List<List<String>> solveNQueens(int n) {
        List<List<String>> result = new ArrayList<>();
        Deque<int[]> solutions = new LinkedList<>();
        int[] solution = newSolution(n);
        findNQueen(solutions, solution, 0, n);
        for (int[] s : solutions) {
            result.add(solution2String(s));
        }
        return result;
    }

    /**
     * Create a new array of solution
     *
     * @param n array length
     * @return new array
     */
    public int[] newSolution(int n) {
        int[] solution = new int[n];
        Arrays.fill(solution, -1);
        return solution;
    }

    /**
     * Convert result array to string list
     *
     * @param solution the result array, each value stores the position which is correct to put a queen
     * @return string list
     */
    public List<String> solution2String(int[] solution) {
        List<String> result = new ArrayList<>();
        for (int rowVal : solution) {
            StringBuilder builder = new StringBuilder();
            for (int i = 0; i < solution.length; i++) {
                if (i == rowVal) {
                    builder.append("Q");
                } else {
                    builder.append(".");
                }
            }
            result.add(builder.toString());
        }
        return result;
    }

    /**
     * Find all solutions for n-queen problem
     *
     * @param solutions store all solutions
     * @param solution  store one solution
     * @param row       current row
     * @param n         board size
     */
    public void findNQueen(Deque<int[]> solutions, int[] solution, int row, int n) {
        if (row >= n) {
            //Because solution array is the same one throughout, we have to add its copy, or we will get empty array at last
            solutions.offer(Arrays.copyOf(solution, n));
            return;
        }

        for (int col = 0; col < n; col++) {
            if (check(solution, row, col)) {
                //find a valid check and store it
                solution[row] = col;
                //recursion
                findNQueen(solutions, solution, row + 1, n);
                //backtrack
                solution[row] = -1;
            }
        }
    }

    /**
     * Check if the value of current row and column is a valid position
     *
     * @param result solution result
     * @param row    current row
     * @param col    current column
     * @return if the position is valid by chess rules
     */
    public boolean check(int[] result, int row, int col) {
        for (int i = 0; i < result.length; i++) {
            //not occupied
            if (result[i] == -1) {
                continue;
            }
            //same row or same column
            if (i == row || result[i] == col) {
                return false;
            }
            //same diagonal from top left to bottom right
            if (((i < row && result[i] < col) || (i > row && result[i] > col)) && (Math.abs(i - row) == Math.abs(result[i] - col))) {
                return false;
            }
            //same diagonal from top right to bottom left
            if (((i > row && result[i] < col) || (i < row && result[i] > col)) && (i + result[i] == row + col)) {
                return false;
            }
        }
        return true;
    }
}
```