### 解题思路
见代码
### 代码

```java
class Solution {
   /* public static void main(String[] args) {
        int m=16,n=8,k=4;
        System.out.println(movingCount(m,n,k));
    }*/

    public  int movingCount(int m, int n, int k) {
        if (k == 0) return 1;

        boolean[][] vis = new boolean[m][n]; //辅助数组 判断障碍物
        //全部填充为false
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                vis[i][j]=false;
            }
        }

        vis[0][0] = true; //初始坐标必定为0
        int sum = 0; 


        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                
                boolean cur = path(i, j, vis); //询问周围是否有连通的，有没有障碍物
                if (i == 0 && j == 0) cur = true; //初始情况特殊处理
                if ((sum_of_each_digits(i) + sum_of_each_digits(j)) > k || cur==false) continue; //各位数上的和大于k，则跳过该位置或者，没有可以到达的路径
                vis[i][j] = true; //遍历过了，自然可以为true
                sum++; 
            }
        }

        return sum;

    }
     //寻问是否有路径可以到达，当前坐标
    public  boolean path(int x, int y, boolean[][] vis) { 
        int[] dx = {-1, 1, 0, 0};
        int[] dy = {0, 0, -1, 1};
        for (int i = 0; i < 4; i++) {
            int new_x = x + dx[i];
            int new_y = y + dy[i];
            if (new_x < 0 || new_y < 0 || new_x >= vis.length || new_y >= vis[0].length) continue;
            if (vis[new_x][new_y]) return true;
        }
        return false;
    }
    //各个数位上数字之和
    public  int sum_of_each_digits(int a) {
        int sum = 0;
        while (a != 0) {
            sum += a % 10;
            a /= 10;
        }
        return sum;
    }
}
```