```
class Solution {
    boolean flag = false;
    public boolean hasValidPath(int[][] grid) {

        //存储节点，方向 
        Node[][] gridnode = new Node[grid.length][grid[0].length];
        int[] dx = {0, 1, 0, -1};
        int[] dy = {-1, 0, 1, 0};
        int[][] visit = new int[grid.length][grid[0].length];
        for (int i = 0; i < grid.length; i++) {
            for (int j = 0; j < grid[0].length; j++) {
                switch (grid[i][j]) {
                    case 1:
                        Node node1 = new Node(1, 0, 1, 0);
                        gridnode[i][j] = node1;
                        break;
                    case 2:
                        Node node2 = new Node(0, 1, 0, 1);
                        gridnode[i][j] = node2;
                        break;
                    case 3:
                        Node node3 = new Node(1, 1, 0, 0);
                        gridnode[i][j] = node3;
                        break;
                    case 4:
                        Node node4 = new Node(0, 1, 1, 0);
                        gridnode[i][j] = node4;
                        break;
                    case 5:
                        Node node5 = new Node(1, 0, 0, 1);
                        gridnode[i][j] = node5;
                        break;
                    case 6:
                        Node node6 = new Node(0, 0, 1, 1);
                        gridnode[i][j] = node6;
                        break;
                    default:
                        break;
                }
            }
        }
        dfs(gridnode, visit, 0, 0, dx, dy);
        return flag;
    }

    //dfs遍历
    public void dfs(Node[][] grid, int[][] visit, int i, int j, int[] dx, int[] dy) {
        if ( i == grid.length - 1 && j == grid[0].length - 1) {
            flag = true;
            return;
        }
        if ( i < 0 || i > grid.length - 1 || j < 0 || j > grid[0].length - 1) {
            return;
        }
        visit[i][j] = 1;
        boolean bz = false;
        if (i >= 0 && i <= grid.length - 1 && j >=0 && j <= grid[0].length - 1)
        {
            
            if (i+dx[0] >= 0 && i+dx[0] <= grid.length -1 && 
                j+dy[0] >= 0 && j+dy[0] <= grid[0].length -1 && grid[i][j].left == 1 &&
            grid[i+dx[0]][j+dy[0]].right == grid[i][j].left && visit[i+dx[0]][j+dy[0]] == 0) {
                dfs(grid, visit, i + dx[0] ,j + dy[0], dx, dy);
                
                bz = true;
            }
            if (i+dx[1] >= 0 && i+dx[1] <= grid.length -1 &&
                j+dy[1] >= 0 && j+dy[1] <= grid[0].length -1 && grid[i][j].down == 1 &&
                    grid[i+dx[1]][j+dy[1]].up == grid[i][j].down && visit[i+dx[1]][j+dy[1]] == 0) {
                dfs(grid, visit, i + dx[1] ,j + dy[1], dx, dy);
                bz = true;
            }
            if (i+dx[2] >= 0 && i+dx[2] <= grid.length -1 &&
                j+dy[2] >= 0 && j+dy[2] <= grid[0].length -1 && grid[i][j].right == 1 &&
                grid[i+dx[2]][j+dy[2]].left == grid[i][j].right && visit[i+dx[2]][j+dy[2]] == 0) {
                dfs(grid, visit, i + dx[2] ,j + dy[2], dx, dy);
                bz = true;
            }

            if (i+dx[3] >= 0 && i+dx[3] <= grid.length -1 &&
                j+dy[3] >= 0 && j+dy[3] <= grid[0].length -1 && grid[i][j].up == 1 &&
                    grid[i+dx[3]][j+dy[3]].down == grid[i][j].up && visit[i+dx[3]][j+dy[3]] == 0) {
                dfs(grid, visit, i + dx[3] ,j + dy[3], dx, dy);
                bz = true;
            }
           if (!bz) {
                return;
            }
        }
         
        
    }
    class Node {
        int left;
        int down;
        int right;
        int up;
        public Node(int left, int down, int right, int up){
            this.left = left;
            this.right = right;
            this.down = down;
            this.up = up;
        }
    }
    
}
```

