### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int[] spiralOrder(int[][] matrix) {
        if(matrix.length == 0 || matrix[0].length == 0){
            return new int[]{};
        }
        int up = 0;
        int bottom = matrix.length - 1;
        int left = 0;
        int right = matrix[0].length - 1;

        int size = matrix.length * matrix[0].length;
        int[] ans = new int[size];
        int cnt = 0;
        while(up <= bottom && left <= right){
            for(int i = left; i <= right; i++){
                ans[cnt++] = matrix[up][i];
            }
            if(cnt >= size){//这个判断是不是结束了，否则会数组越界
                break;
            }
            up++;
            for(int i = up; i <= bottom; i++){
                ans[cnt++] = matrix[i][right];
            }
            if(cnt >= size){
                break;
            }
            right--;
            for(int i = right; i >= left; i--){
                ans[cnt++] = matrix[bottom][i];
            }
            if(cnt >= size){
                break;
            }
            bottom--;
            for(int i = bottom; i >= up; i--){
                ans[cnt++] = matrix[i][left];
            }
            left++;
        }
        return ans;
    }
}
```