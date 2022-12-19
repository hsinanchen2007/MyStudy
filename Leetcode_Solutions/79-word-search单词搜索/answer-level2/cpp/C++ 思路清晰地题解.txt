### 解题思路
DFS深度搜索
注意小细节
一个是搜索时候不要走回头路 这里通过tmp暂时保存数值来做到
另一个是边界条件 注意>=0 并且搜索访问不能超过 size
另外就是要先检查这个点是不是目标值 然后再判断到没到头
要是相反的话 会跳过只右一个的情况 {{'a'}}

### 代码

```cpp
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        for(auto i = 0; i<board.size();i++)
        {
            for(auto j = 0; j<board[i].size();j++)
            {

                bool rs = DFS(board,word,0,i,j);

                if(rs)
                    return true;
            }
        }


        return false;
    }

private:
    bool DFS(vector<vector<char>>& board,string word,int index, int i, int j)
    {
        bool rs = false;
        //判断这个点对不对
        if(word[index]!=board[i][j])
            return false;
        //判断到没到头
        if(index == word.size()-1)
            return true;
        //当前值
        char tmp = board[i][j];
        //临时变量替换 防止 回头路
        board[i][j] = '0';

        //判断向上走
        if( i-1>=0)
        {
            rs = DFS(board,word,index+1,i-1,j);

            if(rs)
                return true;
        }

        //判断向右走
        if(j+1<board[0].size())
        {
            rs = DFS(board,word,index+1,i,j+1);

            if(rs)
                return true;
        }

        //判断向下走
        if( i+1<board.size())
        {
            rs = DFS(board,word,index+1,i+1,j);

            if(rs)
                return true;
        }

        //判断向左走
        if(j-1>=0)
        {
            rs = DFS(board,word,index+1,i,j-1);

            if(rs)
                return true;
        }

        board[i][j] = tmp;
        return rs;
    }
};
```