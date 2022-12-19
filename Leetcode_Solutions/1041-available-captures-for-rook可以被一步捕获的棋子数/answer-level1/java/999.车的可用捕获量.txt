### 解题思路
车的移动规则：一个方向，主边缘或颜色相反的卒
（1）确定R的位置
（2）利用i循环：
    左--i<x,j=y;右--i>x,j=y;上--i=x;j<y;下--i=x,j>y;
（3）先循环到p--resul++；先循环到B，结束循环。

### 代码

```java
class Solution {
    public int numRookCaptures(char[][] board) {
        int x=-1, y=-1;   //R坐标
        for(int i=0; i<board.length; i++){
            for(int j=0; j<board.length; j++){
                if(board[i][j]=='R'){
                    x=i;
                    y=j;
                    break;
                }
            }
        }

        int i, result = 0;
        //左边
        i=x-1;
        while(i>=0){
            if(board[i][y]=='p'){
                result++;
                break;
            }else if(board[i][y]=='B'){
                break;
            }
            i--;
        }
        //右边
        i=x+1;
        while(i<board.length){
            if(board[i][y]=='p'){
                result++;
                break;
            }else if(board[i][y]=='B'){
                break;
            }
            i++;
        }
        //上边
        i=y-1;
        while(i>=0){
            if(board[x][i]=='p'){
                result++;
                break;
            }else if(board[x][i]=='B'){
                break;
            }
            i--;
        }
        //下边
        i=y+1;
        while(i<board.length){
            if(board[x][i]=='p'){
                result++;
                break;
            }else if(board[x][i]=='B'){
                break;
            }
            i++;
        }
        return result;
    }
}
```