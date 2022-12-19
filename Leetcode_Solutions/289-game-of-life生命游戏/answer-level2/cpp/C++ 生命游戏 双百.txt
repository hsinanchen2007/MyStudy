### 解题思路
我们通过是否大于0来区别死亡和存活。
逐个遍历，假设遍历到`board[i][j]`，我们寻找`board[i][j]`8个位置存活数量，如果该位置的死亡或存活状态不变，则不做任何操作；如果由死亡变为存活，那么`board[i][j]`设为-1；存活变为死亡，则设为2；
处理完之后，在遍历一次，将2改为0，-1改为1
时间复杂度是O(mn),空间复杂度O(1)

### 代码

```cpp
class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
            int x,len1=board.size();
            if(len1==0) return;
            int len2=board[0].size();
            int tx[8]={1,-1,0,0,1,1,-1,-1};//八个位置
            int ty[8]={0,0,1,-1,-1,1,-1,1};
            for(int i=0;i<len1;i++)
            {
                for(int j=0;j<len2;j++)
                {
                    x=0;
                    for(int k=0;k<8;k++)
                        if(i+tx[k]>=0 && i+tx[k]<len1 && j+ty[k]>=0 && j+ty[k]<len2 && board[i+tx[k]][j+ty[k]]>0)//判断是否越界且大于0
                            x++;
                    if(board[i][j]==0 && x==3)
                        board[i][j]=-1;//死亡变存活，但当前还是死亡(-1<=0)
                    else if(board[i][j]==1 && (x<2 || x>3))
                        board[i][j]=2;//存活变死亡，但当前还是存活(2>0)
                }
            }
            for(int i=0;i<len1;i++)
                for(int j=0;j<len2;j++)
                    if(board[i][j]==-1) board[i][j]=1;
                    else if(board[i][j]==2) board[i][j]=0;
    }
};
```