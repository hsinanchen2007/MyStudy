```java
class Solution {
  public int numMagicSquaresInside(int[][] grid) {
        int r = grid.length, c = grid[0].length;

        int cnt = 0;
        for(int i = 0; i <= r-3; i++){
            for(int j = 0; j <= c-3; j++){
                if(isMagicSquare(i, j, grid)) {
                    cnt++;
                    
                }

            }
        }
        return cnt;
    }

    public boolean isMagicSquare(int i, int j, int[][]grid){
        int rowsum = grid[i][j] + grid[i+1][j] + grid[i+2][j];

        int duijiaoxian1 = grid[i][j] + grid[i+1][j+1] + grid[i+2][j+2];
        int duijiaoxian2 = grid[i][j+2] + grid[i+1][j+1] + grid[i+2][j];

        for(int k = i; k <= i+2; k++){
            int tmpHang = 0;

            for(int m = j; m <= j+2; m++){
                tmpHang += grid[k][m];

            }

            if(rowsum != tmpHang) return false;
        }

        for(int m = j; m <= j+2; m++){
            int tmpLie = 0;
            for(int k = i; k <= i+2; k++){
                tmpLie += grid[k][m];
            }
            if(tmpLie != rowsum) return false;
        }

        if(rowsum != duijiaoxian1 || rowsum != duijiaoxian2 ){
            return false;
        }
        
        //幻方中的数字需要从1到9
        int []tmp = new int[9];
        int index = 0;
        for(int k = i; k <= i+2; k++){
            for(int m = j; m <= j+2; m++){
                tmp[index] = grid[k][m];
                index++;
            } 
        }
        Arrays.sort(tmp);
        for(int kk = 0; kk < tmp.length; kk++){
            if(tmp[kk] != kk+1) return false;
        }
        return true;

    }

}
```