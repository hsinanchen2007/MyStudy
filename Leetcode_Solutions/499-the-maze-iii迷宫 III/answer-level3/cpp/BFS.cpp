### 解题思路
BFS的一个拓展应用。**千万不要把搜索过程中的所有信息存储下来，只需要每次把更优的答案记录下来，然后再进行一次搜索，刷新dp信息就好**，和迷宫二类似，需要记录的变成了每次转折时候节点的信息(地图信息+长度))；每一次添加node也就是“BFS染色”的时候，要判断两个东西：长度是不是比上一次短，地图信息是不是按照字符串排序；但凡有一个条件不满足就需要重新刷新与其相关的节点信息，实质上这系列的题目就是在BFS染色的时候需要进行特殊判断。
最后一个特殊点就是需要使用一个node专门存储搜索途经目的节点时候的信息，每一次queue弹出来的时候，都需要对其进行刷新。

注意 **上下左右** 在dir数组里面的对应关系。。。。。

### 代码

```cpp
class Solution {
public:
	struct dpNode {
		string nodeStr;
		int length;
		dpNode() {
			nodeStr = "";
			length = 1000;
		}
	};
	struct node {
		int x;
		int y;
		node (int line, int col) {
			x = line;
			y = col;
		}
	};
	vector<vector<int>> nextDir{{1,0},{-1,0},{0,1},{0,-1}};
	vector<char> dirStr{'d','u','r','l'};
	
	int GetDistence(int holeX, int holeY, int nodeX, int nodeY)
	{
		return (abs(holeX - nodeX) + abs(holeY - nodeY));
	}
	
	bool RefreshNodeInfo(vector<vector<dpNode>>& dpVec, dpNode& resultsNode, int destX, int destY, node currentNode, char currentDir) {
		if (currentNode.x == destX && currentNode.y == destY) {
			return false;
		}
		int distence = GetDistence(destX, destY, currentNode.x, currentNode.y) + dpVec[currentNode.x][currentNode.y].length;
		if (resultsNode.length > distence) {
			resultsNode.length = distence;
			resultsNode.nodeStr = dpVec[currentNode.x][currentNode.y].nodeStr + currentDir;
		} else if (resultsNode.length == distence && resultsNode.nodeStr > (dpVec[currentNode.x][currentNode.y].nodeStr +  currentDir)) {
			resultsNode.nodeStr = dpVec[currentNode.x][currentNode.y].nodeStr + currentDir;
		} else {
			return false;
		}
		
		return true;
	}
	bool IsNodeWall(vector<vector<int>>& maze, int x, int y) 
	{
		if (x >= maze.size() || x < 0 || y >= maze[0].size() || y < 0) {
			return true;
		}
		return (maze[x][y] == 1);
	}
    string findShortestWay(vector<vector<int>>& maze, vector<int>& ball, vector<int>& hole) {
		vector<vector<dpNode>> dpVec(maze.size(), vector<dpNode> (maze[0].size(), dpNode()));
		dpNode resultsNode;
		dpVec[ball[0]][ball[1]].length = 0;
		queue<node> BFSqueue;
		node tempNode(ball[0], ball[1]);
		BFSqueue.push(tempNode);
		while(! BFSqueue.empty()) {
			node topNode = BFSqueue.front();
			for(int i = 0; i < 4; i++) {
				node currentNode = BFSqueue.front();
				while(! IsNodeWall(maze, currentNode.x + nextDir[i][0], currentNode.y + nextDir[i][1])) {
					currentNode.x += nextDir[i][0];
					currentNode.y += nextDir[i][1];
					if (currentNode.x == hole[0] && currentNode.y == hole[1]) {
						RefreshNodeInfo(dpVec, resultsNode, hole[0], hole[1], topNode, dirStr[i]);
					}
				}
				if (RefreshNodeInfo(dpVec, dpVec[currentNode.x][currentNode.y], currentNode.x, currentNode.y, topNode, dirStr[i])) {
					node insertDirNode(currentNode.x, currentNode.y);
					BFSqueue.push(insertDirNode);
				}
			}
			BFSqueue.pop();
		}
		if (resultsNode.nodeStr.empty()) {
			return "impossible";
		} else {
			return resultsNode.nodeStr;
		}
    }
};
```