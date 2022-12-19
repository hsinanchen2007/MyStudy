由于是从左往右遍历，从上往下遍历，所以在算(i,j)的四个方向时，left和up可以来自其他点
right和down方向需要自己算，并且可以把沿途算出来的都进行更新
```
class Solution {
    public int[][][] dp;//0->up,1->left,2->down,3->right
    public int[][] map;
    public int orderOfLargestPlusSign(int N, int[][] mines) {
        int res = 0;
        dp = new int[N][N][4];
        map = new int[N][N];
        for(int i=0;i<mines.length;i++){
            int I = mines[i][0];
            int J = mines[i][1];
            if(I>=0&&I<N&&J>=0&&J<N){
                map[I][J] = 1;// 0 is fine
            }
        }
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                res = Math.max(res,updatePoint(i,j)); 
            }
        }
        return res;
        
    }
    public int updatePoint(int i,int j){
        //up和left方向使用dp数组里记录的
        if(map[i][j]==0){
            if(i>0){
                dp[i][j][0] = dp[i-1][j][0]+1;
            }else{
                dp[i][j][0] = 1;
            }
            if(j>0){
                dp[i][j][1] = dp[i][j-1][1]+1;
            }else{
                dp[i][j][1] = 1;
            }      
            //down和right方向需要自己计算
            if(dp[i][j][2]==0){
                int tmpI = i;
                while(tmpI<map.length){
                    if(map[tmpI][j]==1){
                        break;
                    }
                    tmpI++;
                }
                int count = tmpI-i;
                for(int index=i;index<tmpI;index++){
                    dp[index][j][2] = count--;
                }
            }
            if(dp[i][j][3]==0){
                int tmpJ = j;
                while(tmpJ<map.length){
                    if(map[i][tmpJ]==1){
                        break;
                    }
                    tmpJ++;
                }
                int count = tmpJ-j;
                for(int index=j;index<tmpJ;index++){
                    dp[i][index][3] = count--;
                }
            }
        }
        return Math.min(dp[i][j][0],Math.min(dp[i][j][1],Math.min(dp[i][j][2],dp[i][j][3])));
    }
}
```
