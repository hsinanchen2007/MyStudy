执行用时：3 ms
内存消耗：40.9 MB
```
class Solution {
    //创建一个静态内部类
    static class Point {
        int row;
        int column;
        char s;

        private Point(int row, int column, char s) {
            this.row = row;
            this.s = s;
            this.column = column;
        }


        @Override
        public boolean equals(Object o) {
            if (getClass() != o.getClass()) return false;
            Point point = (Point) o;
            return row == point.row || column == point.column || (point.row / 3 == row / 3 && point.column / 3 == column / 3);
        }

        @Override
        public int hashCode() {
            return Objects.hash(s);
        }
    }
    public boolean isValidSudoku(char[][] board) {
     Set<Point> set = new HashSet<>();
        for (int i = 0; i < board.length; i++) {
            for (int j = 0; j < board[i].length; j++) {
                if (board[i][j] == '.') continue;
                Point point = new Point(i, j, board[i][j]);
                if (!set.contains(point)) set.add(point);
                else return false;
            }
        }
        return true;
    }
}
```

