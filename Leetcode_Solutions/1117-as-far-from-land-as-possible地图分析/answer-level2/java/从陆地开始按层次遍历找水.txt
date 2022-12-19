### 解题思路
- 每层遍历所有陆地附近的水一步（X或者Y轴）
- 遍历可以通过一个方向数组（左、右、上、下）实现。方向数组除了二维数组外，也可以通过两个一维数组实现

### 代码

```java
class Solution {
    public int maxDistance(int[][] grid) {
        Queue<int[]> queue = new LinkedList();

        int size = grid.length;
        for(int i=0; i<size; i++) {
            for(int j=0; j<size; j++) {
                if(grid[i][j] == 1) {
                    queue.add(new int[]{i,j});
                }
            }
        }
        // 全是水或者陆地
        if(queue.isEmpty() || queue.size() == size * size) {
            return -1;
        }

        int ans = 0;
        int[][] scan = new int[][] {{-1,0},{1,0},{0,-1},{0,1}}; // 左右上下四个方向的扫描数组
        while(!queue.isEmpty()) {
            int num = queue.size(); // 现有队列需要都遍历完，作为向附近的一次扩散
            for(int k=0; k<num; k++) {
                int[] land = queue.poll();
            
                for(int i=0; i<4; i++) {
                    int x = land[0] + scan[i][0];
                    int y = land[1] + scan[i][1];

                    if(x>=0 && x<size && y>=0 && y<size && grid[x][y] == 0) {
                        grid[x][y] = -1; // 标记已遍历过

                        queue.add(new int[] {x, y});
                    }
                }
            }

            ++ans;

        }

        return ans-1;
    }
}
```