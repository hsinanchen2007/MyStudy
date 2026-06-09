```cpp
class Solution {
public:
    typedef pair<int, int> coor;
    int row, col, num;
    bool res;
    vector<pair<int, int>> direction{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    bool exist(vector<vector<char>>& board, string word) {
        /*
            状态: 
                int CurId     当前待匹配的字符
                coor CurCoor  当前待匹配的board坐标
                记录已经匹配的字符: 将所有匹配过的字符统一置为'-'
            转移:
                dfs 深度优先
                返回条件: 
                    待匹配字符越界
                    带匹配坐标越界
                    字符不匹配
            输出:
                如果最后一个字符,且匹配完成, 置res为true
        */
        res = false;
        row = board.size();
        if(row==0) return false;
        num = word.size();
        col = board[0].size();
        
        for(int i=0; i<row; ++i){
            for(int j=0; j<col; ++j){
                dfs(board, word, 0, {i, j});
                if(res) return res;
            }
        }
        return res;
    }
    
    void dfs(vector<vector<char>>& board, string &word, int CurId, coor CurCoor){
        if((CurId == num) || (CurCoor.first < 0) || (CurCoor.first == row) || (CurCoor.second < 0) || (CurCoor.second == col)) return;
        if(board[CurCoor.first][CurCoor.second] != word[CurId]) return;
        if(CurId == num-1) {
            res=true;
            return;
        }
        board[CurCoor.first][CurCoor.second] = '-';
        for(auto &t:direction){
            dfs(board, word, CurId+1, {CurCoor.first + t.first, CurCoor.second + t.second});
            if(res) return;
        }
        board[CurCoor.first][CurCoor.second] = word[CurId];
    }
};
```