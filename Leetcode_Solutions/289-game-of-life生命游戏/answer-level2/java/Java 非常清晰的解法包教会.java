### 解题思路
**根据题目意思，我们只需要知道当前细胞状态和周围活细胞的个数就能更新当前细胞状态了**

### 1、循环拷贝临时数组。
### 2、循环获取当前细胞周围的活细胞个数。
### 3、根据周围活细胞的个数和自身状态更新自身下一次的状态。
### 代码

```java
class Solution {
     public void gameOfLife(int[][] board) {
        int m = board.length;
        int n = board[0].length;

        //1、定义临时二维数组并且拷贝原数组
        int[][] temp = new int[m][n];
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                temp[i][j] = board[i][j];
            }
        }
        //方向数组
        int[] dx = {0, 1, 0, -1, -1, -1, 1, 1};
        int[] dy = {1, 0, -1, 0, 1, -1, 1, -1};

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int liveCell = 0;
                for(int index=0;index<8;index++ ){
                    int x = i + dx[index];
                    int y = j + dy[index];

                    if(x < 0 || x >= m || y < 0 || y >= n)
                        continue;
                    //2、获取每个细胞周围的活细胞    
                    liveCell += temp[x][y] == 1 ? 1 : 0;
                }
                
                //3、根据周围活细胞的数量和原始状态更新当前细胞
                if(liveCell < 2 || liveCell > 3){
                    board[i][j] = 0;
                }else if(liveCell >=2 && temp[i][j] == 1){
                    board[i][j] = 1;
                }else if(liveCell == 3 && temp[i][j] == 0){
                    board[i][j] = 1;
                }
            }
        }
    }
}
```