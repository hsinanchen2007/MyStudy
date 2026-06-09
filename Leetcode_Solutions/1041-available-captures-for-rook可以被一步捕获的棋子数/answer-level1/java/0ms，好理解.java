### 解题思路
这道题思路就是先找到车的位置，即为二维数组的两个下标记为(x,y)。
然后让车向四个方向移动：
向上移动即是x--,y不变，直到x减到0。
向下移动即是x++,y不变，直到x加到7。
向左移动即是y--,x不变，直到x减到0。
向右移动即是y++,x不变，直到x加到7。

### 代码

```java
class Solution {
    public int numRookCaptures(char[][] board) {
       int x = 0;
       int y = 0;
       int num = 0;
       boolean flag = true;
       //找到车的坐标
       for (int i = 0; flag && i < 8; i++){
           for (int j = 0; flag && j < 8; j++){
               if (board[i][j] == 'R'){
                   x = i;
                   y = j;
                   flag = false;
               }
           }
       }
       //x,y都要用，不能把值丢了，所以得用个临时值
       int temp;
       //上
       temp = x-1;
        while(temp > -1){
            if (board[temp][y] == 'B') break;
            if (board[temp][y] == 'p'){
                num += 1;
                break;
            }
            temp -= 1;
        }
        //下
        temp = x+1;
        while(temp < 8){
            if (board[temp][y] == 'B') break;
            if (board[temp][y] == 'p'){
                num += 1;
                break;
            }
            temp += 1;
        }
        //左
        temp = y-1;
        while(temp > -1){
            if (board[x][temp] == 'B') break;
            if (board[x][temp] == 'p'){
                num += 1;
                break;
            }
            temp -= 1;
        }
        //右
        temp = y+1;
        while(temp < 8){
            if (board[x][temp] == 'B') break;
            if (board[x][temp] == 'p'){
                num += 1;
                break;
            }
            temp += 1;
        }
        return num;
    }
}
```