### 解题思路
性能很差，初学者

### 代码

```java
class Solution {
    class Position {
        int line;
        int row;
        int status; // 遍历找到所有为O的字符 0代表'O'尚未变化， 2代表不变，1代表'O'已遍历， 3代表已变

        Position(int line, int row, Boolean Edge) {
            this.line = line;
            this.row = row;
            if (Edge) {
                this.status = 2;
            } else {
                this.status = 0;
            }
        }

        public void changStatus(int status) {
            this.status = status;
        }

        public Boolean equals(Position a) {
            return a.line==(this.line) && a.row==(this.row);
        }

        public Boolean relate(Position a) {
            if ((Math.abs(a.line-this.line)==1 && a.row == this.row) ||
                    (a.line == this.line && Math.abs(a.row-this.row)==1) ) {
                return true;
            } else {
                return false;
            }
        }
    }

    public void solve(char[][] board) {
        if (board.length == 0)
            return;
        // 记录边界上的点
        Queue<Position> queue = new LinkedList<>();
        // 记录所有为'O'的点
        List<Position> list = new ArrayList<>();

        // 所有为'O'的入队列
        for (int i = 0; i < board.length; i++) {
            for (int j = 0; j < board[0].length; j++) {
                if (board[i][j] == 'O') {
                    Boolean edge = (i==0 || j==0 || i==board.length-1 || j==board[0].length-1);
                    Position p = new Position(i, j, edge);
                    list.add(p);
                    if (p.status == 2) {
                        queue.add(p);
                    }
                }
            }
        }

        // 以任意一个边境节点开始遍历
        while(!queue.isEmpty()) {
            Position cur = queue.peek();
            for (int i = 0; i < list.size(); i++) {
                Position test = list.get(i);
                if (test.status==0 && test.relate(cur)) {
                    test.changStatus(2);
                    queue.add(test);
                }
            }
            queue.remove(cur);
        }

        // 刷新board
        list.forEach((position -> {
            if (position.status==0){
                board[position.line][position.row] = 'X';
            }
        }));
    }
}
```