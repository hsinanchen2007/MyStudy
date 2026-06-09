### 解题思路
复制数组解法，本来用Arrays的copy方法，但是用来复制二维数组只是复制了个引用

### 代码

```java
class Solution {
    public void gameOfLife(int[][] board) {

        if(board.length==0) return;
        int h = board.length;
        int l = board[0].length;
        //int[][] ints = Arrays.copyOf(board, board.length);复制二维数组的引用
        int[][] ints = new int[h][l];
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < l; j++) {
                ints[i][j] = board[i][j];
            }
        }
        
        //定义方向
        int[][] dir =
                {
                        {1, 0},//上
                        {-1, 0},//下
                        {0, -1},//右
                        {0, 1},//左
                        {-1, -1},//左下
                        {1, -1},//左上
                        {1, 1},//右下
                        {-1, 1}//右上
                };

        for (int i = 0; i < h; i++) {
            for (int j = 0; j < l; j++) {
                //细胞状态
                int flag = ints[i][j];
                //记录周围活细胞数目
                int count = 0;
                for (int[] d : dir) {
                    int newDx = i + d[0];
                    int newDy = j + d[1];
                    if (newDx < 0 || newDx >= h || newDy < 0 || newDy >= l) continue;
                    if (ints[newDx][newDy] == 1) count++;

                }

                switch (flag) {
                    case 0:
                        if (count == 3) board[i][j] = 1;
                        break;
                    case 1:
                        if (count < 2 || count > 3) board[i][j] = 0;
                        break;
                    default:
                        break;
                }


            }
        }
    }
}
```