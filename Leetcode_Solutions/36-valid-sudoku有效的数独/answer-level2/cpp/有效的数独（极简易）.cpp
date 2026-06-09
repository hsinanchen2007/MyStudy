### 解题思路
特别特别简单的做法，适合初学者做法。
首先判断行与列的合法性（基本相同），最后判断9格一方块的合法性。
![1.png](https://pic.leetcode-cn.com/50046aac740eb7c29f9db70a10c76794a53a2dc24c74300811d0d9516429c594-1.png)

### 代码

```cpp
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) 
    {int x=0,i=0;
    for(x=0;x<9;x++){
        for(i=0;i<9;i++)
        {
            if (board[x][i]!='.')
            {for(int a=i+1;a<9;a++)
            {if (board[x][a]!='.'&&board[x][i]==board[x][a])
            return false;}
            }
        }}
        int y=0;
        for(y=0;y<9;y++){
        for(i=0;i<9;i++)
        {
            if (board[i][y]!='.')
            {for(int a=i+1;a<9;a++)
            {if (board[a][y]!='.'&&board[i][y]==board[a][y])
            return false;}
            }
        }}
for(x=0;x<9;x+=3)
{
    for(y=0;y<9;y+=3)
    {
      char shu[9];
      shu[0]=board[x][y];shu[1]=board[x][y+1];shu[2]=board[x][y+2];
      shu[3]=board[x+1][y];shu[4]=board[x+1][y+1];shu[5]=board[x+1][y+2];
      shu[6]=board[x+2][y];shu[7]=board[x+2][y+1];shu[8]=board[x+2][y+2];
      for(i=0;i<9;i++)
      {
            if (shu[i]!='.')
            {for(int a=i+1;a<9;a++)
            {if (shu[i]!='.'&&shu[i]==shu[a])
            return false;} 
      }
    }
}
}
        return true;
        
    }
};
```