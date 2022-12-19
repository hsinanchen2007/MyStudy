### 解题思路
模拟车的移动,碰见卒记录,并且break,遇到象直接break;

### 代码

```java
class Solution {
    public int numRookCaptures(char[][] board) {
        //找到车的坐标xBoard代表车的x坐标,yBoard代表是车的y坐标
        int xBoard = 0, yBoard = 0;
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                if (board[i][j] == 'R') {
                    xBoard = i;
                    yBoard = j;
                    break;
                }
            }
        }
        //定义四个方向顺序分别是上/左/下/右
        int[] direction = new int[]{-1, -1, 1, 1};
        int result = 0, xOrY;
        //四个方向进行寻找
        for (int i = 0; i < 4; i++) {
            //取出对应方向
            int d = direction[i];
            //进行标记,true是移动x,false是移动y
            boolean flag;
            //如果i % 2 == 0(说明方向是上或者下)说明是对xBoard进行移动,y不变
            //如果i % 2 != 0(说明方向是左或者右)说明是对yBoard进行移动,x不变
            if (i % 2 == 0) {
                xOrY = xBoard;
                flag=true;
            } else {
                xOrY = yBoard;
                flag=false;
            }
            while (true) {
                //进行移动
                xOrY = xOrY + d;
                //如果在边界内,就进行判断出来,边界外直接break;
                if (xOrY >= 0 && xOrY < 8) {
                    //取出对应坐标的值
                    char c =flag? board[xOrY][yBoard]:board[xBoard][xOrY];
                    //如果是'p'说明可以吃到result加1,并且跳出循环,因为碰到一个卒吃到已经是第一步了,
                    //后面即使有卒也已经不再是第一步吃掉了,所以直接break,
                    //象直接break
                    //如果都不是继续循环
                    if (c == 'p') {
                        result++;
                        break;
                    } else if (c == 'B') {
                        //如果是象直接break
                        break;
                    }
                } else {
                    //边界外部直接break
                    break;
                }
            }
        }
        return result;
    }
}
```