### 解题思路
num_left = matrix[len - i][left];//zuo
num_bottom = matrix[bottom][len-i];//xia
num_right = matrix[i][right];//you
num_top = matrix[top][i];//shang
然后循环赋值，向内圈收缩
最终得到结果

### 代码

```java
class Solution {
    public void rotate(int[][] matrix) {
        int len = matrix.length-1;
        int left = 0;
        int right = matrix.length-1;
        int top = 0;
        int bottom = matrix.length-1;
        while(top < bottom && left < right){
            for(int i = left; i < right; i++){
                int temp = matrix[len - i][left];//zuo
                matrix[len - i][left] = matrix[bottom][len-i];//xia
                matrix[bottom][len-i] = matrix[i][right];//you
                matrix[i][right] = matrix[top][i];//shang
                matrix[top][i] = temp;
            }
            left++;
            right--;
            top++;
            bottom--;
        }
    }
}
```