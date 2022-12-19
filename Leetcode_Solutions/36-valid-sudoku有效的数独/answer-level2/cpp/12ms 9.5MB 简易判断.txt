### 解题思路
采用最简单易想的方法，先判断每行的合法性，再判断每列的合法性，最后判断每九宫格的合法性。
![image.png](https://pic.leetcode-cn.com/4c7c11499b05710301142680f2751e99ba31ec675ecf520538dfbe4f9ec0b3b8-image.png)

### 代码
```
class Solution 
{
public:
    bool isValidSudoku(vector<vector<char>>& board) 
    {
        //每一行非法检测
        for(int i=0;i<9;i++)
        {
            char Shell[10]={'a','a','a','a','a','a','a','a','a','a'};
            for(int j=0;j<9;j++)
            {
                if(board[i][j]=='.')continue;
                if( Shell[ board[i][j]-'0' ] == 'a' )
                    Shell[ board[i][j]-'0' ] = 'b';
                else return false;
            }   
        }
        //每一列非法检测
        for(int i=0;i<9;i++)
        {
            char Shell[10]={'a','a','a','a','a','a','a','a','a','a'};
            for(int j=0;j<9;j++)
            {
                if(board[j][i]=='.')continue;
                if( Shell[ board[j][i]-'0' ] == 'a' )
                    Shell[ board[j][i]-'0' ] = 'b';
                else return false;
            }   
        }
        //每一九格块非法检测
        //写法还可以进一步优化
        int x=0;
        int y=0;
        for(int i=0;i<3;i++)
        {
            x=i*3;
            for(int j=0;j<3;j++)
            {
                y=j*3;
                char Shell[10]={'a','a','a','a','a','a','a','a','a','a'};
                for(int k=0;k<3;k++)
                {
                    for(int l=0;l<3;l++)
                    {
                        if(board[x+k][y+l]=='.')continue;
                        if( Shell[ board[x+k][y+l]-'0' ] == 'a' )
                            Shell[ board[x+k][y+l]-'0' ] = 'b';
                        else return false;
                    }
                }

            }
        }
        return true;
    }
};
```

