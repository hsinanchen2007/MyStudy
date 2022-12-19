### 解题思路
先找到行最小的坐标，然后判断他是不是列最小。

### 代码

```java
class Solution {
 public List<Integer> luckyNumbers (int[][] matrix) {
        List<Integer> res = new ArrayList<>();
        for (int i = 0; i < matrix.length; i++) {
            int min = getMin(matrix[i]);
            int max = 0;
            for (int j = 1; j < matrix.length; j++) {
                if (matrix[max][min] < matrix[j][min])
                    max = j;
            }
            if (i == max)
                res.add(matrix[max][min]);
        }
        return res;
    }

    private int getMin(int[] h){
        int min = 0;
        for (int i = 1; i < h.length; i++) {
            if (h[min] > h[i])
                min = i;
        }
        return min;
    }

}
```