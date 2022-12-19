### 解题思路
有个性质，如果单看列，0开头的一列，所有的列都得一样，1开头的与其取反，不能保证化不了棋盘，枚举一下，最终的棋盘，第一列开头是0还是1，找不在对应位置上的元素，除以2，取这两种情况最小的，行也是如此，因为行变换和列变换是正交的。N是奇数要特判一下，这块有点坑。。。。
代码写的真是玄学，习惯一直不好，瞎写
### 代码

```cpp
class Solution {
public:
    int movesToChessboard(vector<vector<int>>& board) {
        int sumt=0;
        int sum=0;
        //*
        for(int j=0; j<board[0].size(); j++)
        sumt+=board[0][j];
for(int i=0; i<board.size(); i++){
    sum=0;
    for(int j=0; j<board[i].size(); j++)
        sum+=board[i][j];
    if(sum>=board.size()/2+1+board.size()%2)
        return -1;
}
for(int j=0; j<board.size(); j++)
        sum+=board[j][0];
for(int i=0; i<board[0].size(); i++){
    sum=0;
    for(int j=0; j<board.size(); j++)
        sum+=board[j][i];
    if(sum>=board.size()/2+1+board.size()%2)
        return -1;
}
for(int i=0; i<board.size()-1; i++){
    for(int j=0; j<board[i].size(); j++){
        if(board[i][0]!=board[i+1][0]){
            if(board[i][j]==board[i+1][j])
                return -1;
        }
        if(board[i][0]==board[i+1][0]){
            if(board[i][j]!=board[i+1][j])
                return -1;
        }
    }
}
for(int i=0; i<board[0].size()-1; i++){
    for(int j=0; j<board.size(); j++){
        if(board[0][i]!=board[0][i+1]){
            if(board[j][i]==board[j][i+1])
                return -1;
        }
        if(board[0][i]==board[0][i+1]){
            if(board[j][i]!=board[j][i+1])
                return -1;
        }
    }
}
int sum1=0;
int sum2=0;
int ans=0;
int q=0;
for(int i=0; i<board.size(); i++){
    if(board[i][0]==1)
        q++;
    else
        q--;
}
if(q<=0)
{for(int i=0; i<board.size(); i++){
    if(board[i][0]==0&&i%2==1)
        sum1++;
    if(board[i][0]==1&&i%2==0)
        sum1++;
}
}
if(q>=0)
{for(int i=0; i<board.size(); i++){
    if(board[i][0]==0&&i%2==0)
        sum2++;
    if(board[i][0]==1&&i%2==1)
        sum2++;
}}
if(q==0)
ans+=min(sum1,sum2)/2;
if(q<0)
ans+=sum1/2;
if(q>0)
ans+=sum2/2;
sum1=0;
sum2=0;
q=0;
for(int i=0; i<board.size(); i++){
    if(board[0][i]==1)
        q++;
    else
        q--;
}
if(q<=0){
for(int i=0; i<board[0].size(); i++){
    if(board[0][i]==0&&i%2==1)
        sum1++;
    if(board[0][i]==1&&i%2==0)
        sum1++;
}}
if(q>=0){
for(int i=0; i<board[0].size(); i++){
    if(board[0][i]==0&&i%2==0)
        sum2++;
    if(board[0][i]==1&&i%2==1)
        sum2++;
}}

if(q==0)
ans+=min(sum1,sum2)/2;
if(q<0)
ans+=sum1/2;
if(q>0)
ans+=sum2/2;
return ans;
    }
};
```