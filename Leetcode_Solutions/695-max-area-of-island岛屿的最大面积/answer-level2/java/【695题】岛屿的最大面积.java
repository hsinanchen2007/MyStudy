**方法一：深度优先遍历 + 递归**
```
class Solution {
    /**
    * 思路：
    * (1) 按顺序遍历二维数组，如果遍历到1则通过递归方法深度优先遍历出与当前1相连的最大岛屿，
    *       并把每个遍历到并计数后的1改为0，避免重复计数；
    * (2) 每完成一次循环则记录当前找到的最大岛屿面积；
    * (3) 直到循环遍历结束，返回最终记录的最大岛屿面积。
    */
    public int maxAreaOfIsland(int[][] grid) {
        int res = 0; 
        for (int i = 0; i < grid.length; i++) {
            for (int j = 0; j < grid[i].length; j++) {
                if (grid[i][j] == 1) {
                    res = Math.max(res, dfs(i, j, grid));
                }
            }
        } 
        return res;
    }
    
    private int dfs(int i, int j, int[][] grid) {
        // 如果当前位置越界或者不是岛屿，则直接返回0。
        if (i < 0 || j < 0 || i >= grid.length || j >= grid[i].length || grid[i][j] == 0) { 
            return 0;
        } 
        // 如果当前位置是岛屿则从1开始计数，并对当前岛屿做沉岛处理。
        grid[i][j] = 0;
        int num = 1;
        num += dfs(i + 1, j, grid);
        num += dfs(i - 1, j, grid);
        num += dfs(i, j + 1, grid);
        num += dfs(i, j - 1, grid);
        return num;
    }
}
```

**方法二：深度优先遍历 + 栈**
```
class Solution {
    /**
    * 思路：
    * 同方法一，用栈来存储每个与当前岛屿相连的位置，通过栈的pop()方法取出每个位置判断是不是岛屿。
    * (1) 按顺序循环遍历二维数组，如果遍历到1则添加到栈内深度遍历出与当前1相连的最大岛屿，
    *       并把每个遍历到并计数后的1改为0，避免重复计数；
    * (2) 每完成一次循环则记录当前找到的最大岛屿面积；
    * (3) 直到遍历结束，返回最终记录的最大岛屿面积。
    */
    public int maxAreaOfIsland(int[][] grid) {
        Deque<int[]> stack = new LinkedList<>();
        // 辅助找出每个位置上下左右四个相连位置
        int[][] moveIndexArray = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        // 记录最大岛屿面积
        int maxArea = 0;
        for (int i = 0; i < grid.length; i++) {
            for (int j = 0; j < grid[i].length; j++) {
                if(grid[i][j] == 1){
                    stack.add(new int[]{i, j});
                }
                // 记录当前的岛屿面积
                int currArea = 0;
                while (!stack.isEmpty()) {
                    int[] pop = stack.pop();
                    int currI = pop[0];
                    int currJ = pop[1];
                    // 如果当前位置越界或者不是岛屿，则继续下次循环。
                    if (currI < 0 || currI >= grid.length || currJ < 0
                            || currJ >= grid[0].length || grid[currI][currJ] == 0) {
                        continue;
                    }
                    // 如果当前位置是岛屿，则当前岛屿面积+1并做沉岛处理。
                    currArea++;
                    grid[currI][currJ] = 0;
                    // 将与当前位置相连的四个位置添加进栈顶。
                    for (int[] moveIndex : moveIndexArray) {
                        stack.add(new int[]{currI + moveIndex[0], currJ + moveIndex[1]});
                    }
                }
                maxArea = Math.max(currArea, maxArea);
            }
        }
        return maxArea;
    }
}
```

**方法三：广度优先遍历 + 队列**
```
class Solution {
    /**
    * 思路：
    * 同方法二，用队列来存储每个与当前岛屿相连的位置，按广度优先遍历每个相连位置。
    */
    public int maxAreaOfIsland(int[][] grid) {
        Deque<int[]> queue = new LinkedList<>();
        // 辅助找出每个位置上下左右四个相连位置
        int[][] moveIndexArray = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        // 记录最大岛屿面积
        int maxArea = 0;
        for (int i = 0; i < grid.length; i++) {
            for (int j = 0; j < grid[i].length; j++) {
                if(grid[i][j] == 1){
                    queue.add(new int[]{i, j});
                }                
                // 记录当前的岛屿面积
                int currArea = 0;
                while (!queue.isEmpty()) {
                    int size = queue.size();
                    for (int k = 0; k < size; k++) {
                        int[] poll = queue.poll();
                        int currI = poll[0];
                        int currJ = poll[1];
                        // 如果当前位置越界或者不是岛屿，则继续下次循环。
                        if (currI < 0 || currI >= grid.length || currJ < 0 
                                || currJ >= grid[0].length || grid[currI][currJ] == 0) {
                            continue;
                        }
                        // 如果当前位置是岛屿，则当前岛屿面积+1并做沉岛处理。
                        currArea++;
                        grid[currI][currJ] = 0;
                        // 将与当前位置相连的四个位置添加进队列队尾。
                        for (int[] moveIndex : moveIndexArray) {
                            queue.offer(new int[]{currI + moveIndex[0], currJ + moveIndex[1]});
                        }
                    }
                }
                maxArea = Math.max(currArea, maxArea);
            }
        }
        return maxArea;
    }
}
```
