```
class Solution {
    public int[] findDiagonalOrder(int[][] matrix) {
        if (matrix == null) return null;
        if (matrix.length == 0) return new int[]{};

        int size = matrix.length * matrix[0].length;
        int[] result = new int[size];
        int x = 0;
        int y = 0;
        boolean flag = true;    //设置flag为true向右上方遍历，反之向左下方遍历
        for (int i = 0; i < size; i++){
            result[i] = matrix[x][y];
            if (flag == true){ //向右上方移动
                x--;
                y++;
                //如果y越界，3->6的情况，y变为最右边，x转到下一行，这里x之前已经减1，此处要加2
                if (y > matrix[0].length - 1) {
                    y = matrix[0].length - 1;
                    x += 2;
                    flag = false;
                }
                //如果x越界，1->2的情况，x变为最上边，y转到下一列，即y++保持
                if (x < 0) {
                    x = 0;
                    flag = false;
                }
            }else{    //向左下方移动
                x++;
                y--;
                if (x > matrix.length - 1) {
                    x = matrix.length - 1;
                    y += 2;
                    flag = true;
                }
                if (y < 0) {
                    y = 0;
                    flag = true;
                }
            }
        }
        return result;
    }
}

```
