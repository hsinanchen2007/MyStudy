### 解题思路
1.检查相同字符是否重复出现，考虑采用map;
2.这题比较繁琐的部分在于三个条件的空间划分;
3.其余操作简单且一致，具体划分过程见代码。

### 代码

```cpp
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        map<char,int> rkey;
        map<char,int> ckey;
        for(int j=0;j<board.size();j++){
            for(int i=0;i<board[j].size();i++){
                if(board[j][i]-'0'>=0&&board[j][i]-'0'<=9)
                rkey[board[j][i]]++;
                if(rkey[board[j][i]]>1) return false;
            }
            rkey.erase(rkey.begin(),rkey.end());
        }
        for(int j=0;j<board[0].size();j++){
            for(int i=0;i<board.size();i++){
                if(board[i][j]-'0'>=0&&board[i][j]-'0'<=9){
                    ckey[board[i][j]]++;
                }
                if(ckey[board[i][j]]>1) return false;
            }
            ckey.erase(ckey.begin(),ckey.end());
        }
        for(int i=0;i<9;i+=3){
            for(int j=0;j<9;j+=3){
                map<char,int> mkey;
                for(int k=0;k<3;k++){
                    for(int d=0;d<3;d++){
                       if(board[i+k][j+d]-'0'>=0&&board[i+k][j+d]-'0'<=9){
                            mkey[board[i+k][j+d]]++;
                        }
                        if(mkey[board[i+k][j+d]]>1) return false;
                    }   
                }
                mkey.erase(mkey.begin(),mkey.end());
            }
        }
        return true;
    }
};
```