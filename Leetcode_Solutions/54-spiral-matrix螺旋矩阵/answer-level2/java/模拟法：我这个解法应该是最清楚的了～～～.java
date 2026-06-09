```java
class Solution {
    public List<Integer> spiralOrder(int[][] matrix) {
        List<Integer> ans = new LinkedList<>();
        if (matrix == null || matrix.length == 0) {
            return ans;
        }
        int R = matrix.length;
        int C = matrix[0].length;
        int num = R * C;
        int left = 0;
        int right = C - 1;
        int top = 0;
        int bottom = R - 1;
        while (num > 0) {
            // left -> right
            for (int j = left; j <= right && j < C && num > 0; ++j) {
                ans.add(matrix[top][j]);
                num--;
            }
            ++top;
            // top -> bottom
            for (int i = top; i <= bottom && i < R && num > 0; ++i) {
                ans.add(matrix[i][right]);
                num--;
            }
            --right;
            // right -> left
            for (int j = right; j >= left && j >= 0 && num > 0; --j) {
                ans.add(matrix[bottom][j]);
                num--;
            }        
            --bottom;
            // bottom -> top
            for (int i = bottom; i >= top && i >= 0 && num > 0; --i) {
                ans.add(matrix[i][left]);
                num--;
            }
            ++left;
        }
        return ans;
    }
}
```
