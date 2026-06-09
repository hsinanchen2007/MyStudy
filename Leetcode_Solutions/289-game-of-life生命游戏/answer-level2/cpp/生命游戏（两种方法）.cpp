### 解题思路
**第一种：**
很容易理解，复刻一个二维向量，用于查询，而在原二维向量中进行修改。
程序如下：（以C++实现）

**第二种**
使用原地算法，对要修改的值进行特殊定义，最后将特殊定义的值修改为合法值，亦可解决该问题。
程序如下：（以JAVA实现）

### 代码

```C++ []
class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int I=board.size(),J=board[0].size();
        vector<vector<int>> a(I,vector<int> (J));
        //复刻
        for(int i=0;i<I;i++){
            for(int j=0;j<J;j++){
                a[i][j]=board[i][j];
            }
        } 
        //处理
        for(int i=0;i<I;i++){
            for(int j=0;j<J;j++){
                int sum=0;//计数器
                for(int p=-1;p<=1;p++){
                    for(int q=-1;q<=1;q++){
                        if(p==0&&q==0)continue;//跳过自己
                        int x=i+p,y=j+q;
                        if(x>=0&&x<I&&y>=0&&y<J&&a[x][y])
                            sum++;
                    }
                }
                if((sum<2||sum>3)&&a[i][j]==1)board[i][j]=0;//死亡
                else if(sum==3&&a[i][j]==0)board[i][j]=1;//复活
            }
        }
    }
};
```
```JAVA []
class Solution {
    public void gameOfLife(int[][] board) {
        int I=board.length,J=board[0].length;//数组的行数及列数
        for(int i=0;i<I;i++){
            for(int j=0;j<J;j++){
                int sum=0;//计数器
                for(int a=-1;a<=1;a++){
                    for(int b=-1;b<=1;b++){
                        if(a==0&&b==0)continue;//跳过自己
                        int x=i+a,y=j+b;
                        if(x>=0&&x<I&&y>=0&&y<J&&(board[x][y]==1||board[x][y]==-1))
                            sum++;
                    }
                }
                //判断死亡或复活
                if((sum<2||sum>3)&&board[i][j]==1)board[i][j]=-1;//死亡
                else if(sum==3&&board[i][j]==0)board[i][j]=2;//复活
            }
        }
        //修改标记值
        for(int i=0;i<I;i++){
            for(int j=0;j<J;j++){
                if(board[i][j]==-1)board[i][j]=0;
                else if(board[i][j]==2)board[i][j]=1;
            }
        }
    }
}
```
