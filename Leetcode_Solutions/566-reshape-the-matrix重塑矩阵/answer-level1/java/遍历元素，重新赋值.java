```
class Solution {
    public int[][] matrixReshape(int[][] nums, int r, int c) {
        int nr = nums.length;
        int nc = nums[0].length;
        if(nr*nc != r*c) return nums;
        int[][] res = new int[r][c];
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                res[i][j] = nums[(i*c+j)/nc][(i*c+j)%nc]; //➗模取余，重新赋值
            }
        }
        //或者单层循环for(int i=0; i<r*c;i++) res[i/c][i%c] = nums[i/nc][i%nc]
     return res;   
    }
}
```

代码块
```
