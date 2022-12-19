```
class Solution {
    public int[][] matrixReshape(int[][] nums, int r, int c) {
        if(nums.length * nums[0].length < r * c || r <= 0 || c <= 0){
            return nums;
        }
        
        int[][] result = new int[r][c];
        int numsR = 0, numsC = 0;
        for(int i = 0 ; i < r; i++){
            for(int j = 0; j < c; j++){
                if(numsC == nums[0].length){       //如果遍历到当前nums数组某一行的最后一个元素，将行numsR变量自加一指向下一行，同时列numsC置为0
                    numsR++; 
                    numsC = 0;
                }
                result[i][j] = nums[numsR][numsC];
                numsC++;
            }
        }
        return result;
    }
}
```
