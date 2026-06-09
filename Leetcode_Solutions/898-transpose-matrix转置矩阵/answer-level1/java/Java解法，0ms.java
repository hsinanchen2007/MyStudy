执行用时 : 0 ms , 在所有 Java 提交中击败了 100.00% 的用户
内存消耗 : 38.5 MB , 在所有 Java 提交中击败了 90.04% 的用户

### 代码

```java
class Solution {
    public int[][] transpose(int[][] A) {
        int height = A.length;
        int width = A[0].length;
        int[][] answer = new int[width][height];
        for (int i = 0; i < width; i++) {
            for (int j = 0; j < height; j++) {
                answer[i][j] = A[j][i];
            }
        }
        return answer;
    }
}
```