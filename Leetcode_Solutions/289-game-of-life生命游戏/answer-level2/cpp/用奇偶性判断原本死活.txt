### 解题思路
![image.png](https://pic.leetcode-cn.com/6875deef55a066341e63e5436dc06ffb97a3659a7a4cb922e10497fba94dce72-image.png)

### 代码

```cpp
class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) //用奇偶来区分原本死活
    {
        int row = board.size(), col = board[0].size();
        for (int i = 0; i < row; i++)
            for (int j = 0; j < col; j++)
            {
                //计算初始周围有几个死细胞
                int cnt = 0;
                if (j==0||(board[i][j-1]&1)==0) {cnt++;}
                if (j==col-1||(board[i][j+1]&1)==0) {cnt++;}
                if (i==0||(board[i-1][j]&1)==0) {cnt++;}
                if (i==row-1||(board[i+1][j]&1)==0) {cnt++;}
                if (i==0||j==0||(board[i-1][j-1]&1)==0) {cnt++;}
                if (i==row-1||j==col-1||(board[i+1][j+1]&1)==0) {cnt++;}
                if (i==row-1||j==0||(board[i+1][j-1]&1)==0) {cnt++;}
                if (i==0||j==col-1||(board[i-1][j+1]&1)==0) {cnt++;}
                //若原本是活的
                if (board[i][j] & 1)
                {
                    switch (cnt)
                    {
                        case 0:
                        case 1:
                        case 2:
                        case 3:
                        case 4: //情况3
                        case 7:
                        case 8: //情况1
                        board[i][j] = 3; //现在死了
                        break;
                        default:
                        board[i][j] = 1; //仍然活着
                    }
                }
                else //若原本是死的
                {
                    //计算初始周围有几个死细胞
                    switch (cnt)
                    {
                        case 5: //情况4
                        board[i][j] = 2; //活过来了
                        break;
                        default:
                        board[i][j] = 4; //还是死的
                    }
                }
            }
            for (int i = 0; i < row; i++)
                for (int j = 0; j < col; j++)
                    if (board[i][j] < 3) board[i][j] = 1;
                    else board[i][j] = 0;
    }
};
```