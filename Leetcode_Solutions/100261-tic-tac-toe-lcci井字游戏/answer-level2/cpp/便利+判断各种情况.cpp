### 解题思路
此处撰写解题思路
给出数组棋盘，要想有一方获胜共有三种情况：行相同，列相同，对角线相同，因此三次遍历，n行遍历，n列遍历，还有两条对角线。若没有获胜，是游戏继续还是结束，这个取决于棋盘中间是否有空格，因此可以设flag标志空格。
### 代码

```cpp
class Solution {
public:
    string zh(char ch){
        if(ch=='O')return "O";
        if(ch=='X')return "X";
        return "";
    }
    string tictactoe(vector<string>& board) {
        int n=board.size();
        int i,j;
        int flag=0;
        char ch;
        for(i=0;i<n;i++){
            ch=board[i][0];
            if(ch==' ')flag=1;
            else{
                for(j=1;j<n;j++){
                    if(ch!=board[i][j])break;
                }
                if(j==n)return zh(ch);
            }
        }
        for(i=0;i<n;i++){
            ch=board[0][i];
            if(ch==' ')flag=1;
            else{
                for(j=1;j<n;j++){
                    if(ch!=board[j][i])break;
                }
                if(j==n)return zh(ch);
            }
        }
        ch=board[0][0];
        if(ch==' ')flag=1;
        else{for(i=1;i<n;i++){
            if(ch!=board[i][i])break;
        }
        if(i==n)return zh(ch);
        }
        i=0;j=n-1;
        ch=board[i][j];
        if(ch==' ')flag=1;
        else{
            for(;i<n;i++,j--){
                if(ch!=board[i][j])break;
        }
        if(i==n)return zh(ch);
        }
        if(flag==1)return "Pending";
        else return "Draw";
    }
};
```