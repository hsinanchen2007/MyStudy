### 解题思路
1.遍历数组
2.每个数都会交换4个位置
3.定义退出条件

### 代码

```java
class Solution {
    public void rotate(int[][] matrix) {
        if (matrix == null || matrix.length <= 1) return;
        for (int i = 0; i < matrix.length; i++) {
            if (i >= matrix.length / 2) break;
            for (int j = i; j < matrix[i].length - 1; j++) {
                if (j >= matrix[i].length - 1 - i) break;
                int val = matrix[i][j];
                //找到当前数
                //交换4次
                int x = 0, y = 0, temp = 0;
                for (int time = 1; time <= 4; time++) {
                    if (time == 1) {
                        x = j;
                        y = matrix[i].length - 1 - i;
                        temp = matrix[x][y];
                        matrix[x][y] = val;
                        val = temp;
                    } else if (time == 2) {
                        x = matrix[i].length - 1 - i;
                        y = matrix[i].length - 1 - j;
                        temp = matrix[x][y];
                        matrix[x][y] = val;
                        val = temp;
                    } else if (time == 3) {
                        x = matrix[i].length - 1 - j;
                        y = i;
                        temp = matrix[x][y];
                        matrix[x][y] = val;
                        val = temp;
                    } else if (time == 4) {
                        matrix[i][j] = val;
                    }
                }
            }
        }
    }
}
```