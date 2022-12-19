### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
    int x=0,y=0,cou=0;
    int dx[4]={0,1,0,-1};
    int dy[4]={1,0,-1,0};
    for(int i=0;i<8;i++)
    {
        for(int j=0;j<8;j++)
        {
            if(board[i][j]=='R')
           {
               x=i;
            y=j;
            break;
           } 
        }
    }
    for(int i=0;i<4;i++)
    {
        for(int ste=0;;ste++)
        {
            int ix=x+ste*dx[i];
            int iy=y+ste*dy[i];
            if(ix<0||ix>=8||iy<0||iy>=8||board[ix][iy]=='B')break;
            if(board[ix][iy]=='p'){
                cou++;
                break;
            }
        }
    }
    return cou;
    }
};
```