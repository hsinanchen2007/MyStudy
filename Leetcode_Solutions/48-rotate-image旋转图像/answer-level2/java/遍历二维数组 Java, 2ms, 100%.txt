### 解题思路
1. 二维数组 遍历方式 改成 圆圈式的遍历，从最外圈遍历到最内圈
2. 每次遍历只往前推进一个数字，总共推进round次以及需要循环cycle次。 round = end - start, cycle = n / 2;

### 代码

```java
class Solution {
    public void rotate(int[][] matrix) {
        int n = matrix.length;
        int cur = matrix[0][0], temp;
        int start = 0, end = n - 1, i = 0, j = 0;
        int round = end - start, cycle = n / 2, direction = 1;
        while (cycle > 0) {
            if (direction % 2 == 1) {
                j = (direction == 1) ? j + 1 : j - 1;
            } else {
                i = (direction == 2) ? i + 1 : i - 1;
            }
            temp = matrix[i][j];
            matrix[i][j] = cur;
            cur = temp;
            if (j == end && i == start
                    || j == end && i == end
                    || j == start && i == end) {
                direction = (direction + 1) % 4;
            } else if (j == i) {
                round--;
                if (round == 0) {
                    cycle--;
                    i++;
                    j++;
                    start++;
                    end--;
                    round = end - start;
                }
                direction = (direction + 1) % 4;
                cur = matrix[i][j];
            }
        }
    }
}
```