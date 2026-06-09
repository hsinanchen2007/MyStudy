### 解题思路
对行·列·3x3矩阵分别处理
很笨的写法，仅供参考

### 代码

```cpp
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
       int i,j,k;
       char s;
       map<char,int>h;
       for(i=0;i<9;i++){
           h.clear();
          for(j=0;j<9;j++){
             s=board[i][j];
             if(s=='.') continue;
             if(h[s]==1) return false;
             else h[s]=1;
          }
       }
       for(i=0;i<9;i++){
           h.clear();
          for(j=0;j<9;j++){
             s=board[j][i];
             if(s=='.') continue;
             if(h[s]==1) return false;
             else h[s]=1;
          }
       }
       
       int x,y;
       for(i=0;i<9;i+=3){
           for(j=0;j<9;j+=3){
               h.clear();
               for(x=i;x<i+3;x++){
                   for(y=j;y<j+3;y++){
                       s=board[x][y];
                       if(s=='.') continue;
                       if(h[s]==1) return false;
                       else h[s]=1;
                   }
               }
           }
       }
    return true;
    }
};
```