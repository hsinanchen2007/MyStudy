### 解题思路
###按照题意写代码就行，一次的可捕获 ：东南西北四个方向 ，捕获到到一个就换方向，输出最多是4.

### 代码

```java
class Solution {
    public int numRookCaptures(char[][] board) {
        int[][] det={{-1,0},{1,0},{0,-1},{0,1}};

        int ans=0;
        for(int i=0;i<8;i++){
            for(int j=0;j<8;j++){
                if(board[i][j]=='R'){
                    for(int k=0;k<4;k++){//东西南北四个方向
                        int x=i;int y=j;
                        while(true){
                            x+=det[k][0];
                            y+=det[k][1];
                            if(x>=8||x<0||y>=8||y<0||board[x][y]=='B'){
                                break;
                            }
                            else if(board[x][y]=='p'){
                                ans+=1;
                                break;
                            }
                        }
                    
                }
                return ans;
            }
        }

    }
    return 0;
}
}
```