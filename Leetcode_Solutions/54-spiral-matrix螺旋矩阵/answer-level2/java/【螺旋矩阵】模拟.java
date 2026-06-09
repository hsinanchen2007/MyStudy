### 解题思路
直接模拟螺旋矩阵生成的过程：**右-->下-->左-->上**，一圈一圈由外向内遍历就可以了，注意动态更新边界。直接看代码应该比较容易理解。

### 代码

```java
class Solution {
    public List<Integer> spiralOrder(int[][] matrix) {
        if (matrix == null || matrix.length == 0) {
            return new ArrayList<>();
        }

        int m = matrix.length;
        int n = matrix[0].length;
        
        List<Integer> ans = new ArrayList<>();
        int sum = n * m;
        // 螺旋矩阵"螺旋"过程中的边界
        int left = 0, right = n - 1, top = 0, bottom = m - 1;
        while (sum > 0) {
            // 右
            for (int j = left; j <= right; j++) {
                if (sum > 0) {
                    ans.add(matrix[top][j]);
                    sum--;   
                }
            }
            top++;

            // 下
            for (int i = top; i <= bottom; i++) {
                if (sum > 0) {
                    ans.add(matrix[i][right]);
                    sum--;   
                }
            }
            right--;

            // 左
            for (int j = right; j >=  left; j--) {
                if (sum > 0) {
                    ans.add(matrix[bottom][j]);
                    sum--; 
                }  
            }
            bottom--;

             // 上
            for (int i = bottom; i >= top; i--) {
                if (sum > 0) {
                    ans.add(matrix[i][left]);
                    sum--;   
                }
            }
            left++;
        }
        return ans;
    }
}
```