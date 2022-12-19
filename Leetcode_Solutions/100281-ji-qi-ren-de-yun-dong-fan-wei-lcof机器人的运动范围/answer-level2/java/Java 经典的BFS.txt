//今天的题是很经典的bfs搜索
class Solution {
     public int movingCount(int m, int n, int k) {
        if (k < 0) return -1;

        int[][] book = new int[m][n];
        int[] dx = {0, 0, 1, -1};
        int[] dy = {1, -1, 0, 0};

        Queue<int[]> queue = new LinkedList<>();

        //初始位置入队
        queue.offer(new int[]{0, 0});
        int res = 1;
        book[0][0] = 1;
        while (queue.size() != 0) {
            //出队
            int[] poll = queue.poll();
            for (int i = 0; i < 4; i++) {
                int newX = poll[0] + dx[i];
                int newY = poll[1] + dy[i];
                if (newX >= 0 && newX < m && newY >= 0 && newY < n && book[newX][newY] == 0 && numCounts(newX, newY, k)) {
                    queue.offer(new int[]{newX,newY});
                    book[newX][newY] = 1;
                    res++;
                }
            }
        }
        return res;

    }

    private boolean numCounts(int newX, int newY, int k) {
        int temp = 0;
        while (newX != 0 || newY != 0) {
            if (newX != 0) {
                temp += newX % 10;
                newX /= 10;
            }
            if (newY != 0) {
                temp += newY % 10;
                newY /= 10;
            }
        }
        return temp <= k;

    }
}