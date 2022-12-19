/**
 * Project:
 * Author : zhaozhen
 * Email  : 
 * Date   : 2019/10/12
 * 
 * 解题思路: 暴力循环 进行3*3 矩阵验证 
 * 
 * 注意：矩阵9个数字不同验证可以用hash进行 使用累加和为45也可以 但前提是必须过滤掉0和大于9的数字
 * 
 */
```
public int numMagicSquaresInside(int[][] grid) {
    int res = 0;
    for(int i = 0;i < grid.length - 2;i++){
        for(int  j = 0;j < grid[0].length - 2;j++){
            //判断右下角3X3

            //sum 是否相同
            boolean is_ok = true;
            //排除全是相同的值
            int[] same = new int[10];

            //对角线 sum和
            int sum = grid[i][j] + grid[i+1][j+1] + grid[i+2][j+2];
            if(sum != grid[i+1][j+1] + grid[i][j+2] + grid[i+2][j]){
                is_ok = false;
            }


            //每行
            if(is_ok)
            for(int ii = i;ii < i + 3;ii++){
                if(sum != grid[ii][j] + grid[ii][j + 1] + grid[ii][j +2]){
                    is_ok = false;break;
                }
                
                //过滤0 和 大于9的数字
                if((grid[ii][j] <= 0 || grid[ii][j] >= 10)||(grid[ii][j + 1] <= 0 || grid[ii][j + 1] >= 10) || (grid[ii][j + 2] <= 0 || grid[ii][j + 2] >= 10)){
                    is_ok = false;break;
                }

                //数字不同的验证 也可以累加和为45
                if(same[grid[ii][j]] == 0){
                    same[grid[ii][j]] = 1;
                }else{
                    is_ok = false;break;
                }
                if(same[grid[ii][j + 1]] == 0){
                    same[grid[ii][j + 1]] = 1;
                }else{
                    is_ok = false;break;
                }
                if(same[grid[ii][j +2]] == 0){
                    same[grid[ii][j + 2]] = 1;
                }else{
                    is_ok = false;break;
                }

            }

            // SUM(1 2 3 4 5 6 7 8 9) = 45

            //每一列
            if(is_ok)
            for(int jj = j;jj < j + 3;jj++){
                if(sum != grid[i][jj] + grid[i + 1][jj] + grid[i + 2][jj]){
                    is_ok = false;break;
                }
            }
            if(is_ok == true) res++;
        }
    }
    return res;
}
```