### 解题思路
1. 测试样例中有 [2,1]类似的边，所以统一修改成[1,2]的格式
2. 使用广度优先遍历的方法，但需要注意如果某一个点没有后继但时间没有停止，那么这个点就是我们需要的；如果时间没有停止但是已经到达了该点，则只能返回0；
3. 使用隔板，将每一层的节点都放在队列中，每次拿掉一个隔板，时间自减且表明该层的节点全都已经被访问过了。
4. 最后需要做的是，将队列中的节点看一遍是否存在我们需要的点，并返回概率。

### 代码

```cpp
struct Node { // 结构体存储从开始到本节点的分叉数，用来计算概率。
	int num;
	int ways;
	Node(){}
	Node(int n,int w):num(n),ways(w){}
};
class Solution {
public:
	vector<vector<int>>links;
	queue<Node> myqueue;
	void solveLinks(int n,vector<vector<int>>& edges) {  // 得到边之间的关系，方便查找
		vector<int>temp;
		for (int i = 0; i < n+1; i++) {
			links.push_back(temp);
		}
		for (int i = 0; i < edges.size(); i++) {
			int a = edges[i][0], b = edges[i][1];
			if (a < b) {
				links[a].push_back(b);
			}
			else {
				links[b].push_back(a);
			}
		}
	}
	double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
		solveLinks(n, edges);
		Node p(1, 1);
		Node broad(-1, 0); // 隔板
		myqueue.push(p);
		myqueue.push(broad);
		bool flag = false;
		while (!myqueue.empty() && t > 0) { // 非空且时间充足的情况下进行
			Node temp = myqueue.front();
			myqueue.pop();
			if (temp.num == -1) { // 找到隔板的时候时间自减
				t--; // 时间自减1
				flag = true;
			}
			else {
				if (flag) {
					myqueue.push(broad);
					flag = false;
				}
				int s = links[temp.num].size();
				if (temp.num == target && s == 0) {
					Node m(temp.num, temp.ways); // 是target且target没有后继节点，此时不再变更概率
					myqueue.push(m);
				}
				else { // 普通情况，则将节点的后继都push进队列中即可
					for (int i = 0; i < s; i++) {
						Node m(links[temp.num][i], temp.ways*s);
						myqueue.push(m);
					}
				}
			}
		}
		while (!myqueue.empty()) {
			if (myqueue.front().num == target) {
				return 1.0 / myqueue.front().ways;
			}
			myqueue.pop();
		}
		return 0;
	}
};
```