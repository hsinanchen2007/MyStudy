### 解题思路
首先把输入信息转换成一个有向图，然后遍历输入的方程式，使用BFS进行搜索，每次BFS都需要记录当前节点到起始节点的value值。
这道题最关键的点实质上是将方程式求解的问题转换成图论问题，方程式描述的两个node之间的联系，所以可以抽象成图之间的边。当然这道题也有并查集解法。

### 代码

```cpp
class Solution {
public:
	struct node {
		string nodeStr;
		double value;
		node (string inputStr, double inputValue) {
			nodeStr = inputStr;
			value = inputValue;
		}
	};
	
	double BFSGetEquation(map<string, vector<node>>& equationMap, string startNode, string endNode, set<string>& isVisited) {
		queue<node> BfsStr;
		node tempNode(startNode, 1);
		BfsStr.push(tempNode);
		isVisited.insert(startNode);
		while(! BfsStr.empty()) {
			node currentNode = BfsStr.front();
			BfsStr.pop();
			auto nodeVec = equationMap[currentNode.nodeStr];
			for (auto nodeItem : nodeVec) {
				if (nodeItem.nodeStr == endNode) {
					return nodeItem.value * currentNode.value;
				}
				if (isVisited.find(nodeItem.nodeStr) != isVisited.end()) {
					continue;
				}
				tempNode.nodeStr = nodeItem.nodeStr;
				tempNode.value = nodeItem.value * currentNode.value;
				BfsStr.push(tempNode);
				isVisited.insert(tempNode.nodeStr);
			}
		}
		return -1;
	}
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
		map<string, vector<node>> equationMap;
		for (int i = 0; i < equations.size(); i++) {
			node tempNode(equations[i][1], values[i]);
			equationMap[equations[i][0]].push_back(tempNode);
			tempNode.nodeStr = equations[i][0];
			tempNode.value = ((double)1)/values[i]; 
			equationMap[equations[i][1]].push_back(tempNode);
		}
		vector<double> results;
		for (auto querieItem : queries) {
			if (equationMap.find(querieItem[0]) != equationMap.end()) {
				if (querieItem[0] == querieItem[1]) {
					results.push_back(1);
				} else {
					set<string> isVisited;
					results.push_back(BFSGetEquation(equationMap, querieItem[0], querieItem[1],isVisited));
				}
			} else {
				results.push_back(-1);
			}
		}
		return results;
		
    }
};
```