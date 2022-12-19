### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    private int n;
    private List<List<String>> ret = new ArrayList<>();
    public List<List<String>> solveNQueens(int n) {
        this.n = n;
        // 用一个布尔二维数组来记录棋盘的某一个点是否可以放置皇后，false表示可以
        boolean[][] mark = new boolean[n][n];
        List<String> already = new ArrayList<>();
        backtracking(already, 0, mark);
        return ret;
    }
    private void backtracking(List<String> already, int row, boolean[][] mark){
        if(row == n){
            ret.add(new ArrayList<>(already));
            return;
        }
        for(int col = 0; col < n; col++){
            if(!mark[row][col]){
                // 保存目前的mark状态，以便后来现场恢复
                boolean[][] old = new boolean[n][n];
                for(int x = row+1; x < n; x++){
                    for(int y = 0; y < n; y++){
                        old[x][y] = mark[x][y];
                    }
                }
                // 那一列不可以放置皇后了
                colHandle(row, col, mark);
                // 对角线不可以放置皇后了
                diagHandle(row, col, mark);
                // 生成该行的字符串
                String s = genString(col);
                already.add(s);
                // 放置下一行
                backtracking(already, row+1, mark);
                // 还原现场
                already.remove(already.size() - 1);
                for(int x = row+1; x < n; x++){
                    for(int y = 0; y < n; y++){
                        mark[x][y] = old[x][y];
                    }
                }
            }           
        }
        return;
    }
    // 列处理
    private void colHandle(int row, int col, boolean[][] mark){
        // 从下一行标记
        row++;
        while(row < n){
            mark[row][col] = true;
            row++;
        }
        return;
    }
    // 对角线处理
    private void diagHandle(int row, int col, boolean[][] mark){
        row++;
        // 向右的对角线
        int col1 = col + 1;
        // 向左的对角线
        int col2 = col - 1;
        while(row < n){
            if(col1 < n){
                mark[row][col1] = true;
            }
            if(col2 >= 0){
                mark[row][col2] = true;
            }
            row++;
            col1++;
            col2--;
        }
        return;
    }
    // 生成字符串
    private String genString(int col){
        StringBuffer sb = new StringBuffer();
        for(int i = 0; i < n; i++){
            if(i == col){
                sb.append('Q');
            }
            else{
                sb.append('.');
            }
        }
        return sb.toString();
    }
}
```