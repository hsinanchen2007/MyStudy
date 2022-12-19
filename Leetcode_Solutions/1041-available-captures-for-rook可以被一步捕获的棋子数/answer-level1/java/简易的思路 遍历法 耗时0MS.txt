### 解题思路
此处撰写解题思路
首先找出车在棋盘上的位置并记录，随后因为车只走直线，所以只用在车的运动轨迹是个十字。
我们只需挨个轨迹的遍历，遇到“象”停止，遇到“兵”停止且捕获数量加1
最后输出总的 代码一遍过的 没怎么修改内存消耗情况
### 代码

```java
class Solution {
    public int numRookCaptures(char[][] board) {
        int m = 0;
        int n = 0;
        int sum=0;
        char R = 'R';
        char B = 'B';
        char p = 'p';
        for(int i=0;i<8;i++){//找出车的位置并记录
            for(int j=0;j<8;j++){
                if(board[i][j]==R){
                    m=i;
                    n=j;
                    break;
                }
            }
        }
        for(int i=m;i<8;i++){//找出车在X轴上正方向可以捕获的兵数量
            if(board[i][n]==B){
                break;
            }else if(board[i][n]==p){
                sum+=1;
                break;
            }
        }
        for(int i=m;i>=0;i--){
            if(board[i][n]==B){//找出车在X轴上负方向可以捕获的兵数量
                break;
            }else if(board[i][n]==p){
                sum+=1;
                break;
            }
        }
        for(int j=n;j<8;j++){//找出车在Y轴上正方向可以捕获的兵数量
            if(board[m][j]==B){
                break;
            }else if(board[m][j]==p){
                sum+=1;
                break;
            }
        }
        for(int j=n;j>=0;j--){//找出车在Y轴上负方向可以捕获的兵数量
            if(board[m][j]==B){
                break;
            }else if(board[m][j]==p){
                sum+=1;
                break;
            }
        }
        return sum;//输出
    }
}
```