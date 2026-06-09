### 解题思路
vector用来保存方向 往上、往下、往左、往右
判断当前点和下一个点是否符合要求

### 代码

```java
class Solution {
    public boolean hasValidPath(int[][] grid) {
        int[][] visited = new int[grid.length][grid[0].length];
        Queue<int[]> queue = new LinkedList<>();
        //方向 上下左右
        int[][] vectors = new int[][]{{-1, 0},{1, 0}, {0 , -1}, {0, 1}};
        queue.offer(new int[]{0, 0});
        visited[0][0] = 1;
        while (!queue.isEmpty()){
            int[] poll = queue.poll();
            if (poll[0] == grid.length - 1 && poll[1] == grid[0].length - 1)
                return true;
            int way = 1;
            for (int[] vector : vectors) {
                int a = poll[0] + vector[0];
                int b = poll[1] + vector[1];
                if (a >= 0 && a < grid.length && b >= 0 && b < grid[0].length && visited[a][b] == 0){
                    int before = grid[poll[0]][poll[1]];
                    int after =  grid[a][b];
                    if (isOk(before, after, way)){
                        queue.offer(new int[]{a, b});
                        visited[a][b] = 1;
                        break;
                    }
                }
                way++;
            }
        }
        return false;
    }

    private boolean isOk(int a, int b, int way){
        // way 代表 1， 2， 3， 4
        // 分别代表 上 下 左 右
        if (way == 1){
            if ((a == 2 || a == 5 || a == 6) && (b == 2 || b == 3 || b == 4))
                return true;
        }
        else if (way == 2){
            if ((a == 2 || a == 3 || a == 4) && (b == 2 || b == 5 || b == 6))
                return true;
        }
        else if (way == 3){
            if ((a == 1 || a == 3 || a == 5) && (b == 1 || b == 4 || b == 6))
                return true;
        }
        else if (way == 4){
            if ((a == 1 || a == 4 || a == 6) && ((b == 1 || b == 3 || b == 5)))
                return true;
        }
        return false;
    }
}
```