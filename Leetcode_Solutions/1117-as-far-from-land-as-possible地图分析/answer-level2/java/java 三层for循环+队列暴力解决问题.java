### 解题思路
1.思路都在注释里
2.唯一的关键操作在于区分第一次传播和后续的传播,因为第一次传播需要将所有的1入队
### 代码

```java
 class Solution   {
    public int maxDistance(int[][] grid) {
        /*思路：广度遍历，感染整个大方格,返回感染所需要的广度遍历次数*/
        /*先来个方向数组,方向是上下左右*/
        int[] dr = {-1, 1, 0, 0};
        int[] dc = {0, 0, -1, 1};
        int N = grid.length;
        int count = 2;
        int res = -1;
        /*必须加入队列判断广度遍历是否完毕*/
        Queue<Integer> queue = new LinkedList<>();
        /*遍历一次二维数组，让所有的1都进行一次病毒传播,被传播到的方格变为count+1*/
        for (int l = 0; l < N + 2; l++) {
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    /*第一次传播的条件。将所有的1入队*/
                    if (grid[i][j] == 1 && count == 2) {
                        queue.add(count - 1);
                    }
                    /*普遍的传播条件*/
                    if (grid[i][j] == count - 1) {
                        for (int k = 0; k < 4; k++) {
                            if (i + dr[k] >= 0 && i + dr[k] < N && j + dc[k] >= 0 && j + dc[k] < N && grid[i + dr[k]][j + dc[k]] == 0) {
                                grid[i + dr[k]][j + dc[k]] = count;
                                queue.add(count);
                            }
                        }
                        res = queue.remove();
                    }
                }
            }
            count ++ ;
            if (queue.isEmpty()) {
                return res <= 1 ? -1 : res - 1;
            }
        }
        //没啥用的一句话，可以随便return
        return res;
    }
   }
```