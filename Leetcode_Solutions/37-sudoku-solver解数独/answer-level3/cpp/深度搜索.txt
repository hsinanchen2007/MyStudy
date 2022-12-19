### 解题思路
属于第二遍看不懂系列。。
执行用时 :64 ms, 在所有 C++ 提交中击败了22.90%的用户
内存消耗 :6.5 MB, 在所有 C++ 提交中击败了100.00%的用户
### 代码

```cpp
class Solution {
public:
    bool OK=false;
    char replace[10]={'0','1','2','3','4','5','6','7','8','9'};
    void solveSudoku(vector<vector<char>>& board) {
        int length=board.size();
        dfs(board,-1,length);     
    }
    // 深搜
    void dfs( vector<vector<char>>& board,int curLocation,int length)
    {
        curLocation++;
        if(curLocation>(length*length-1)) {OK=true;return;}
        int x=curLocation/length;
        int y=curLocation%length;
        if(board[x][y]=='.')
        {
            for(int data=1;data<11;data++)
            {
                if(OK) {break;}
                else if(data==10)
                {
                    board[x][y]='.';                    
                }
                else if(data<10&&check(board,replace[data],curLocation,length))
                {
                    board[x][y]=replace[data];
                    if(curLocation==(length*length-1)) OK=true;
                    dfs(board,curLocation,length);
                }
            }
        }
        else{
            dfs(board,curLocation,length);
        }
    }
    // 检查行、列、周边是否有相同数字
    bool check(vector<vector<char>>& board,char data,int curLocation,int length)
    {
        
        int x=curLocation/length;
        int y=curLocation%length;
        for(int i=0;i<length;i++)
        {
            if((i!=x&&board[i][y]==data)||(i!=y&&board[x][i]==data))
            {
                return false;
            }
        }
        int index=(3*(x/3)+(y/3)%3);
        int centerx=1+(index/3)*3;
        int centery=1+(index%3)*3;
        int dx[]={-1,-1,-1,0,0,0,1,1,1};
        int dy[]={-1,0,1,-1,0,1,-1,0,1};
        for(int k=0;k<9;k++)
        {
            if(((centerx+dx[k])!=x||(centery+dy[k])!=y)&&board[centerx+dx[k]][centery+dy[k]]==data) return false;
        }
        return true;
    }
};
```