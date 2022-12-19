### 解题思路
前置校验 + 遍历方式
能用变量直接操作就不要用取余

### 代码

```java
class Solution {
    public int[][] matrixReshape(int[][] nums, int r, int c) {
        if (nums.length * nums[0].length != r * c) return nums;
        int[][] res = new int[r][c];
        int rLen = nums.length, cLen = nums[0].length;
        int i = 0, j = 0;
        for(int[] arr: nums) {
            for(int t : arr) {
                res[i][j] = t;
                j++;
                if(j == c) {
                    j = 0;
                    i++;
                }
            }
        }
        return res;
    }
}
```