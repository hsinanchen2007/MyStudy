```
class Solution {
    /*
        根据数组的特点，每一行第一个负数位置记为pos，则下一行的第一个负数位置在0-pos中
        找到每行第一个负数位置后，该行中其后面所有元素均为负数，直接统计结果
    */
    public int countNegatives(int[][] grid) {
        int sum = 0;
        int m = grid.length;
        int n = grid[0].length;
        int pos = grid[0].length-1;

        for(int i=0; i<m; i++){
            for(int j=0; j<=pos; j++){
                if(grid[i][j] < 0){
                    sum += (n - j);
                    pos = j;
                    break;
                }
            }
        }
        return sum;
    }
}
```
