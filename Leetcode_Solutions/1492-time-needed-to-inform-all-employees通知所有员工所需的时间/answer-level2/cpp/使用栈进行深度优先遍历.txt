1. 之前使用递归显示超时，可能也是我多次调用find函数导致的。所以在周赛的时候花了一个多小时的时间处理这道题……（还是很菜）想到的是深度优先遍历，然后找时间的最大值即为返回结果。
2. 定义结构体（存储到该节点的花费时间），stack pop出一个元素就寻找他的子节点，一次进行下去，直到栈空。
3. 之前每次寻找某一个元素的父节点时都会调用find函数，后来用空间换取时间（定义vector<vector<int>>的info，只需要一次遍历，之后需要哪个元素的子节点直接返回即可）

```
struct Node {
	int num;
	int cost;
	Node(){}
	Node(int n,int c):num(n),cost(c){}
};
class Solution {
public:
	vector<vector<int>> info;
	void myfind(int id, vector<int>& manager) {
		vector<int>temp;
		for (int i = 0; i < manager.size(); i++) {
			info.push_back(temp);
		}
		for (int i = 0; i < manager.size(); i++) {
			if(manager[i] >= 0)
				info[manager[i]].push_back(i);
		}
	}
	int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
		stack<Node> costs;
		Node p(headID, 0);
		int max = 0;
		costs.push(p);
		myfind(headID, manager);
		while (!costs.empty()) {
			int i = costs.top().num, c = costs.top().cost;
			costs.pop();
			if (info[i].size() == 0) {
				max = (max > c) ? max : c;
			}
			else {
				for (int k = 0; k < info[i].size(); k++) {
					Node p(info[i][k], c+informTime[i]);
					costs.push(p);
				}
			}
		}
		return max;
	}
};
```
