### 解题思路
跟官方比起太垃圾了，哈哈哈，实在是我自己笨，觉得官方的太长了，只能自己琢磨了

### 代码

```java
class Solution {
    public int maximalRectangle(char[][] matrix) {
        int result = 0;
        if (matrix.length == 0 || matrix == null) {
            return result;
        }
        int wid = 0, len = 0;
        int[] temp = new int[matrix[0].length];
        for (int i = 0; i < matrix.length; i++) {
            for (int j = 0; j < matrix[0].length; j++) {
                //虽然看着长，但是很好理解的，这一步只是将二维数组中对应的1转换为一维数组中的1的连续的个数
                //也相当于将这一题转换为84题来解了
                if ((i == 0 && matrix[i][j] == '1') || (i > 0 && ((matrix[i - 1][j] == '1' && matrix[i][j] == '1') || (matrix[i - 1][j] == '0' && matrix[i][j] == '1')))) {
                    temp[j]++;
                } else {
                    temp[j] = 0;
                }
            }
            //下面就是84题的解法，照搬了
            for (int j = 0; j < temp.length; j++) {
                if (j != temp.length - 1 && temp[j] <= temp[j + 1]) {
                    continue;
                }
                wid = temp[j];
                for (int k = j; k >= 0; k--) {
                    len = j - k + 1;
                    wid = Math.min(wid, temp[k]);
                    result = Math.max(result, len * wid);
                }
            }
        }
        return result;
    }
}
```