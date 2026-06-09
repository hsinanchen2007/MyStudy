### 解题思路
模拟题，分别记录当前的上、右、下、左边界，依次填充完以后更新边界

### 代码

```java
class Solution {
    public int[][] generateMatrix(int n) {

        int left = 0, right = n - 1, up = 0, down = n - 1;
        int[][] ans = new int[n][n];
        int num = 1, nums = n * n;

        while (num <= nums){

            // 从左往右
            for (int j = left; j <= right; j ++){
                ans[up][j] = num ++;
            }
            up ++;

            // 从上往下
            for (int i = up; i <= down; i ++){
                ans[i][right] = num ++;
            }
            right --;

            // 从右往左
            for (int j = right; j >= left; j --){
                ans[down][j] = num ++;
            }
            down --;

            // 从下往上
            for (int i = down; i >= up; i --){
                ans[i][left] = num ++;
            }
            left ++;

        }

        return ans;

    }
}
```