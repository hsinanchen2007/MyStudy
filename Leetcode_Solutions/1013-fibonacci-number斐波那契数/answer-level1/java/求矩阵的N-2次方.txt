看了大多数评论，都是递归和交换居多，这里给出一种比较少人用的矩阵乘法，时间复杂度O(logN)
执行用时 : 1 ms, 在Fibonacci Number的Java提交中击败了74.58% 的用户
内存消耗 : 32.6 MB, 在Fibonacci Number的Java提交中击败了78.58% 的用户
```
class Solution {
    public int fib(int N) {
        if(N<1){
            return 0;
        }
        if(N==1||N==2){
            return 1;
        }
        int[][] base = {{1,1},{1,0}};
        int[][] res = matrixPower(base,N-2);
        return res[0][0] + res[1][0];
    }
    public int[][] matrixPower(int[][] m, int p){
        int[][] res = new int[m.length][m[0].length];
        for(int i=0; i<res.length; i++){
            res[i][i] = 1;
        }
        int[][] tmp = m;
        for(;p!=0; p>>=1){
            if((p&1)!=0){
                res = muliMatrix(res,tmp);
            }
            tmp = muliMatrix(tmp,tmp);
        }
        return res;
    }
    public int[][] muliMatrix(int[][] m1, int[][] m2){
        int[][] res = new int[m1.length][m2[0].length];
        for(int i=0; i<m1.length; i++){
            for(int j=0; j<m2[0].length; j++){
                for(int k=0; k<m2.length; k++){
                    res[i][j] += m1[i][k]*m2[k][j];
                }
            }
        }
        return res;
    }
}
```
