### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
 int get_cosum(int m,int n,int i,int j,vector<vector<int>>& board)
{
    int count=0;
    if(i<0 || i>m) return 0;
    if(j<0 || j>n) return 0;
    int left_1=i-1>-1?i-1:i;
    int right_1=j-1>-1?j-1:j;
    int left_2=i+1<m?i+1:i;
    int right_2=j+1<n?j+1:j;
    for(int k=left_1;k<left_2+1;k++)
    {
        for(int f=right_1;f<right_2+1;f++)
        {
            if(board[k][f]==1)
                count++;
        }
    }
    return board[i][j]==1?count-1:count;
}
void gameOfLife(vector<vector<int>>& board) {
    if(board.empty() || board.back().empty())
        return;
    vector<vector<int>> v{board};
int m=board.size(),n=board.back().size(),count=0;;
for(int i=0;i<m;i++)
{
    for(int j=0;j<n;j++)
    {
        if(board[i][j]==0)
        {
            count=get_cosum(m,n,i,j,v);
            if(count==3)
                board[i][j]=1;
        }
        else
        {
            count=get_cosum(m,n,i,j,v);
            if(count<2 || count >3)
                board[i][j]=0;
        }
        count=0;
    }
}
}
};
```