### 解题思路
简单遍历每一行，获取每一行最小数，然后比较当前列是不是最大数

### 代码

```java
class Solution {
    public List<Integer> luckyNumbers (int[][] matrix) {
        List<Integer> list = new ArrayList<>(matrix.length);
        int x = 0;
        for (int i = 0; i < matrix.length; i++) {
            for (int j = 0; j < matrix[i].length; j++) {
                if (matrix[i][j] < matrix[i][x]) x = j;
            }
            boolean isMax = true;
            for (int j = 0; j < matrix.length; j++) {
                if (matrix[j][x] > matrix[i][x]) {
                    isMax = false;
                    break;
                }
            }
            if (isMax) list.add(matrix[i][x]);
        }
        return list;
    }
}
```