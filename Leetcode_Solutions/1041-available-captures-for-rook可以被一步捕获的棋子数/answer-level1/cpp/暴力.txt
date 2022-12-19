### 解题思路
目前只会暴力

### 代码

```cpp
class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
int tag=0;
int x=0,y=0;
for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
                if(board[i][j]=='R'){
                        x=i;
                        y=j;
                        break;
                }
        }
}
for(int a=x;-1<a;--a){
        if(board[a][y]=='B') break;
        if(board[a][y]=='p'){
                tag++;
                break;
        }

}
for(int a=x;a<8;++a){
        if(board[a][y]=='B') break;
        if(board[a][y]=='p'){
                tag++;
                break;
        }
}
  for(int a=x;-1<a;--a){
        if(board[x][a]=='B') break;
        if(board[x][a]=='p'){
                tag++;
                break;
        }
  }
for(int a=x;a<8;++a){
        if(board[x][a]=='B') break;
        if(board[x][a]=='p'){
                tag++;
                break;
        }
}
return tag;
    }
};
```