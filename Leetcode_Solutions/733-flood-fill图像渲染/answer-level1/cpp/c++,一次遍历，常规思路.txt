```
vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if (image.empty() || image[0].empty() ||
        sr < 0 || sc < 0 || sr >= image.size() || sc >= image[0].size() ||
        image[sr][sc] == newColor) {  //必须要判断一下是否原值和newColor是否相等，否则会出现死循环
            return image;
        }
        vector<vector<int>> dict({{0,1}, {-1,0},{0,-1}, {1,0}});
        queue<pair<int,int>> que;
        que.push(make_pair(sr, sc));
        int x,y, key = image[sr][sc];
        while (que.size()) {
            auto iter = que.front();
            que.pop();
            for (auto direc : dict) {
                x = iter.first + direc[0], y = iter.second + direc[1];
                if (x < 0 || y < 0 || x >= image.size() ||
                y >= image[0].size() || image[x][y] != key) {
                    continue;
                }
                que.push(make_pair(x,y));
                image[x][y]  = newColor;
            }
        }
        image[sr][sc] = newColor;
        return image;
    }
```
