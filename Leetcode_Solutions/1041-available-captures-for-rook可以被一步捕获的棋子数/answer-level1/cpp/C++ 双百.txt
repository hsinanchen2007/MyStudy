### 解题思路
遍历找出车，然后考虑四个方向的离车最近的卒和象，遍历一遍即可

### 代码

```cpp
class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        int rx,ry,px1=-1,px2=8,py1=-1,py2=8,bx1=-1,bx2=8,by1=-1,by2=8;
        for(int i=0;i<8;i++)
         for(int j=0;j<8;j++)
             if(board[i][j]=='R'){
                 rx=i;
                 ry=j;
             }
        for(int i=0;i<8;i++){
            if(board[rx][i]=='p'){
                if(i<ry)py1=max(py1,i);
                if(i>ry)py2=min(py2,i);
            }
            if(board[i][ry]=='p'){
                if(i<rx)px1=max(px1,i);
                if(i>rx)px2=min(px2,i);
            }
            if(board[rx][i]=='B'){
                if(i<ry)by1=max(by1,i);
                if(i>ry)by2=min(by2,i);
            }
            if(board[i][ry]=='B'){
                if(i<rx)bx1=max(bx1,i);
                if(i>rx)bx2=min(bx2,i);
            }
        }
        return (px1>bx1)+(px2<bx2)+(py1>by1)+(py2<by2);
    }
};
```