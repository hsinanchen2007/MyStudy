回溯法
```cpp
class Solution {

private:
    int m = 0;
    int n = 0;
    const int d[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
    
    vector < vector<bool> > visit;

    bool inArea(int x, int y) {
        return (x >= 0) && (x < m) && (y >= 0) && (y <n );
    }

    // board: 2d char 
    // word: string 
    // index: 从board[x][y]开始, 寻找word[index, word.size()), 找到了返回true
    bool searchWord(const vector< vector<char> > &board, const string & word, int index, int x, int y) {

        if (index == word.size()-1)
            return board[x][y] == word[index];

        if (board[x][y] == word[index]) {
            visit[x][y] = true;
            for (int i = 0; i < 4; i++) {
                int newx = x + d[i][0];
                int newy = y + d[i][1];
                if (inArea(newx, newy) && !visit[newx][newy])
                    if (searchWord(board, word, index+1, newx, newy))
                        return true;
            }
            visit[x][y] = false;
        }
        return false;             
    }

public:
    bool exist(vector< vector<char> >& board, string word) {

        m = board.size();
        if (m == 0)
            return false;
        n = board[0].size();

        visit = vector< vector<bool>> (m, vector<bool>(n, false));

        for (int i = 0; i < m; i++) 
            for (int j = 0; j < n; j++) 
                if (searchWord(board, word, 0, i, j))
                    return true;
            
        return false;
        
    }
};
```