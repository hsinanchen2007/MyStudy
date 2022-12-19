### 解题思路
设置 2，3状态，2表示由死变活，3表示由活变死；在不更新的情况下，3和1 都是奇数，都是活，不影响后面细胞的判断，等所有细胞检查完了，再把每个2和3更新成1和0；

### 代码

```cpp
class Solution {
    int direct[8][2] = {
        {-1, 0}, //左
        {1, 0}, //右
        {0, 1}, //上
        {0, -1}, //下
        {-1, -1}, //左上
        {-1, 1}, //左下
        {1, -1}, //右上
        {1, 1} //右下
    };

    int judge(int cell_stat, int cell_aroud){
        //如果该细胞是活的
        if(cell_stat % 2){
            if(cell_aroud < 2 || cell_aroud > 3) cell_stat = 3; //3表示由活变死 
        }else{
            if(cell_aroud == 3) cell_stat = 2; //2表示由死变活
        }
        return cell_stat; 
    }
public:
    void gameOfLife(vector<vector<int>>& board) {
        int max_x = board.size(), max_y = board[0].size();
        for(int i = 0; i < max_x; i++){
            for(int j = 0; j < max_y; j++){
                int around_count = 0;
                for(int k = 0; k < 8; k++){
                    int x = i + direct[k][0];
                    int y = j + direct[k][1];
                    if(x >= 0 && x < max_x && y >= 0 && y < max_y){
                        if(board[x][y] % 2) around_count++;
                    }
                }
                board[i][j] = judge(board[i][j], around_count);
            }
        }
        //更新数组
        for(int i = 0; i < max_x; i++){
            for(int j = 0; j < max_y; j++){
                if(board[i][j] == 3) board[i][j] = 0; //3表示由活变死 
                if(board[i][j] == 2) board[i][j] = 1; //2表示由死变活
            }
        }
    }
};
```