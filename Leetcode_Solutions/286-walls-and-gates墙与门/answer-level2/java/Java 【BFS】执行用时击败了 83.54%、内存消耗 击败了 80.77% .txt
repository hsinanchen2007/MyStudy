### 解题思路
参考烂橘子中大佬思路。
首先将所有门点入队；
队列不为空时，针对每一轮当前队列的点，查看上下左右是否有可入队的相邻点，若有则入队，并赋值当前round轮数，round即为当前点步数。

### 代码

```java
class Solution {
    public void wallsAndGates(int[][] rooms) {

        int M = rooms.length;

        if (M == 0) return;
        
        int N = rooms[0].length;

        Queue<int[]> queue = new LinkedList<>();

        int round = 0;

        for (int i = 0; i < M; i++){
            for (int j = 0;j < N; j++){
                if (rooms[i][j] == 0)
                    queue.add(new int[]{i,j});  //门入队
            }
        }

        while (!queue.isEmpty()) {
            round++;
            int n = queue.size();
            for (int i = 0; i < n; i++){
                int[] room = queue.poll();
                int r = room[0];
                int c = room[1];

                if (r > 0 && rooms[r - 1][c] == 2147483647) {
                    rooms[r - 1][c] = round;
                    queue.add(new int[]{r - 1,c});
                }

                if (r + 1 < M && rooms[r + 1][c] == 2147483647) {
                    rooms[r + 1][c] = round;
                    queue.add(new int[]{r + 1,c});
                }

                if (c > 0 && rooms[r][c - 1] == 2147483647) {
                    rooms[r][c - 1] = round;
                    queue.add(new int[]{r,c - 1});
                }

                if (c + 1 < N && rooms[r][c + 1] == 2147483647) {
                    rooms[r][c + 1] = round;
                    queue.add(new int[]{r,c + 1});
                }
            }
        }
    }
}
```