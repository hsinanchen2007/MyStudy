### 解题思路
这题实质上是一个广度优先搜索的变种，因为搜索并不是一个树形结构，不能保证第一次到达某个节点就一定会大于第二次到达该节点的值，因此每次到达该节点的时候都需要判断当前的dp是否小于之前的值，如果小于，就需要将该节点重新压入队列里面进行BFS.

再说说这个题，要能够停下来，必须是到destination的时候撞墙，所以BFS只需要将那些从起始点出发能撞墙的点记录下来，然后不断地刷新dp值，直至遍历结束，遇到最小值为止。 距离就是起始点和终止点的坐标绝对值差值。

### 代码

```cpp
class Solution {
public:
vector<vector<int>> dir{{0,1},{0,-1},{-1,0},{1,0}};

struct dirNode {
    int x,y;
    dirNode(int inputX, int inputY) {
        x = inputX;
        y = inputY;
    }
};
struct node {
    int len;
	bool isVisited;
    node() {
        len = 10002;
        isVisited = false;
    }
};
bool IsNodeWall(vector<vector<int>>& maze, int line, int col)
{
    if (line < 0 || line >= maze.size()) {
        return true;
    }
    if (col < 0 || col >= maze[0].size()) {
        return true;
    }
    return maze[line][col] == 1  ? true : false;
}

void RefreshDpMap(vector<vector<int>>& maze, vector<vector<node>>& dp, vector<int>& start)
{
    queue<dirNode> BfsQueue;
    dp[start[0]][start[1]].isVisited = true;
    for (int i = 0; i < 4; i++) {
        dp[start[0]][start[1]].len = 0;
    }
    dirNode startNode(start[0], start[1]);
    BfsQueue.push(startNode);
    while(! BfsQueue.empty()) {
        for (int i = 0; i < 4; i++) {
            dirNode currentNode = BfsQueue.front();
			dirNode destNode = BfsQueue.front();
            while(! IsNodeWall(maze, destNode.x + dir[i][0], destNode.y + dir[i][1])) {
                destNode.x += dir[i][0];
                destNode.y += dir[i][1];
            }
			if (dp[destNode.x][destNode.y].len > abs(currentNode.x - destNode.x) + abs(currentNode.y - destNode.y) + dp[currentNode.x][currentNode.y].len) {
				dp[destNode.x][destNode.y].isVisited = false;
				dp[destNode.x][destNode.y].len = abs(currentNode.x - destNode.x) + abs(currentNode.y - destNode.y) + dp[currentNode.x][currentNode.y].len;
			}
            if (dp[destNode.x][destNode.y].isVisited) {
                continue;
            }
            dirNode insertNode(destNode.x, destNode.y);
            dp[destNode.x][destNode.y].isVisited = true;
            BfsQueue.push(insertNode);
        }
        BfsQueue.pop();
    }
}

int shortestDistance(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
    if (maze.empty()) {
        return -1;
    }
    int minDir = 10001;
    vector<vector<node>> dp(maze.size(), vector<node> (maze[0].size(), node()));
    RefreshDpMap(maze, dp, start);
	minDir = min(dp[destination[0]][destination[1]].len, minDir);
    if (minDir == 10001) {
        minDir = -1;
    }
    return minDir;
}
};
```