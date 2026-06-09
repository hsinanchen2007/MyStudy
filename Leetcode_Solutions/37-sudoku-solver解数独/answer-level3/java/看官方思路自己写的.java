方法
1. getCandidates方法：获取当前位置可填字符
2. findNext方法：获取下一个需要填写的空格位置
3. backtrack方法：回溯方法

变量
1. trace：类型Stack<int[]>，其数组中为第一个行号，第一个列号
2. allCandidate：二维数组，存储着每一个需要填写的空格中可填字符
3. next：存储下一个字符的位置

思路
1. 当findNext找不到下一个字符的填写位置则表示完成数独
2. 找到下一个可选的字符的位置，然后找到该位置可填写的字符
3. 如果存在候选字符，则选择该候选字符数组中选择最后一个，然后将该位置压入栈中，更新next
4. 如果没有候选字符，则表示之前填写的存在问题，则调用回溯方法，弹出栈顶元素，然后将next赋予弹出的值，并将元素设置为空

```java
class Solution {
    public void solveSudoku(char[][] board) {
        Stack<int[]> trace = new Stack<>();
        // 当前排除元素
        // char[][] excludes = new char[81][1];
        // 存储候选
        char[][] allCandidate = new char[81][9];
        // char[][] cacheCandidate = new char[81][9];
        int i = 0, j = 0;
        int[] next = findNext(board, i, j);
        int mn = 0;
        while (next[0]!= -1 && i < 9 && j < 9){
            int row = next[0];
            int col = next[1];
            allCandidate[9 * row + col] = getCandidates(board, row, col, allCandidate);
            char[] candidates = allCandidate[9 * row + col];
//            mn++;
//            if (candidates.length != 0){
//                System.out.println(Arrays.toString(candidates));
//                System.out.println(row + ":" + col);
//                System.out.println(mn);
//            }
            if (candidates.length == 0){
                // 回溯
                int[] prev = backtrack(trace);
                if (prev[0] == -1){
                    i = 0; j =0;
                }else {
                    i = prev[0]; j = prev[1];
                }
                next = new int[]{i, j};
                board[i][j] = '.';

            }else {
                // 每次取最后一个，当回溯时直接从候选中删除最后一个
                board[row][col] = candidates[candidates.length - 1];
                trace.push(new int[]{row, col});
                i = row; j = col;
                next = findNext(board, i, j);
            }
        }
    }

    public int[] backtrack(Stack<int[]> trace){
        if (trace.empty()){
            return new int[]{-1, -1};
        }
        return trace.pop();
    }

    // 获取下一个需要填充的位置
    public int[] findNext(char[][] board, int row, int col){
        int[] result = new int[]{-1, -1};
        for (int i = col; i < 9; i++){
            if (board[row][i] == '.'){
                result[0] = row;
                result[1] = i;
                // System.out.println(Arrays.toString(result));
                return result;
            }
        }
        for (int i = row + 1; i < 9; i++){
            for (int j = 0; j < 9; j++){
                if (board[i][j] == '.'){
                    result[0] = i;
                    result[1] = j;
                    // System.out.println(Arrays.toString(result));
                    return result;
                }
            }
        }
        return result;
    }

    // 获取当前元素可选值
    public char[] getCandidates(char[][] board, int row, int col, char[][] allCandidate){
        char[] cache = allCandidate[9 * row + col];
        int cacheLen = 0;
        for (int i = 0; i < cache.length; i++){
            if (cache[i] != '\0'){
                cacheLen ++;
            }else {
                break;
            }
        }
        if (cacheLen > 1){
            // char[] exclude = excludes[9 * row + col];
            return Arrays.copyOf(cache, cacheLen - 1);
        }
        if (cacheLen == 1){
            return new char[0];
        }

        // 缓存
//        cache = cacheCandidate[9 * row + col];
//        cacheLen = 0;
//        for (int i = 0; i < cache.length; i++){
//            if (cache[i] != '\0'){
//                cacheLen ++;
//            }else {
//                break;
//            }
//        }
//        if (cacheLen != 0){
//            return cache;
//        }

        char[] result = new char[9];
        int len = 0;
        boolean[] test = new boolean[9];
        // row
        for (int i = 0; i < 9; i++){
            if (i == col)
                continue;
            char c = board[row][i];
            if (c != '.'){
                int index = c - '1';
                test[index] = true;
            }
        }
        // col
        for (int i = 0; i < 9; i++){
            if (i == row)
                continue;
            char c = board[i][col];
            if (c != '.'){
                int index = c - '1';
                test[index] = true;
            }
        }
        // 3 * 3
        int x = row / 3;
        int y = col / 3;
        for (int i = 0; i < 3; i++){
            for (int j = 0; j < 3; j++){
                int a = 3 * x + i;
                int b = 3 * y + j;
                if (a == row && b == col){
                    continue;
                }
                char c = board[a][b];
                if (c != '.'){
                    int index = c - '1';
                    test[index] = true;
                }
            }
        }

        for (int i = 0; i < test.length; i++){
            if (!test[i]){
                result[len] = (char) ('1' + i);
                len++;
            }
        }

        return Arrays.copyOf(result, len);
    }
}
```