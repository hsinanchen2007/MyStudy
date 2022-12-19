利用曼哈顿距离特性，对每次递进1对走一步可以到的区域进行染色标记，直到染色完全输出当前走的步数。
注意全为0和全为1的特例


class Solution {
public:
    void paint(vector<vector<int>>& tmpG, int i, int j, int& m, int& n) {
        if(i+1<m) tmpG[i+1][j] = 1;
        if(j+1<n) tmpG[i][j+1] = 1;
        if(i-1>=0) tmpG[i-1][j] = 1;
        if(j-1>=0) tmpG[i][j-1] = 1;
    }
    
    int maxDistance(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int count = 0, dist = 0;
        
        auto tmpG = grid;
        vector<vector<int>> ifPaint(m, vector<int>(n));
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1) {
                    count++;
                    paint(tmpG, i, j, m, n);
                }
            }
        }
        grid = tmpG;
        if(count == m*n || count == 0) return -1;
        
        while(count != m*n) {
            count = 0;
            dist++;
            auto tmpG = grid;
            for(int i = 0; i < m; i++) {
                for(int j = 0; j < n; j++) {
                    if(grid[i][j] == 1) {
                        count++;
                        if(ifPaint[i][j] == 0) {
                            paint(tmpG, i, j, m, n);
                            ifPaint[i][j] = 1;
                        }
                    }
                    //else cout << i << " " << j << endl;
                }
            }
            grid = tmpG;
        }
        return dist;
    }
};