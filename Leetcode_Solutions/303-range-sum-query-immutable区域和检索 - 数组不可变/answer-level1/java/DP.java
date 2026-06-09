### 解题思路
二维数组缓存每个i,j和值，内存超时
看完官网,缓存从0->nums.length-1的sum和,针对sumRange:sums[j + 1] - sums[i];

### 代码

```java
class NumArray {

   int[][] matrix;

    int[] sums;

    // public NumArray(int[] nums) {
    // int n = nums.length;
    // matrix = new int[n][n];
    // for (int i = 0; i < n; i++) {
    // matrix[i][i] = nums[i];
    // for (int j = i + 1; j < n; j++) {
    // if (i <= j) {
    // matrix[i][j] = matrix[i][j - 1] + nums[j];
    // }
    //
    // }
    // }
    // }

    public NumArray(int[] nums) {
        sums = new int[nums.length + 1];
        for (int i = 0; i < nums.length; i++) {
            sums[i + 1] = sums[i] + nums[i];
        }
    }

    public int sumRange(int i, int j) {
        return sums[j + 1] - sums[i];
        // return matrix[i][j];
    }
}

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(i,j);
 */
```