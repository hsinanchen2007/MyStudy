```
class Solution {
public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int mod = 1e9 + 7, n = board.size();
        board[0][0] = '0';
        board[n - 1][n - 1] = '0';
        vector<int> dx{-1, 0, -1}, dy{0, -1, -1};
        vector<vector<int>> dp_score(n, vector<int>(n, 0)), dp_num(n, vector<int>(n, 0));
        for(int i = 0; i < n; i ++){
            for(int j = 0; j < n; j ++){
                if(board[i][j] == 'X'){
                    dp_num[i][j] = -1;
                    dp_score[i][j] = -1;
                }
                else{
                    dp_score[i][j] = board[i][j] - '0';
                    dp_num[i][j] = 0; // 其实不需要做
                }
            }
        }
        dp_num[n - 1][n - 1] = 1;
        for(int i = n - 1; i >= 0; i --){
            for(int j = n - 1; j >= 0; j --){
                if(board[i][j] == 'X') continue;
                for(int k = 0; k < 3; k ++){
                    int x = i + dx[k], y = j + dy[k];
                    if(x < 0 || x >= n || y < 0 || y >= n) continue;
                    if(board[x][y] == 'X') continue;
                    int score = board[x][y] - '0', now_s = dp_score[i][j];
                    if(score + now_s > dp_score[x][y]){
                        dp_score[x][y] = score + now_s;
                        dp_num[x][y] = dp_num[i][j];
                    }
                    else if(score + now_s == dp_score[x][y]){
                        dp_num[x][y] = (dp_num[i][j] + dp_num[x][y] ) % mod;
                    }
                }
            }
        }
        for(auto dp:dp_score){
            for(auto d:dp){
                cout << d << " ";
            }
            cout << endl;
        }
        if(dp_num[0][0] > 0)
            return vector<int>{dp_score[0][0], dp_num[0][0]};
        return vector<int>{0, dp_num[0][0]};
    }
};
```
