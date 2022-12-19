### 解题思路
常规操作，找到R的位置，然后我这个R只能走四个方向，上下左右，用pair包装起来，走这四个方向，碰到了别的棋子就break因为挡着R的路了，碰到小p就加个1，直接break;

### 代码

```cpp
class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        size_t x,y;
        
        bool ok=false;
        for(size_t i=0;i<board.size();++i){
           for(size_t j=0;j<board[i].size();++j){
               if(board[i][j]=='R'){
                   x=i;
                   y=j;
                   ok=true;
                   break;
               }
           }
           if(ok)break;
       }
       vector<pair<int,int>>vp{{1,0},{0,1},{-1,0},{0,-1}};
       int num=0;
        for(auto val:vp){
            int x1=x;
            int y1=y;
            while(1){
                x1+=val.first;
                y1+=val.second;
                if(x1<0||y1<0||x1>=board.size()||y1>=board[0].size()){
                    break;
                }
               if(board[x1][y1]=='p'){++num;break;}
               else if(board[x1][y1]=='.')continue;
               else{
                   break;
               }
           
         }
        }
        return num;
    }
};
```