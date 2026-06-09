### 解题思路
根据题意判断即可

### 代码

```cpp
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<board.size();i++){
            map<char,int> mp;
            for(int j=0;j<board[0].size();j++)
                if(board[i][j]!='.')
                    if(mp[board[i][j]]>0)
                        return false;
                    else
                        mp[board[i][j]]++;
        }
        for(int j=0;j<board[0].size();j++){
            map<char,int> mp;
            for(int i=0;i<board.size();i++)
                if(board[i][j]!='.')
                    if(mp[board[i][j]]>0)
                        return false;
                    else
                        mp[board[i][j]]++;
        }
        for(int i=0;i<=6;i+=3)
            for(int j=0;j<=6;j+=3){
                map<char,int> mp;
                for(int x=0;x<3;x++)
                    for(int y=0;y<3;y++)
                        if(board[i+x][j+y]!='.')
                            if(mp[board[i+x][j+y]]>0)
                                return false;
                            else
                                mp[board[i+x][j+y]]++;
            }
        return true;
    }
};
```