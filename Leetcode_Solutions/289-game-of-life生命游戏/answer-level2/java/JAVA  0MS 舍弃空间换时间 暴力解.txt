### 解题思路
此处撰写解题思路
就是很普通的暴力解，遍历二维数组，再遍历以每个数字为中心的周围8个位置，统计周围的活细胞数量。
之后变化出下一轮周期的样子。

### 代码

```java
class Solution {
    public void gameOfLife(int[][] board) {
        int m = board.length;//二维数组的大小
        int n = board[0].length;//二位数组的大小
        if(m==0){
            return;//如果数组为空 则直接返回
        }
        int[][] board2 = new int[m][n]; //创建新的数组用以存放一个周期后的变化
        int[] dx = {0,1,1,1,0,-1,-1,-1};//因为是以某个左边为圆心，遍历周边8个坐标，所以对于中心坐标的变化是确定的
        int[] dy = {1,1,0,-1,-1,-1,0,1};
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){//遍历二维数组
                int cnt = 0;//纪录周边活细胞的个数
                for(int k=0;k<8;k++){//遍历以[i][j]为中心点的周边8个点
                    int x = i+dx[k];
                    int y = j+dy[k];
                    if(x < 0 || x >= m || y < 0 || y >= n){//超过边界直接跳出
                        continue;
                    }
                    if(board[x][y]==1){//活细胞数量有几个则cnt为几
                        cnt += 1;
                    }
                }
                if(cnt<=1 || cnt>3){//生命游戏规则推出活细胞数量少于等于1个或大于3个时，下一个周期[i][j]为死细胞=0
                    board2[i][j]=0;
                }else if(cnt == 2){//如果等于2则不变
                    board2[i][j]=board[i][j];
                }else{//剩下的情况无论怎样，下一轮周期都是活细胞=1
                    board2[i][j]=1;
                }
            }
        }
        for(int i=0;i<m;i++){//把经过一轮变化的二维数组重新复制给board 因为最后返回的是board数组
            for(int j=0;j<n;j++){
                board[i][j] = board2[i][j];
            }
        }
    }
}
```