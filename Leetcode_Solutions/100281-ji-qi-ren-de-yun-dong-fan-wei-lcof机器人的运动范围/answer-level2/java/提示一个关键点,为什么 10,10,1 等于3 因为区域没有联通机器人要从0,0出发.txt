``` java
public class 面试题13机器人的运动范围 {
//    public int get(int x) {
//        int res = 0;
//        while (x > 0) {
//            res += x % 10;
//            x /= 10;
//        }
//        return res;
//    }
//
//    public int movingCount(int m, int n, int k) {
//        int[][] nums = new int[m][n];
//        nums[0][0] = 1;
//        int res = 1;
//        for (int i = 0; i < m; i++) {
//            for (int j = 0; j < n; j++) {
//                if ((i == 0 && j == 0) || get(i) + get(j) > k) continue;
//                if (i > 0)
//                    nums[i][j] |= nums[i - 1][j];
//                if (j > 0)
//                    nums[i][j] |= nums[i][j - 1];
//                res += nums[i][j];
//            }
//        }
//        return res;
//    }
    boolean[][] visited;

    public int movingCount(int m, int n, int k) {
        visited = new boolean[m][n];
        return DFS(0, 0, k);
    }


    public int DFS(int m, int n, int k) {
        if (m < 0 || n < 0 || m >= visited.length || n >= visited[0].length || getNum(m, n) > k || visited[m][n]) {
            return 0;
        }
        visited[m][n] = true;
        return 1 +  DFS(m + 1, n, k)  + DFS(m, n + 1, k);

    }

    public int getNum(int m, int n) {
        return m / 100 + m / 10 + m % 10 + n / 100 + n / 10 + n % 10;
    }

    public static void main(String[] args) {
        面试题13机器人的运动范围 bar = new 面试题13机器人的运动范围();
        System.out.println(bar.movingCount(2, 3, 1) == 3);
        System.out.println(bar.movingCount(3, 1, 0) == 1);
        System.out.println(bar.movingCount(10, 10, 1));
    }
}

```
