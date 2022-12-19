我只是照抄大神的答案再次做mark，共勉。

```
public int maxDistance(int[][] grid) {
        int size = grid.length;
        Queue<int[]> queue = new ArrayDeque<>();
        // 所有的陆地都放到队列中
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < grid[i].length; j++) {
                if(grid[i][j] == 1){
                    queue.add(new int[] {i,j});
                }
            }
        }
        // 如果全部是海洋或者全部是陆地则返回-1
        if(queue.size() == size*size || queue.isEmpty()){
            return -1;
        }
        // 创建方向坐标数组
        int[][] face = {{0,1},{0,-1},{-1,0},{1,0}};
        int distance = 0;
        while (!queue.isEmpty()){
            // 当前队列大小
           int currentSize = queue.size();
            for (int i = 0; i < currentSize; i++) {
                // 当前元素
                int[] currentD = queue.poll();
                for (int j = 0; j < face.length; j++) {
                    int x = currentD[0]+face[j][0];
                    int y = currentD[1]+face[j][1];
                    // 判断在数组范围内，并且是海洋坐标
                    if(x>=0 && x<size && y>=0 && y<size && grid[x][y] == 0){
                        // 将此位置标记为已经做过比较了
                        grid[x][y] = 2;
                        queue.add(new int[]{x,y});
                    }
                }

            }
            if(!queue.isEmpty()){
                distance++;
            }
        }
        return distance;
    }
```
