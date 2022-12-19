/**
 * Project:
 * Author : zhaozhen
 * Email  :
 * Date   : 2019/9/24
 * 
 * 解题思路:怎么想 怎么做
 * 
 */
```
public int[][] matrixReshape(int[][] nums, int r, int c) {
    if( r*c > nums.length*nums[0].length){
        return nums;
    }
    int m = 0;
    int n = 0;
    int[][] res = new int[r][c];
    for(int i = 0;i < nums.length;i++){
        for(int j = 0;j < nums[i].length;j++){
            res[m][n++] = nums[i][j];
            if(n == c){
                m++;
                n = 0;
            }
        }
    }
    return res;
}
```