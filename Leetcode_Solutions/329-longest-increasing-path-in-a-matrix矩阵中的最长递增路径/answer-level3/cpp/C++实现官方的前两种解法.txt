方法一：朴素的深度优先(无法通过)
```

class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        longestPath1.clear();
        longestPath2.clear();
        if (matrix.size() == 0)
            return 0;

        width = matrix[0].size();
        height = matrix.size();

        for (int i = 0; i < matrix.size(); i++)
            for (int j = 0; j < matrix[0].size(); j++)
            {
                int loc = i * width + j;
                dfs(matrix, i, j);
            }


        return longestPath1.size()+ longestPath2.size()-1;
    }

private:
    int width;
    int height;


    int depth1;
    int depth2;

    set<int> path1;
    set<int> path2;

    set<int> longestPath1;
    set<int> longestPath2;


    void dfs(vector<vector<int>>& matrix, int row, int col)
    {
        //先找小后找大，两端dfs
        set<int> visited;//存储一维坐标i*N+j
        depth1 = depth2 = 0;


        path1.clear();
        path2.clear();

        set<int> path;

        //小端
        dfs1(matrix, row, col, 1, path);

        //大端
        dfs2(matrix, row, col, 1, path);


        if (path1.size() + path2.size() > longestPath1.size() + longestPath2.size())
        {
            longestPath1 = path1;
            longestPath2 = path2;
        }

    }

    //递减的dfs
    void dfs1(vector<vector<int>>& matrix, int row, int col, int depth, set<int>& path)
    {
        if (row > -1 && col > -1 && row < height && col < width)
        {
            int loc = row * width + col;
            
            path.insert(loc);


            int flag = 0;

            if (row - 1 > -1 && path.count((row - 1) * width + col) == 0 && matrix[row - 1][col] < matrix[row][col])
            {
                dfs1(matrix, row - 1, col, depth + 1, path);
                flag++;
            }


            if (row + 1 < height && path.count((row + 1) * width + col) == 0 && matrix[row + 1][col] < matrix[row][col])
            {
                dfs1(matrix, row + 1, col, depth + 1, path);
                flag++;
            }


            if (col - 1 > -1 && path.count(row * width + col - 1) == 0 && matrix[row][col - 1] < matrix[row][col])
            {
                dfs1(matrix, row, col - 1, depth + 1, path);
                flag++;
            }


            if (col + 1 < width && path.count(row * width + col + 1) == 0 && matrix[row][col + 1] < matrix[row][col])
            {
                dfs1(matrix, row, col + 1, depth + 1, path);
                flag++;
            }

            //终端节点
            if (flag == 0)
            {
                if (depth > depth1)
                {
                    depth1 = depth;
                    path1 = path;
                }

            }

            path.erase(loc);
        }
    }

    //递增的dfs
    void dfs2(vector<vector<int>>& matrix, int row, int col, int depth, set<int>& path)
    {
        if (row > -1 && col > -1 && row < height && col < width)
        {
            int loc = row * width + col;

            path.insert(loc);


            int flag = 0;

            if (row - 1 > -1 && path.count((row - 1) * width + col) == 0 && matrix[row - 1][col] > matrix[row][col])
            {
                dfs2(matrix, row - 1, col, depth + 1, path);
                flag++;
            }


            if (row + 1 < height && path.count((row + 1) * width + col) == 0 && matrix[row + 1][col] > matrix[row][col])
            {
                dfs2(matrix, row + 1, col, depth + 1, path);
                flag++;
            }


            if (col - 1 > -1 && path.count(row * width + col - 1) == 0 && matrix[row][col - 1] > matrix[row][col])
            {
                dfs2(matrix, row, col - 1, depth + 1, path);
                flag++;
            }


            if (col + 1 < width && path.count(row * width + col + 1) == 0 && matrix[row][col + 1] > matrix[row][col])
            {
                dfs2(matrix, row, col + 1, depth + 1, path);
                flag++;
            }

            //终端节点
            if (flag == 0)
            {
                if (depth > depth2)
                {
                    depth2 = depth;
                    path2 = path;
                }

            }

            path.erase(loc);
        }
    }
};


```
方法二：带缓存的深度优先遍历
```
class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {

        if (matrix.size() == 0)
            return 0;

        width = matrix[0].size();
        height = matrix.size();

        int ans = 0;
        vector<vector<int>> cache(height, vector<int>(width, 0));

        for (int i = 0; i < matrix.size(); i++)
            for (int j = 0; j < matrix[0].size(); j++)
               ans=max(ans,dfs(matrix, i, j, cache));
               
        return ans;
    }

private:
    int width;
    int height;
    const vector<vector<int>> dirs = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };

    int dfs(vector<vector<int>>& matrix, int row, int col, vector<vector<int>> &cache)
    {
        if (cache[row][col] != 0)
            return cache[row][col];

        for (auto d : dirs)
        {
            int _row = row + d[0];
            int _col = col + d[1];
            if (_row >= 0 && _row < height && _col >= 0 && _col < width&& matrix[row][col]<matrix[_row][_col])
                cache[row][col] = max(dfs(matrix, _row, _col, cache), cache[row][col]);
        }

        return ++cache[row][col];
    }
    int max(int a, int b)
    {
        return a > b ? a : b;
    }
};
```

动态规划以后再写了。。。。然后才发现leetcode的时间排名有待更新，高排名的算法现在复制下来运行排名掉下来了。