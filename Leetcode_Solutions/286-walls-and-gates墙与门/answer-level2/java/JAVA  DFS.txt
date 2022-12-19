```
import javax.swing.*;
import java.util.List;

class Solution {

    int M, N;//行数 与一列数
    boolean[][] F;//是否已被访问
    int min;//最小路径值

    boolean isOK(int i, int j, int[][] R) {//判断当前位置是否合法
        return i > -1 && i < M && j > -1 && j < N && R[i][j] != -1;
    }

    void fillF() {//初始化F[][]的值
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                F[i][j] = false;
            }
        }
    }

    public void wallsAndGates(int[][] rooms) {
        if(rooms==null ||rooms.length<1 ||rooms[0].length<1){
            return;
        }
        
        M = rooms.length;
        N = rooms[0].length;
        int INF = Integer.MAX_VALUE;
        F = new boolean[M][N];
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                if (INF == rooms[i][j]) {
                    fillF();
                    min = INF;
                    dfs(i, j, rooms, 0);
                    if (min != INF) {//与 min = INF;对应
                        rooms[i][j] = min;
                    }
                }
            }
        }
    }

    void dfs(int i, int j, int[][] R, int step) {

        if (R[i][j] == 0) {
            min = Math.min(min, step);
            return;
        }
        if (isOK(i - 1, j, R) && !F[i - 1][j]) {
            F[i - 1][j] = true;
            dfs(i - 1, j, R, 1 + step);
            F[i - 1][j] = false;
        }
        if (isOK(i + 1, j, R) && !F[i + 1][j]) {
            F[i + 1][j] = true;
            dfs(i + 1, j, R, 1 + step);
            F[i + 1][j] = false;
        }
        if (isOK(i, j - 1, R) && !F[i][j - 1]) {
            F[i][j - 1] = true;
            dfs(i, j - 1, R, 1 + step);
            F[i][j - 1] = false;
        }
        if (isOK(i, j + 1, R) && !F[i][j + 1]) {
            F[i][j + 1] = true;
            dfs(i, j + 1, R, 1 + step);
            F[i][j + 1] = false;
        }
        return;
    }

}
```