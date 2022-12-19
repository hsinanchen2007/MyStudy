### 解题思路
分成四种情况，顺时针模拟

### 代码

```java
class Solution {
    public List<Integer> spiralOrder(int[][] matrix) {
        if (matrix.length == 0)
            return new ArrayList<>();
        List<Integer> ans = new ArrayList<>();
        int n = matrix.length, m = matrix[0].length;
        int[][] vis = new int[n][m];
        int i = -1, j = -1, cnt = 0, turn = 0;
        while (cnt < n*m) {
            if (turn == 0) {
                turn = 1;
                j++;
                i++;
                while (j < m && vis[i][j] == 0) {
                    vis[i][j] = 1;
                    ans.add(matrix[i][j++]);
                    cnt++;
                }
            } else if (turn == 1) {
                turn = 2;
                j--;
                i++;
                while (i < n && vis[i][j] == 0) {
                    vis[i][j] = 1;
                    ans.add(matrix[i++][j]);
                    cnt++;
                }
            } else if (turn == 2) {
                turn = 3;
                i--;
                j--;
                while (j >= 0 && vis[i][j] == 0) {
                    vis[i][j] = 1;
                    ans.add(matrix[i][j--]);
                    cnt++;
                }
            } else {
                turn = 0;
                j++;
                i--;
                while (i >= 0 && vis[i][j] == 0) {
                    vis[i][j] = 1;
                    ans.add(matrix[i--][j]);
                    cnt++;
                }
            }
        }
        return ans;
    }
}
```