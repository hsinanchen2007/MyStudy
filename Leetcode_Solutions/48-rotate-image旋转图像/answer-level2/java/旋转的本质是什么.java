### 解题思路
旋转的本质是 四个角依次顺时针交互
1,如果找出四个角之间的下角标之间的关系
2,两次for循环的中止条件

### 代码

```java
class Solution {
    public void rotate(int[][] matrix) {
        //旋转图像 四个角对角翻转 找规律题
        int len = matrix.length;
        
        //两个for循环
        for (int i = 0; i < len/2; i++) {
            for (int j = i; j < len - i - 1; j++) {
                int temp = matrix[i][j];
                matrix[i][j]  = matrix[len-j-1][i];
                matrix[len-j-1][i] = matrix[len-i-1][len-j-1];
                matrix[len-i-1][len-j-1] = matrix[j][len-i-1];
                matrix[j][len-i-1] = temp;
            }
        }
    }
}
```