### 解题思路
复制原数组，以复制数组为对照，for循环改变当前数组，竟然双100%
![微信截图_20200402110311.png](https://pic.leetcode-cn.com/70327ab39b2c9a6b032413d7583c7d9e1d820d4534057388621e2af36e18328c-%E5%BE%AE%E4%BF%A1%E6%88%AA%E5%9B%BE_20200402110311.png)


### 代码

```c
void gameOfLife(int** board, int boardSize, int* boardColSize){
    if(*boardColSize == 0 || boardSize == 0){
        return;
    }
    int c[boardSize][*boardColSize];
    int dx[] = {1,-1,0,0,1,-1,1,-1};
    int dy[] = {0,0,1,-1,1,-1,-1,1};
    for(int i=0;i<boardSize;i++){
        for(int j=0;j<(*boardColSize);j++){
            c[i][j] = board[i][j];
        }
    }
    for(int i=0;i<boardSize;i++){
        for(int j=0;j<(*boardColSize);j++){
            int count = 0;
            for(int k=0;k<8;k++){
                int x = i + dx[k];
                int y = j + dy[k];
                if(x<0 || y<0 || x>=boardSize || y>=(*boardColSize)){
                    continue;
                }
                if(c[x][y] == 1){
                    count++;
                }
            }
            if((c[i][j] == 0 && count == 3) || (c[i][j] == 1 && (count == 2 || count == 3))){
                board[i][j] = 1;
            }else{
                board[i][j] = 0;
            }
        }
    }
}
```