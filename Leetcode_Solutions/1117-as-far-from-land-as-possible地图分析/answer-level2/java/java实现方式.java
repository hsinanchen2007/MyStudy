![image.png](https://pic.leetcode-cn.com/bbdc1fa0eeabbc0b0896d1c18691efc44a0d229374c37539b3ed6d60242f3a33-image.png)
看了各位大佬的评论醍醐灌顶，由于我是写java的，好多C++和Python的类库我都看不懂。。。
我感觉肯定还有很多像我这样的小白，所以我打算把我自己的思路贡献出来，希望能有所帮助
我的思路很简单：
1、找到所有的陆地
2、从陆地逐渐往海水扩展
```
   public int maxDistance(int[][] grid) {
        if (grid == null) return 0;
        int row = grid.length;
        int col = grid[0].length;
        /*记录所有陆地的位置*/
        List<Position> positions = new ArrayList<>();
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                int value = grid[i][j];
                if (value == 1) {
                    positions.add(new Position(i, j));

                }
            }
        }
        if (positions.size() == 0 || positions.size() == row * col) {
            return -1;
        }
        return getMax(grid, positions, 0);

    }

    private Integer getMax(int[][] grid, List<Position> positions, Integer curr) {

        List<Position> levelPosition = new ArrayList<>();
        for (Position position : positions) {
            if (position.row - 1 >= 0) {
                if (grid[position.row - 1][position.col] != 1) {
                    levelPosition.add(new Position(position.row - 1, position.col));
                    grid[position.row - 1][position.col] = 1;
                }
            }
            if (position.row + 1 < grid.length) {
                if (grid[position.row + 1][position.col] != 1) {
                    levelPosition.add(new Position(position.row + 1, position.col));
                    grid[position.row + 1][position.col] = 1;
                }
            }
            if (position.col - 1 >= 0) {
                if (grid[position.row][position.col - 1] != 1) {
                    levelPosition.add(new Position(position.row, position.col - 1));
                    grid[position.row][position.col - 1] = 1;
                }
            }
            if (position.col + 1 < grid[0].length) {
                if (grid[position.row][position.col + 1] != 1) {
                    levelPosition.add(new Position(position.row, position.col + 1));
                    grid[position.row][position.col + 1] = 1;
                }
            }

        }
        if (levelPosition.size() == 0) {
            return curr;
        }
        return getMax(grid, levelPosition, curr + 1);
    }

    class Position {
        public Integer row;

        public Integer col;

        public Position(Integer row, Integer col) {
            this.row = row;
            this.col = col;
        }
    }
```

