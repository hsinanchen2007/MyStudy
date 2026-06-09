### 解题思路
此题目是一道综合问题。主要流程图为： 
先用DFS的判断连通图，在判断连通图的过程中，对感染区域和防火墙的理解应该是：感染区域就是空白地区数，利用set进行处理；而防火墙则是如果此病毒靠近某一个空白地区，就需要加装防火墙。

然后取出其中会感染最大区域的连通图，对其所有的病毒设置为-1,因为有了防火墙，所以他应该不会感染性了；

最后对这一轮具有感染性的区域进行扩散，扩散一轮即可。

### 代码

```cpp

class Solution
{
   public:
    int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    bool IsValid(int x, int y, vector<vector<int>>& grid)
    {
        if (x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size()) {
            return false;
        }
        return true;
    }
    int DFSGetLeftArry(int x, int y, int currentRound, vector<vector<int>>& grid, vector<pair<int, int>>& arryToDivide, set<pair<int, int>>& temp)
    {
        int ans = 0;
        arryToDivide.push_back(make_pair(x, y));
        grid[x][y] = currentRound + 1;
        for (int i = 0; i < 4; i++) {
            int cX = x + dir[i][0];
            int cY = y + dir[i][1];
            if (IsValid(cX, cY, grid)) {
                if (grid[cX][cY] == 0) {
                    temp.insert(make_pair(cX, cY));
                    ans++;
                } else if (grid[cX][cY] == currentRound) {
                    ans += DFSGetLeftArry(cX, cY, currentRound, grid, arryToDivide, temp);
                }
            }
        }
        return ans;
    }
    int GetConnectArry(int currentRound, vector<vector<int>>& grid, vector<pair<int, int>>& arryToDivide)
    {
        int leftArry = 0;
        int ans = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == currentRound) {
                    vector<pair<int, int>> tempArry;
                    set<pair<int, int>> temp;
                    int res = DFSGetLeftArry(i, j, currentRound, grid, tempArry, temp);
                    if (temp.size() > leftArry) {
                        leftArry = temp.size();
                        ans = res;
                        arryToDivide.clear();
                        arryToDivide.assign(tempArry.begin(), tempArry.end());
                    }
                }
            }
        }
        return ans;
    }
    void BfsColorGrid(int currentRound, vector<vector<int>>& grid)
    {
        queue<pair<int, int>> bfsQueue;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j] == currentRound) {
                    bfsQueue.push(make_pair(i, j));
                }
            }
        }
        while (!bfsQueue.empty()) {
            pair<int, int> currentNode = bfsQueue.front();
            bfsQueue.pop();
            for (int i = 0; i < 4; i++) {
                int cX = currentNode.first + dir[i][0];
                int cY = currentNode.second + dir[i][1];
                if (IsValid(cX, cY, grid) && grid[cX][cY] == 0) {
                    grid[cX][cY] = currentRound;
                }
            }
        }
    }
    int containVirus(vector<vector<int>>& grid)
    {
        int ans = 0;
        int currentRound = 1;
        vector<pair<int, int>> arryToDivide;
        do {
            arryToDivide.clear();
            ans += GetConnectArry(currentRound, grid, arryToDivide);
            for (int i = 0; i < arryToDivide.size(); i++) {
                grid[arryToDivide[i].first][arryToDivide[i].second] = -1;
            }
            currentRound++;
            BfsColorGrid(currentRound, grid);
        } while (!arryToDivide.empty());

        return ans;
    }
};
```