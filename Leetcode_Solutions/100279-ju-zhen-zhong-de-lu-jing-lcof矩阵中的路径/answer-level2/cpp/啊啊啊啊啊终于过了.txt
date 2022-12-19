### 解题思路
我吐了，内存占用200多m还100%，真是有够可笑的呢
![image.png](https://pic.leetcode-cn.com/93b1fff0a94ebb0087cdeffef1e99cac4c9a39a2c0b7fc5673a094698042a7b2-image.png)

### 代码

```cpp
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if(board.size()*board[0].size()<word.size() ) return false;
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[0].size();j++)
            {
                if(board[i][j]==word[0]) 
                {
                    if(f(board,i,j,word,0)) return true;
                }
            }
        }
        return false;
    }
private:
    char tmp;
    int di[4]={0,0,1,-1};
    int dj[4]={1,-1,0,0};
   
    bool  f(vector<vector<char>> board,int cur_i,int cur_j,string word,int index)
    {
        index++;
        if(index==word.size()) return true;
        vector<vector<char>> bd=board;
        tmp=bd[cur_i][cur_j];
        bd[cur_i][cur_j]='0';
        
        for(int i=0;i<4;i++)
        {
            int x=cur_i+di[i],y=cur_j+dj[i];
            if(x<0||y<0||x==bd.size()||y==bd[0].size()||bd[x][y]=='0'||bd[x][y]!=word[index]) continue;
            else
            {
                if(f(bd,x,y,word,index)) return true;
            }
            
        }
        bd[cur_i][cur_j]=tmp;
        return false;

    }
};
```