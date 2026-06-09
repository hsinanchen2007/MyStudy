### 解题思路
此处撰写解题思路
广度优先搜索，遍历过的点值设为-1，不再考虑。
### 代码

```cpp
class Solution {
public:
    int row;
    int col;
    vector<vector<int>>grid;
    queue<pair<int,int>>path;
    void left(int x, int y) {
        if (x - 1 >= 0 && (this->grid[y][x - 1] == 4 || this->grid[y][x - 1] == 6 || this->grid[y][x - 1] == 1)) {
            this->path.push(pair<int,int>(x-1,y));
        }
    }
    void right(int x, int y) {
        if (x + 1 < this->col && (this->grid[y][x + 1] == 3 || this->grid[y][x + 1] == 5 || this->grid[y][x + 1] == 1)) {
            this->path.push(pair<int,int>(x+1,y));
        }
    }
    void up(int x, int y) {
        if (y - 1 >= 0 && (this->grid[y - 1][x] == 3 || this->grid[y - 1][x] == 4 || this->grid[y - 1][x] == 2)) {
            this->path.push(pair<int,int>(x,y-1));
        }
    }
    void down(int x, int y) {
        if (y + 1 < this->row && (this->grid[y + 1][x] == 5 || this->grid[y + 1][x] == 6 || this->grid[y + 1][x] == 2)) {
            this->path.push(pair<int,int>(x,y+1));
        }
    }
    bool hasValidPath(vector<vector<int>>& grid) {
        this->grid = grid;
        this->row = grid.size();
        this->col = grid[0].size();
        this->path.push(pair<int,int>(0,0));
        while(this->path.size()>0) {
            pair<int,int>cur = this->path.front();
            if(cur.first==this->col-1&&cur.second==this->row-1){
                return true;
            }
            this->path.pop();
            int val = this->grid[cur.second][cur.first];
            this->grid[cur.second][cur.first]=-1;
            switch(val) {
                case 1:
                    this->left(cur.first, cur.second);
                    this->right(cur.first, cur.second);
                    break;
                case 2:
                    this->up(cur.first, cur.second);
                    this->down(cur.first, cur.second);
                    break;
                case 3:
                    this->left(cur.first, cur.second);
                    this->down(cur.first, cur.second);
                    break;
                case 4:
                    this->down(cur.first, cur.second);
                    this->right(cur.first, cur.second);
                    break;
                case 5:
                    this->left(cur.first, cur.second);
                    this->up(cur.first, cur.second);
                    break;
                case 6:
                    this->down(cur.first, cur.second);
                    this->right(cur.first, cur.second);
                    break;
            }
        }
    return false;
    }
};
```