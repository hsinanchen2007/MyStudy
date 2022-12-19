### 解题思路
JAVA 贪心算法 只交换偶数位即可

### 代码

```java
class Solution {
    public int minSwapsCouples(int[] row) {
        int result = 0;
        for (int i = 1; i < row.length; i += 2) {
            int x = (row[i - 1] & 1) == 1 ? row[i - 1] - 1 : row[i - 1] + 1;
            if (row[i] != x) {
                for (int j = i + 1; j < row.length; j++) {
                    if (row[j] == x) {
                        row[j] = row[i];
                        row[i] = x;
                        result++;
                    }
                }
            }
        }
        return result;
    }
}
```