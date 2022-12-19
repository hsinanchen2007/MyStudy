### 解题思路
因为对应的转向方向是固定的，所以只要走到边界后转向并且修改边界的值，然后继续移动就能得到结果

### 代码

```java
class Solution {
    enum States {
        LEFT, RIGHT, DOWN, UP
    }

    private int[][] matrix;
    private int top;
    private int bottom;
    private int left;
    private int right;
    private States state = States.RIGHT;

    public int[][] generateMatrix(int n) {
        matrix = new int[n][n];
        top = 1;
        left = 0;
        bottom = n;
        right = n;
        matrix[0][0] = 1;
        if(n==1) return matrix;

        moveNext(0, 0, 2);
        return matrix;
    }

    private void moveNext(int row, int col, int num) {
        if (top == bottom && left == right) return;
        switch (state) {
            case RIGHT: {
                if (col < right - 1) {
                    matrix[row][col + 1] = num;
                    moveNext(row, col + 1, num + 1);
                } else {
                    right--;
                    state = States.DOWN;
                    moveNext(row, col, num);
                }
                break;
            }
            case LEFT: {
                if (col > left) {
                    matrix[row][col - 1] = num;
                    moveNext(row, col - 1, num + 1);
                } else {
                    left++;
                    state = States.UP;
                    moveNext(row, col, num);
                }
                break;
            }
            case DOWN: {
                if (row < bottom - 1) {
                    matrix[row + 1][col] = num;
                    moveNext(row + 1, col, num + 1);
                } else {
                    bottom--;
                    state = States.LEFT;
                    moveNext(row, col, num);
                }
                break;
            }
            case UP: {
                if (row > top) {
                    matrix[row - 1][col] = num;
                    moveNext(row - 1, col, num + 1);
                } else {
                    top++;
                    state = States.RIGHT;
                    moveNext(row, col, num);
                }
                break;
            }
        }
    }
}
```