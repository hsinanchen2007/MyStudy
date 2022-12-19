### 解题思路
1.遍历数组，用Ri,Rj存储‘R’的位置
2.上下左右四个方向分别查看是否在白象前有黑卒
### 代码

```cpp
class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        int Ri = -1,Rj = -1,res = 0;

        for(int i=0;i<8;i++){
            for(int j=0;j<8;j++){
                if(board[i][j] == 'R'){
                    Ri = i;
                    Rj = j;
                    break;
                }
            }
            if(Ri != -1)
                break;
        }

        //up
        for(int i = Ri-1;i>=0;i--){
            if(board[i][Rj] == 'B')
                break;
            if(board[i][Rj] == 'p'){
                res ++;
                break;
            }
        }
        //down
        for(int i = Ri+1;i<8;i++){
            if(board[i][Rj] == 'B')
                break;
            if(board[i][Rj] == 'p'){
                res ++;
                break;
            }
        }
        //left
        for(int j = Rj-1;j>=0;j--){
            if(board[Ri][j] == 'B')
                break;
            if(board[Ri][j] == 'p'){
                res ++;
                break;
            }
        }
        //right
        for(int j = Rj+1;j<8;j++){
            if(board[Ri][j] == 'B')
                break;
            if(board[Ri][j] == 'p'){
                res ++;
                break;
            }
        }
        
        return res;
    }
};
```