```
class Solution {
    //递归：
    public boolean stoneGame1(int[] piles) {
        return xian(piles, 0, piles.length - 1) > hou(piles, 0, piles.length - 1);
    }
    
    
    public int xian(int[] piles, int i, int j) {
        if(i == j) {
            return piles[i];
        }   
        
        return Math.max(piles[i] + hou(piles, i + 1, j), piles[j] + hou(piles, i, j - 1));
    }
    
    public int hou(int[] piles, int i, int j) {
        if(i == j) {
            return 0;
        }
        
        return  Math.min(xian(piles, i + 1, j), xian(piles, i, j - 1));
    }

    //两个二维数组
    public boolean stoneGame2(int[] piles) {
        int n = piles.length;
        int[][] xian = new int[n][n];
        int[][] hou  = new int[n][n];
        
        for(int i = 0; i < n; i++) {
            xian[i][i] = piles[i];
            //hou[i][j]  = 0;默认就是0
        }
            
        //dp只依靠左和下
        for(int k = n - 1; k > 0; k--){//此斜线上的个数
            for(int i = 0; i < k; i++) {//行变量
                int j = n - k;//列变量
                xian[i][j] = Math.max(piles[i] + hou[i + 1][j], piles[j] + hou[i][j - 1]);
                hou[i][j] = Math.min(xian[i + 1][j], hou[i][j - 1]);
                
            }
        }    
        
        return xian[0][n - 1] > hou[0][n - 1];
    }

    //两个一维数组
    public boolean stoneGame3(int[] piles) {
        int n = piles.length;
        int[] xian = new int[n];
        int[] hou  = new int[n];
        
        for(int i = 0; i < n; i++) {
            xian[i] = piles[i];
            //hou[i][j]  = 0;默认就是0
        }
            
        //dp只依靠左和下
        for(int k = n - 1; k > 0; k--){//此斜线上的个数
            for(int i = 0; i < k; i++) {//行变量
                int j = n - k;//列变量
                xian[j] = Math.max(piles[i] + hou[j], piles[j] + hou[j - 1]);
                hou[j] = Math.min(xian[j], hou[j - 1]);
                
            }
        }    
        
        return xian[n - 1] > hou[n - 1];
    }
}

```
