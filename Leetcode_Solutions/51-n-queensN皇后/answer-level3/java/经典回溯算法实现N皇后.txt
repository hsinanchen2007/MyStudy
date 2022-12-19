棋盘每行每列编号0～n-1
```
class Solution {
    List<List<String>> result = new ArrayList();
    public List<List<String>> solveNQueens(int n) {
        int[][] queen = new int[n][n];//棋盘：默认全为0,第i行j列放置棋子后置为1
        nQueens(queen, 0, n);//从第0行开始放置棋子
        return result;
    }

    private void nQueens(int[][] queen, int index, int n) {
        //当0到n-1行全部放置完成后，输出结果
        if(index == n) {
            List<String> list = new ArrayList();
            for(int i = 0; i < n; i++) {
                StringBuilder sb = new StringBuilder();
                for(int j = 0; j < n; j++) {
                    if(queen[i][j] == 0) {
                        sb.append(".");
                    } else {
                        sb.append("Q");
                    }
                }
                list.add(sb.toString());
            }
            result.add(list);
            return;
        }
        //验证第index行第i位是否合法，如果合法放置棋子并开始下一行
        for(int i = 0; i < n; i++) {
            if(isQueen(queen, index, i)) {
                queen[index][i] = 1;//放置棋子
                nQueens(queen, index + 1, n);//开始放置下一行
                queen[index][i] = 0;//还原棋盘，验证下一个位置
            }
        }
    }

    private Boolean isQueen(int[][] queen, int index, int n) {
        //纵向验证
        for(int i = 0; i < index; i++) {
            if(queen[i][n] == 1) return false;
        }

        int temp = 0;
        //左上到右下方斜向验证
        for(int i = n-1; i >= 0; i--) {
            temp = i + index - n;
            if(temp < 0) break;
            if(queen[temp][i] == 1) return false;
        }
        //右上到左下验证
        for(int i = n+1; i < queen.length; i++) {
            temp = index + n - i;
            if(temp < 0) break;
            if(queen[temp][i] == 1) return false;
        }

        return true;
    }
}
```
