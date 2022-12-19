        int direction[8][2] = { {1,-1},{1,0},{1,1},{0,-1},{0,1},{-1,-1},{-1,0},{-1,1} };
        int m = grid[0].size();
        if (m == 0) { return -1; }
        if (grid[0][0] == 1) { return -1; }
        if (m == 1) { return 1; }

        queue<pair<int,int>> res ;
        res.push(make_pair<int,int>(0,0));
        int pathlen = 0;
        while (!res.empty()) {
            int size = res.size();
            pathlen++;

            while (size-- > 0) {
                pair<int, int> cur = res.front();
                res.pop();
                int cr = cur.first,cc = cur.second;
                grid[cr][cc] = 3;

                for (int i = 0; i < 8; i++) {
                    int nr = cr + direction[i][0], nc = cc + direction[i][1];
                    if (nr < 0 || nr >= m || nc < 0 || nc >= m || grid[nr][nc] >= 1) {
                        continue;
                    }
                    if ((nr == m-1) && (nc == m-1)){
                        return pathlen + 1;
                    }
                    res.push(make_pair(nr,nc));
                    grid[nr][nc] = 2;
                }
            }
        }

        return -1;
    }