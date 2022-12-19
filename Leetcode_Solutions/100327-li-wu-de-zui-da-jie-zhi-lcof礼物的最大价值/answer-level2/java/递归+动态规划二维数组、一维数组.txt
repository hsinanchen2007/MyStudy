dp(i,j) 表示从起点到[i,j]可以获得的最大糖果数量 
`dp(i, j) = max{dp(i - 1, j), dp(i, j - 1)} + grid[i][j]`

1. **根据这个写递归，超时了**
```
class Solution{


    int[][] dir = new int[][]{{1,0},{0,1}};
    int res = 0;
    public int maxValue(int[][] grid) {
        int M = grid.length -1;
        int N = grid[0].length - 1;
        getGift(grid, M, N,0, 0,0);
        return res;
    }
    public void getGift(int[][] grid, int M, int N, int i, int j, int tmp){

        tmp += grid[i][j];
        if(i == M && j == N){
            res = Math.max(res, tmp);
            return;
        }
        for(int[] d : dir){
            int x = i + d[0];
            int y = j + d[1];
            if(x < 0 || x > M || y<0 || y>N){
                continue;
            }else{
                getGift(grid, M, N, x, y, tmp);
            }
        }
    }
```

**2. 二维动态规划 有边界条件处理**
dp(i,j) 表示从起点到[i,j]可以获得的最大糖果数量
dp(i, j) = max{dp(i - 1, j), dp(i, j - 1)} + grid[i][j]
第一行的只能从左往右走，第一列的只能从上往下走
所以开始先初始化第一行与第一列
```
dp(0,0) = grid[0][0]
dp(0,i) = dp(0,i-1) + grid [0][i];
dp(i,0) = dp(i-1,0) + grid [i][0];
```


然后用转移方程写循环，最后返回dep[M][N]即可
```
  public int MaxValue(int[][] grid){
        int M = grid.length-1, N = grid[0].length-1;
        int[][] dep = new int[M+1][N+1];
        dep[0][0] = grid[0][0];
        for (int i = 1; i <=N; i++){
            dep[0][i] = dep[0][i-1] + grid[0][i];
        }
        for (int i = 1; i <=M; i++){
            dep[i][0] = dep[i-1][0] + grid[i][0];
        }

        for (int i = 1; i<=M; i++){
            for (int j = 1; j <=N; j++){
                dep[i][j] = Math.max(dep[i-1][j],dep[i][j-1])+grid[i][j];
            }
        }
        return dep[M][N];
    }
```


3. **二维动态规划 扩大了数组，使得边界情况也满足**
我们发现之前要处理边界情况，比较麻烦，如果把dp数组的纬度扩大一维，可以不用处理边界条件

```
    public int maxValue(int[][] grid){
        int M = grid.length, N = grid[0].length;
        int[][] dep = new int[M+1][N+1];
        for (int i = 1; i<=M; i++){
            for (int j = 1; j <=N; j++){
                dep[i][j] = Math.max(dep[i-1][j],dep[i][j-1])+grid[i-1][j-1];
            }
        }
        return dep[M][N];
    }
```


4. **一维动态规划 因为只要比较上一格和左边格子**
因为只需要比较左边和上边的数，所以替换成一维数组即可
```
    public int maxValue(int[][] grid){
        int M = grid.length, N = grid[0].length;
        int[] dep = new int[N+1];
        for (int i = 1; i<=M; i++){
            for (int j = 1; j <=N; j++){
                dep[j] = Math.max(dep[j],dep[j-1])+grid[i-1][j-1];
            }
        }
        return dep[N];
    }
```
