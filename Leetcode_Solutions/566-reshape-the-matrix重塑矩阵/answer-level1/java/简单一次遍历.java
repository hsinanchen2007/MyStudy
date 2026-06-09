执行用时 :2 ms, 在所有 Java 提交中击败了96.97%的用户
内存消耗 :39.5 MB, 在所有 Java 提交中击败了96.54%的用户
```
class Solution {
    public int[][] matrixReshape(int[][] nums, int r, int c) {
        int size = nums.length*nums[0].length;
        if (size != r*c){
            return nums;
        }
        int [][] newnums = new int [r][c];
        int row = nums.length;int col = nums[0].length;
        for (int i = 0; i < r*c; i++){
           newnums[i/c][i%c] = nums[i/col][i%col];
        }
        return newnums;
    }
}
```
