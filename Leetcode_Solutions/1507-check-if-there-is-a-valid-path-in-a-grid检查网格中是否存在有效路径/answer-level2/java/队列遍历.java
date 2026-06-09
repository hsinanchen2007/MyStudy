### 解题思路
用一个哈希表存储每个网格可到达下一网格的所有情况，接着使用队列来遍历，根据当前的方向和网格值来判断当前网格是否可达，用二维数组来存储每个网格是否被访问，最后遍历结束时如果目标网格在访问数组中已记录为访问则返回true，否则不存在路径返回false。

### 代码

```java
class Solution {
    private int[] x = new int[]{-1, 1, 0, 0};
    private int[] y = new int[]{0, 0, -1, 1};

    public boolean hasValidPath(int[][] grid) {
        int row = grid.length;
        int column = grid[0].length;
        int[][] visited = new int[row][column];
        Queue<Integer> queue = new LinkedList<>();
        queue.add(0);
        visited[0][0] = 1;
        Map<Integer, List<Integer>> mapper = new HashMap<>();
        for (int i = 1; i <= 6; i++) {
            List<Integer> list = new LinkedList<>();
            switch (i) {
                case 1: {
                    list.add(1);
                    list.add(3);
                    list.add(4);
                    list.add(5);
                    list.add(6);
                    break;
                }
                case 2: {
                    list.add(2);
                    list.add(3);
                    list.add(4);
                    list.add(5);
                    list.add(6);
                    break;
                }
                case 3: {
                    list.add(1);
                    list.add(2);
                    list.add(4);
                    list.add(5);
                    list.add(6);
                    break;
                }
                case 4: {
                    list.add(1);
                    list.add(2);
                    list.add(3);
                    list.add(5);
                    list.add(6);
                    break;
                }
                case 5: {
                    list.add(1);
                    list.add(2);
                    list.add(3);
                    list.add(4);
                    list.add(6);
                    break;
                }
                case 6: {
                    list.add(1);
                    list.add(2);
                    list.add(3);
                    list.add(4);
                    list.add(5);
                    break;
                }

            }
            mapper.put(i, list);
        }
        while (!queue.isEmpty()) {
            int num = queue.poll();
            int r = num / column;
            int c = num % column;
            for (int i = 0; i < 4; i++) {
                int x1 = r + x[i];
                int y1 = c + y[i];
                if (x1 >= 0 && x1 < row && y1 >= 0 && y1 < column && visited[x1][y1] == 0) {
                    List<Integer> list = mapper.get(grid[r][c]);
                    int j = grid[x1][y1];
                    if (list.contains(j)) {
                        if (grid[r][c] == 1) {
                            if (j==1&&(i==2||i==3)){//左右两边
                                queue.add(x1*column+y1);
                                visited[x1][y1] = 1;
                            }else if ((j==3||j==5)&&i==3){//右边
                                queue.add(x1*column+y1);
                                visited[x1][y1] = 1;
                            }else if ((j==4||j==6)&&i==2){//左边
                                queue.add(x1*column+y1);
                                visited[x1][y1] = 1;
                            }
                        }else if (grid[r][c]==2){
                            if (j==2&&(i==0||i==1)){//上下两边
                                queue.add(x1*column+y1);
                                visited[x1][y1] = 1;
                            }else if ((j==3||j==4)&&i==0){//上面
                                queue.add(x1*column+y1);
                                visited[x1][y1] = 1;
                            }else if ((j==5||j==6)&&i==1){//下面
                                queue.add(x1*column+y1);
                                visited[x1][y1] = 1;
                            }
                        }else if (grid[r][c]==3){
                            if ((j==1||j==4||j==6)&&i==2){//左边
                                queue.add(x1*column+y1);
                                visited[x1][y1] = 1;
                            }else if ((j==2||j==5||j==6)&&i==1){//下面
                                queue.add(x1*column+y1);
                                visited[x1][y1] = 1;
                            }
                        }else if (grid[r][c]==4){
                            if ((j==1||j==3||j==5)&&i==3){//右边
                                queue.add(x1*column+y1);
                                visited[x1][y1] = 1;
                            }else if ((j==2||j==5||j==6)&&i==1){//下面
                                queue.add(x1*column+y1);
                                visited[x1][y1] = 1;
                            }
                        }else if (grid[r][c]==5){
                            if ((j==2||j==3||j==4)&&i==0){//上面
                                queue.add(x1*column+y1);
                                visited[x1][y1] = 1;
                            }else if ((j==1||j==4||j==6)&&i==2){//左边
                                queue.add(x1*column+y1);
                                visited[x1][y1] = 1;
                            }
                        }else if (grid[r][c]==6){
                            if ((j==2||j==3||j==4)&&i==0){//上面
                                queue.add(x1*column+y1);
                                visited[x1][y1] = 1;
                            }else if ((j==1||j==3||j==5)&&i==3){//右边
                                queue.add(x1*column+y1);
                                visited[x1][y1] = 1;
                            }
                        }
                    }
                    if (visited[row - 1][column - 1] == 1) {
                        return true;
                    }
                }
            }
        }
        return visited[row-1][column-1]==1?true:false;
    }
}
```