### 解题思路
换了好几种方法，都不能用，最后采用坐标法！还！是！不！行！
原来我一直在判断P（大写），而不是（p），怎么可以吃自己的卒子呢！
基本思路：
    1.先用双重for找到车的位置
    2.利用两个数组，实现横纵四个方向的遍历
   ** 注意：对查找的边界加以限定，以及每吃到一个卒子就要break掉，然后继续换方向遍历
**
### 代码

```c
int numRookCaptures(char** board, int boardSize, int* boardColSize){
    int sum=0;
    int dx[4]={1,-1,0,0},dy[4]={0,0,1,-1};
    for(int i=0;i<boardSize;i++){
        for(int j=0;j<boardSize;j++){
            if(board[i][j]=='R'){//先找到车的位置
                for(int k=0;k<4;k++){//利用数组dx，dy实现四个方向的遍历
                    int x=i,y=j;
                    while(true){
                        x+=dx[k];//横纵坐标步进
                        y+=dy[k];
                        if(x<0 || x>=boardSize || y<0 || y>=boardSize || board[x][y]=='B')
                            break;
                        if(board[x][y]=='p'){//一定要是小写p！
                            sum++;
                            break;
                        }
                    }
                    
                }
                return sum;
            }
        }
    }
    return 0;
}


```