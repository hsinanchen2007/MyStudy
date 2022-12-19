#  使用4个int right，down，left，up来记录当前要向这四个方向前进的优先级和前进的步数

时间复杂度：O(N), 一次遍历
空间复杂度：O(1)，常数个变量保存前进方向和步数

```
class Solution {

    //使用4个int right，down，left，up来记录当前要向这四个方向前进的优先级和前进的步数
    public List<Integer> spiralOrder(int[][] matrix) {
        List<Integer> result = new ArrayList<>();
        int row = matrix.length;
        if (row == 0) {
            return result;
        }
        int column = matrix[0].length;

        int size = row * column;
        //当前已经前进的步数
        int currentPosition = 0;
        //当前走到的行index
        int currentRow = 0;
        //当前走到的列index
        int currentColumn = 0;
        //当前走的圈数，right，down，left，up同时为0说明一圈已经走完，round++
        int round = 0;

        int right = column - 1 - round * 2;
        int down = row - 1 - round * 2;
        int left = column - 1 - round * 2;
        int up = row - 2 - round * 2;

        while (currentPosition < size) {
            result.add(matrix[currentRow][currentColumn]);
            //向右前进步数未完，继续向右前进
            if (right > 0) {
                currentColumn++;
                right--;
            } else if (down > 0) {
                //向下前进步数未完，继续向下前进
                currentRow++;
                down--;
            } else if (left > 0) {
                //向左前进步数未完，继续向左前进
                currentColumn--;
                left--;
            } else if (up > 0) {
                //向上前进步数未完，继续向上前进
                currentRow--;
                up--;
                if (up == 0) {
                    //right，down，left，up同时为0,一圈已经走完，round++,并重置下一圈四个方向要走的步数
                    round++;
                    right = column - round * 2;
                    down = row - 1 - round * 2;
                    left = column - 1 - round * 2;
                    up = row - 2 - round * 2;
                }
            }
            currentPosition++;
        }
        return result;
    }
}
```
