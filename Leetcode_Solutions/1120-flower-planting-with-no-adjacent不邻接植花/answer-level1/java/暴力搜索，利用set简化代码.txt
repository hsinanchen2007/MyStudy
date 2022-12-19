```java
import java.util.HashSet;

class Solution {
    public int[] gardenNoAdj(int N, int[][] paths) {
        // 构造图结构
        int[] A = new int[N];
        byte[][] map = new byte[N][N];
        for (int p[] : paths) {
            map[p[0] - 1][p[1] - 1] = -1;
            map[p[1] - 1][p[0] - 1] = -1;
        }
        //A处：将相邻且上过色的节点保存
        //B处：利用set快速找出可选择的颜色，进行上色
        HashSet<Integer> set = new HashSet<>(4);
        for (int i = 0; i < N; ++i) {
            if (A[i] > 0) continue;
            set.clear();
            for (int j = 0; j < N; ++j) {
                if (map[i][j] != -1) continue;
                if (A[j] == 0) continue;
                set.add(A[j]);//A
            }
            for (int j = 1; j < 5; j++) {
                if (set.contains(j)) continue; //B
                A[i] = j;
                break;
            }

        }
        return A;
    }

    public static void main(String[] args) {
        int n = 5;
        int[][] map = new int[][]{{4, 1}, {4, 2}, {4, 3}, {2, 5}, {1, 2}, {1, 5}};
        int A[] = new Solution().gardenNoAdj(n, map);
        for (int i = 0; i < n; i++) {
            System.out.println(A[i]);
        }
    }
}
```