### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int[][] flipAndInvertImage(int[][] A) {
        int size = A.length;
        int[][] result = new int[size][size];
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                result[i][size - 1 - j] = (A[i][j] == 0) ? 1 : 0;
            }
        }
        return result;
    }
}
```