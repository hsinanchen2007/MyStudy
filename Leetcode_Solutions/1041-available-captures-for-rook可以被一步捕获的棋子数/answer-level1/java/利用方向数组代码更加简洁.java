### 解题思路
本来想直接四个for循环暴力破解的，看了看答案可以用方向数组能让代码简单化，易于看懂。

首先是循环找到数组中的R，没有什么捷径，直接全部遍历.得到R的坐标[row][cow];
接着是设计一个方向数组
    int[] x = {1,0,-1,0};
    int[] y = {0,1,0,-1};
保证他们在同一个i时候只向一个方向移动，然后就是利用之前找到的坐标加上方向数组再加上步长j
    int movex = row+j*x[i];
    int movey = cow+j*y[i];
得到新的坐标，在判断是否为p。

注意！
该题只找四个方向上遇到的第一个p，找到后要break出循环，我们不需要该方向上的第二个p。
### 代码

```java
class Solution {
    public int numRookCaptures(char[][] board) {
        int row=0;
        int cow=0;
        int[] x = {1,0,-1,0};
        int[] y = {0,1,0,-1};
        for(int i=0;i<board.length;i++){
            for(int j=0;j<board[0].length;j++){
                if(board[i][j]=='R'){
                    row = i;
                    cow = j;
                    break;
                }
            }
        }
        int count=0;
        for(int i=0;i<4;i++){
            for(int j=0;j<8;j++){
                int movex = row+j*x[i];
                int movey = cow+j*y[i];
                if(movex<0||movex>7||movey<0||movey>7||board[movex][movey]=='B'){
                    break;
                }
                if(board[movex][movey]=='p'){
                    count++;
                    break;
                }
            }
        }
        return count;
    }
}
```