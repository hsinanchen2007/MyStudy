![image.png](https://pic.leetcode-cn.com/355212821e27d0cac8ad955573a39c15ae3c02be07c7da77137a23231a3fac6e-image.png)

这个版本做了些代码上优化，参考了很多大佬的代码，使用了“board[x][y] = '#';//标记路径被占用”设置和重置路径状态。
```
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        m = board.size();
        n = board[0].size();
        this->word = word;
        bool ret = false;
        
        for(int x = 0; x < m; x++)
        {
            for(int y = 0; y < n && !ret; y++)
            {
                ret = exist_detail(board, x, y, 0);
            }
        }

        return ret;
    }


    bool exist_detail(vector<vector<char>>& board, int x, int y, int pos)
    {  
        bool ret = false;

        if (x < 0 || x >= m || y < 0 || y >= n || pos >= word.length() || board[x][y] == '#')
        {
            return false;
        }

        char ctmp = word.at(pos);

        if (pos == word.length() - 1 && board[x][y] == ctmp)
        {
            return true;
        }
        
        if (board[x][y] == ctmp)
        {
            board[x][y] = '#';//标记路径被占用

            ret = exist_detail(board, x+1, y, pos+1) 
                || exist_detail(board, x-1, y, pos+1)
                || exist_detail(board, x, y+1, pos+1)
                || exist_detail(board, x, y-1, pos+1);

            board[x][y] = ctmp;//状态重置
        }

        return ret;
    }
private:

    int m;
    int n;
    string word;
};
```


这个版本属于为参考大佬代码，个人单独完成。对比之下，一个是visited造成内存增加，和getDir造成性能增加，其耗时和性能如下。
![image.png](https://pic.leetcode-cn.com/e8c0a25b0369727280d28fc3ed280872f4e1ad74f81d05daedf3fd20d5330f56-image.png)

```
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        m = board.size();
        n = board[0].size();
        this->word = word;
        vector<vector<bool>> visited(m, vector<bool>(n));

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                visited[i][j] = false;
            }
        }
        
        for(int x = 0; x < m; x++)
        {
            for(int y = 0; y < n; y++)
            {
                visited[x][y] = true;
                if (exist_detail(board, x, y, 0, visited))
                {
                    return true;
                }
                visited[x][y] = false;
            }
        }
        
        return false;
    }


    bool exist_detail(vector<vector<char>>& board, int x, int y, int pos, vector<vector<bool>>& visited)
    {  
        bool ret = false;
        vector<std::pair<int, int>> nextdir;

        if (x < 0 || x >= m || y < 0 || y >= n || pos >= word.length())
        {
            return false;
        }

        char ctmp = word.at(pos);

        if (pos == word.length() - 1 && board[x][y] == ctmp)
        {
            return true;
        }
        
        if (board[x][y] == ctmp)
        {
            getDir(x, y, nextdir, visited);

            for(int i=0;i<nextdir.size() && !ret;i++)//若是当前返回ok，暂停DFS搜索，也可以理解为剪枝。
            {
                auto nextJumpDir = nextdir[i];
                visited[nextJumpDir.first][nextJumpDir.second] = true;
                ret = exist_detail(board, nextJumpDir.first, nextJumpDir.second, pos+1, visited);
                visited[nextJumpDir.first][nextJumpDir.second] = false;
            }
        }

        return ret;
    }

    void getDir(int x, int y, vector<std::pair<int, int>>& dir, vector<vector<bool>>& visited)
    {
        if (y < n-1 && !visited[x][y+1])
            dir.push_back(pair<int, int>(std::make_pair(x, y+1)));
        if (y > 0 && !visited[x][y-1])
            dir.push_back(pair<int, int>(std::make_pair(x, y-1)));
        if (x < m-1 && !visited[x+1][y])
            dir.push_back(pair<int, int>(std::make_pair(x+1, y)));
        if (x > 0 && !visited[x-1][y])
            dir.push_back(pair<int, int>(std::make_pair(x-1, y)));
    }
private:

    int m;
    int n;
    string word;
};
```

