### 解题思路
1. 从数组左上角（matrix[0][0]）开始循环读取，初始读取方向为向右；
2. 读取出某个位置的数据后，将该位数据清除，置为已读状态；
3. 尝试按照之前的读取方向读取下一个数据，若可读（数组未越界且不是已读状态），则读取下一位；
4. 若不满足上一个条件，则按照【右→下→左→上】的优先级，依次尝试读取下一个数据，若可读则读取下一位并更新读取方向；若都不可读，则结束；

### 代码

```java
class Solution {
    public List<Integer> spiralOrder(int[][] matrix) {
        List<Integer> result = new ArrayList<Integer>();
        if (null == matrix || 0 == matrix.length) return result;

        int i = 0, j = 0;
        int m = matrix.length;
        int n = matrix[0].length;
        int last = 0;//记录上一次方向 0-向右；1-向下；2-向左；3-向上
        while(true) {
            if (matrix[i][j] == Integer.MAX_VALUE) {
                break;
            }

            result.add(matrix[i][j]);
            matrix[i][j] = Integer.MAX_VALUE;
            
            //优先按照上一步的方向走
            if (0 == last && j + 1 < n && matrix[i][j+1] != Integer.MAX_VALUE) {
                //上一次向右，且能继续向右，则优先向右走
                j++;
                continue;
            } else if (1 == last && i + 1 < m && matrix[i+1][j] != Integer.MAX_VALUE) {
                //上一次向下，且能继续向下，则优先向下走
                i++;
                continue;
            } else if (2 == last && j - 1 >= 0 && matrix[i][j-1] != Integer.MAX_VALUE) {
                //上一次向左，且能继续左下，则优先向左走
                j--;
                continue;
            } else if (2 == last && j - 1 >= 0 && matrix[i][j-1] != Integer.MAX_VALUE) {
                //上一次向左，且能继续左下，则优先向左走
                j--;
                continue;
            } else if (3 == last && i - 1 >= 0 && matrix[i-1][j] != Integer.MAX_VALUE) {
                //上一次向上，且能继续上下，则优先向上走
                i--;
                continue;
            }

            //需要转向则按照【右→下→左→上】的优先级
            if (j + 1 < n && matrix[i][j+1] != Integer.MAX_VALUE) {
                j++;
                last = 0;
            } else if (i + 1 < m && matrix[i+1][j] != Integer.MAX_VALUE) {
                i++;
                last = 1;
            } else if (j - 1 >= 0 && matrix[i][j-1] != Integer.MAX_VALUE) {
                j--;
                last = 2;
            } else if (i - 1 >= 0 && matrix[i-1][j] != Integer.MAX_VALUE) {
                i--;
                last = 3;
            } else {
                break;
            }
        }

        return result;
    }
}
```