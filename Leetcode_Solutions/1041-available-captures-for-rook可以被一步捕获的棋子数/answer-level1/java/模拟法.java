题目中“返回车能够在一次移动中捕获到的卒的数量”->即“车往一个方向移动只能捕获一个卒”
class Solution {
    public int numRookCaptures(char[][] board) {
      int x=0,y=0;
      /*白色车可行进的四个方向*/
      int[] dx={-1,0,1,0};
      int[] dy={0,1,0,-1};
      int count=0;    /*统计捕获卒的个数*/
      aa:
      for(int i=0;i<8;i++){
          for(int j=0;j<8;j++){
              if(board[i][j]=='R'){
                 x=i;         /*记录白色车的位置*/ 
                 y=j;
                 break aa;
              }              
          }
        }
        int sx,sy;
        for(int k=0;k<4;k++){    /*遍历白色车可行进的四个方向*/
            sx=x;
            sy=y;
            for(int step=1;;step++){
              sx=sx+dx[k];
              sy=sy+dy[k];
              if(sx<=0||sx>=8||sy<=0||sy>=8||board[sx][sy]=='B') break; /*到达棋盘的边缘或遇到白色象则终止该方向的前进*/
              if(board[sx][sy]=='p'){    /*遇到黑色卒，增加捕获次数，同时终止该方向的前进即一个方向只能捕获一个卒*/ 
                  count++;
                  break;
              }
            }
        }
        return count;
    }
}