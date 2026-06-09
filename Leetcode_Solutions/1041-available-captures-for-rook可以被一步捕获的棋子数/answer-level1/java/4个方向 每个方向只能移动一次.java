### 解题思路
找到R所在位置 然后对R在四个方向上进行移动
四个方向：上下左右 定义2个数组 
一个dx表示x方向移动 dx={-1,1,0,0} moveleft：x-1 moveright:x+1 moveup:x+0 movedown:x+0
一个dy表示x方向移动 dy={0,0,1,-1} moveleft：y+0 moveright:y+0 moveup:y+1 movedown:y-1
### 代码

```java
class Solution {
    public int numRookCaptures(char[][] board) {
        
        return getCntByMovingForDirction(getRPos(board),board);
    }
    private int[] getRPos(char[][] board){
        for(int i=0;i<board.length;i++){
            for(int j=0;j<board[i].length;j++){
                if(board[i][j]=='R'){
                    return new int[]{i,j};
                }
            }
        }
        return null;
    }
    /**
    **
    ** we have four direction,so define two arrays, one is the x's move(dx),the other one is y's move(dy)
    ** dx={-1,1,0,0} moveleft：x-1 moveright:x+1 moveup:x+0 movedown:x+0
    ** dy={0,0,1,-1} moveleft：y+0 moveright:y+0 moveup:y+1 movedown:y-1
    **/
    private int getCntByMovingForDirction(int[] pos,char[][]board){
        if(null==pos) return 0;
        int cnt=0;
        int[] dx={-1,1,0,0};
        int[] dy={0,0,1,-1};
        for(int d=0;d<dx.length;d++){
            int i=pos[0]+dx[d],j=pos[1]+dy[d];
            while(i>0&&j>0&&i<8&&j<8){
                
                if(board[i][j]=='.'){
                    i=i+dx[d];
                    j=j+dy[d];
                    continue;
                }
                if(board[i][j]=='B'){
                    break;
                }
                if(board[i][j]=='p'){
                    cnt++;
                    break;
                }
                
                
            }
        }
        return cnt;
    }
}
```