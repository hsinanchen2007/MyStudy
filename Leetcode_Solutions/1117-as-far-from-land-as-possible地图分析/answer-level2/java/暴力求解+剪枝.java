```
class Solution {
    public int maxDistance(int[][] grid) {
        int total_max = -1;boolean one = false;
        boolean zero = false;boolean juice=true;
        for (int i = 0; i < grid.length; i++) {
            for (int j = 0; j < grid[i].length; j++) {
                if(grid[i][j]==0){
                    one=true;
                    int val_min = 100000;
                    juice = true;
                    for (int k = 0; k < grid.length&&juice; k++) {
                        for (int l = 0; l < grid[k].length&&juice; l++) {
                            if(grid[k][l]==1)
                            {
                                zero=true;
                                int dis = (i>k?i-k:k-i) + (j>l?j-l:l-j);
                                val_min = val_min<dis?val_min:dis;
                                if(total_max!=-1&&val_min<total_max)
                                    juice=false;
                            }
                        }
                    }
                    total_max = total_max>val_min?total_max:val_min;
                }
            }
        }
        if(one==false||zero==false) return -1;
        else return total_max;
    }
}
```
别骂我，脑力有限，容易看懂！！！