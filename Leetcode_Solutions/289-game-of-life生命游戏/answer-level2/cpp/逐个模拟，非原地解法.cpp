class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        vector<vector<int > > ans;
        int n = board.size();
        int m = board[0].size();
        int dx[] = {-1,-1,0,1,1,1,0,-1};
        int dy[] = {0,1,1,1,0,-1,-1,-1};
        vector<int> ansi;
        for(int i = 0;i < n;i++)
        {
            ansi.clear();
            for(int j = 0;j < m;j++)
            {
                int counta = 0;

                for(int u = 0;u < 8;u++)
                {
                    int x = i + dx[u];
                    int y = j + dy[u];
                    if(x < 0|| x >= n || y < 0 || y >= m)   continue;

                    if(board[x][y] == 1)    counta++;
                }
                if(board[i][j] == 0)
                {
                    if(counta == 3)
                        ansi.push_back(1);
                    else ansi.push_back(0);
                }
                if(board[i][j] == 1)
                {
                    if(counta < 2)  ansi.push_back(0);
                    if(counta == 2 || counta == 3)
                        ansi.push_back(1);
                    if(counta > 3)  ansi.push_back(0);
                }
            }
            ans.push_back(ansi);
        }
        board = ans;
    }
};
逐行逐个处理，应用一个辅助vector ans