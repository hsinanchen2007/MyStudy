### 解题思路
充分利用int的长度保存计算后的存活。
利用int 第二位bit保存计算后的状态。
0x11 代表当前活，计算后也是活
0x01代表计算后为死
0x10代表计算后为活
0x00代表计算后依旧为死
吐槽一句，java的内存消耗无法双百呀。
### 代码

```java
class Solution {
    public void gameOfLife(int[][] board) {
        if (board.length==0)return;

        int dx[] = {-1,  0,  1, -1, 1, -1, 0, 1};//建立一个数组代表统计时，周边的位置。
        int dy[] = {-1, -1, -1,  0, 0,  1, 1, 1};//建立一个数组代表统计时，周边的位置。

        for (int i=0;i<board.length;i++){
            for (int j=0;j<board[0].length;j++){
                int count=0;
                for(int k = 0; k < 8; k++) {
                    int nx = i + dx[k];
                    int ny = j + dy[k];
                    if(nx >= 0 && nx < board.length && ny >= 0 && ny < board[0].length) {
                        count += (board[nx][ny]&1); // 只累加最低位
                    }
                }
                //利用int 第二位保存计算后的结果，0x11 代表当前活，计算后也是活
                //0x01代表计算后为死，0x10代表计算后为活。0x00代表计算后依旧为死
                board[i][j] = board[i][j]==1?(count<2?1:count>3?1:3):(count==3?2:0);
            }
        }
        for (int i=0;i<board.length;i++){
            for (int j=0;j<board[0].length;j++){
                board[i][j]=board[i][j]>>1;//位移1位更新状态
            }
        }
    }

}
```