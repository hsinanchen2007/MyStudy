![image.png](https://pic.leetcode-cn.com/114a68d1089bab3302815eb0f40d6fce680ef770d0b7d1ff64f24765efbb73b0-image.png)

今天的题，题目虽长，但是好理解，一把过，心态就很舒服。没有废话，直接上代码。
直接按照题目的意思，顺着往下写就可以，列清楚生死之间的变化条件。
唯独要关注的就是，注意题目中的条件*“下一个状态是通过将上述规则同时应用于当前状态下的每个细胞所形成的”*，所以需要一个额外的临时矩阵，来存储更新后的值。讲的简短一点意思就是，**下一状态基于当前状态**。就这么多，看代码吧~
```
class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        vector<pair<int, int>> dir = {{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};//8个方向
        int m = board.size(), n = board[0].size();
        vector<vector<int>> temp_board = board;//新建临时矩阵，存储下一状态
        for(int i=0;i<m;i++){//挨个遍历，挨个计算当前细胞周围的活细胞数，并及时更新临时矩阵的值
            for(int j=0;j<n;j++){
                int count_one = 0;//存储8个方向上的活细胞数目
                for(auto d: dir){//计算8个方向的活细胞数目
                    int x = i + d.first;
                    int y = j + d.second;
                    if(x>=0 && x<m && y>=0 && y<n){
                        if(board[x][y]==1) count_one++;
                    }
                }
                //遍历的同时更新临时矩阵
                if(board[i][j]==1){//如果当前是活细胞
                    if(count_one<2){
                        temp_board[i][j] = 0;
                    }
                    else if(count_one==2 || count_one ==3){
                        temp_board[i][j] = 1;
                    }
                    else if(count_one>3){
                        temp_board[i][j] = 0;
                    }
                }
                else{//如果当前是死细胞
                    if(count_one==3){
                        temp_board[i][j] = 1;
                    }
                }
            }
        }
        board = temp_board;//更新当前矩阵
    }
};
```
