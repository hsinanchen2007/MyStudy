由于青蛙总是从1开始跳的，所以我们可以以1为根节点将图转化为一颗树，当然我们并不需要建立一颗真正的树的结构。我们需要什么？
我们需要得到：
每个节点的父节点是谁？用来描述树。
每个节点的孩子有几个？用来计算时间刚好青蛙可以到该节点子女节点时的概率。
每个节点的深度？用来判断到达该节点的时间。

第一步：找到每个节点的父节点。扫描一遍边集合，所有连接该点的边的另一端点为该点的父节点或子节点。要把父节点排除很简单，我们先把根节点1加入一个队列，然后按层次遍历的方式扫描，扫到的关联边直接从边集合中删除，将这些边的另一端点的父节点设置为该点，并将它们加入队列中。PS：下面代码中没有直接删除边，而是用一个bool数组来屏蔽掉要删除的边。

第二步：计算每个节点的孩子有几个。由于找父节点是层次遍历的，对每个节点在遍历边集合时已经找出了所有子节点，所以遍历完边集合后，统计一下子节点个数就行了。

第三步：计算每个节点的深度。也是在层次遍历的过程中进行，每个节点的深度等于它父节点的深度+1。

第四步：计算时间刚好青蛙可以到该节点时的概率，等于它父节点的概率除以它父节点的孩子数（节点1可能要做特殊处理）。由于层次遍历过程中遍历到该节点时，它的父节点已经被遍历过了，它父节点的概率也已经算出，所以对概率的计算也可以放在层次遍历过程中。PS：很显然，青蛙只能从父节点跳到子节点，无法向上返回。

第五步:计算最后的概率。若时间还没到该节点的深度，则青蛙不可能跳到该点，返回0；若时间已经超过了该节点的深度，并且该节点不是叶节点的话（可以根据该节点孩子数判断是否为叶节点），返回0；其他情况就是时间刚好青蛙可以到该节点，返回之前算的概率。

执行用时20ms，超过100%。内存消耗15.8MB，超过100%。

```C++ []
class Solution {
public:
	vector<bool> e;	//该边是否被访问过
	vector<int> father;	//该点的父节点
	vector<int> sons_num;	//该点孩子的数量
	vector<int> depth;	//该点的深度
	vector<double> possible;	//跳到该点的概率

	double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
		this->e = vector<bool>(edges.size(), true);
		this->father = vector<int>(n + 1, -1);
		this->sons_num = vector<int>(n + 1, 0);
		this->depth = vector<int>(n + 1, 0);
		this->possible = vector<double>(n + 1, 1);
		queue<int> q;
		q.push(1);	//根节点加入q
		while (!q.empty()) {
			vector<int> tmp = find_alledges(edges, q.front());
			q.pop();
			for (int t : tmp) {
				q.push(t);
			}
		}
		if (t < depth[target])
			return 0;
		if (t > depth[target] && sons_num[target] > 0)
			return 0;
		return possible[target];
	}

	vector<int> find_alledges(vector<vector<int>>& edges, int elem) {
		vector<int> res;
		for (int i = 0; i < edges.size(); i++) {
			if (e[i] == true) {
				if (edges[i][0] == elem) {
					res.push_back(edges[i][1]);
					father[edges[i][1]] = elem;
					depth[edges[i][1]] = depth[elem] + 1;
					e[i] = false;
				}
				if (edges[i][1] == elem) {
					res.push_back(edges[i][0]);
					father[edges[i][0]] = elem;
					depth[edges[i][0]] = depth[elem] + 1;
					e[i] = false;
				}
			}
		}
		sons_num[elem] = res.size();
		if (elem != 1){
			possible[elem] = possible[father[elem]] / sons_num[father[elem]];
		}
		return res;
	}
};
```
