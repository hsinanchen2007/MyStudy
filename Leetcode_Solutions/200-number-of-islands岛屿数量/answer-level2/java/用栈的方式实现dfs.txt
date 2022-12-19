 dfs用栈的方法实现，方式和bfs类似但是本质不同。
public int numIslands(char[][] grid) {
        if(grid.length==0){
        return 0;            
    }
        int row = grid.length;
        int col = grid[0].length;
        Stack<Integer> stack = new Stack<>();
        int num = 0;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j] == '1') {
                    int cal = i * col + j;
                    grid[i][j] = '0';
                    num++;
                    stack.push(cal);
                    while (!stack.isEmpty()) {
                        Integer pop = stack.pop();
                        int row1 = pop / col;
                        int col1 = pop % col;
                        if (col1 + 1 < col && grid[row1][col1 + 1] == '1') {
                            grid[row1][col1 + 1] = '0';
                            stack.push(pop + 1);
                        }
                        if (col1 - 1 >= 0 && grid[row1][col1 - 1] == '1') {
                            grid[row1][col1 - 1] = '0';
                            stack.push(pop - 1);
                        }
                        if (row1 - 1 >= 0 && grid[row1 - 1][col1] == '1') {
                            grid[row1 - 1][col1] = '0';
                            stack.push(pop - col);
                        }
                        if (row1 + 1 < row && grid[row1 + 1][col1] == '1') {
                            grid[row1 + 1][col1] = '0';
                            stack.push(pop + col);
                        }
                    }
                }

            }
        }
        return num;

    }