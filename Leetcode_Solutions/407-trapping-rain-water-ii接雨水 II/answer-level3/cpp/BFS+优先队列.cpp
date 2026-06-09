### 解题思路
某个点能不能装水，就看最小的那个边界是不是大于当前点的高度，如果（历史上）最小的边界大于当前的边界，可以填满；
一维的接雨水边界就是两边，二维的接雨水边界是整个大圈，最后的结束条件队列为空。

### 代码

```cpp
class Solution {
public:
    int dir[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
    struct node{
        int x, y;
        int value;
        node(int iX, int iY, int iV) {
            x = iX;
            y = iY;
            value = iV;
        }
    };
    struct cmp{
        bool operator() (node a, node b) {
            return a.value > b.value;
        }
    };
    bool IsValied(vector<vector<int>>& heightMap, int x, int y) 
    {
        if (x >= heightMap.size() || x < 0 || y >= heightMap[0].size() || y < 0) {
            return false;
        }
        if (heightMap[x][y] != -1) {
            return true;
        }
        return false;
    }
    int BfsGetMaxWater(vector<vector<int>>& heightMap, priority_queue<node, vector<node>, cmp>& outsideMin)
    {
        int ans = 0;
        int maxH = -1;
        while(! outsideMin.empty()) {
            node currentNode = outsideMin.top();
            outsideMin.pop();
            maxH = max(currentNode.value, maxH);
            for (int i = 0; i < 4; i++) {
                int x = currentNode.x + dir[i][0];
                int y = currentNode.y + dir[i][1];
                if (IsValied(heightMap, x, y)) {
                    if (heightMap[x][y] < maxH) {
                        ans += (maxH - heightMap[x][y]);
                    }
                    outsideMin.push(node(x,y,heightMap[x][y]));
                    heightMap[x][y] = -1;
                }
            }
        }
        return ans;
    }
    int trapRainWater(vector<vector<int>>& heightMap) {
        if (heightMap.size() <= 2) {
            return 0;
        }
        priority_queue<node, vector<node>, cmp> outsideMin;
        int m = heightMap.size();
        int n = heightMap[0].size();
        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 || i == m - 1 || j == 0 || j == n - 1) {
                    outsideMin.push(node(i,j,heightMap[i][j]));
                    heightMap[i][j] = -1;
                }
            }
        }
        return BfsGetMaxWater(heightMap, outsideMin);
    }
};
```