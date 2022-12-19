BFS 
先通过头结点进行BFS，在BFS的同时记录每个结点的邻居结点，注意此时要判重以便于BFS终止，在记录完所有节点的邻居结点后(以int的形式记录)，开始构建结点之间的关系，之后就非常简单了。

看代码：
```
代码块
```map<int, vector<int>> count;//记录每个结点邻居结点的标号;
		map<int, int> map1;//判断是否重复;
		map<int, Node*> map2;//将结点与标号连接起来;
		queue<Node*> queue1;
		queue1.push(node);
		int count_all = node->val;//统计结点数量;
		//map1[node->val] = 1;
		while (!queue1.empty()) {
			auto node = queue1.front();
			queue1.pop();
			if (map1.find(node->val) != map1.end()) continue;
			map1[node->val] = 1;
			int size = node->neighbors.size();
			for (int i = 0; i < size; i++) {
				int val = node->neighbors[i]->val;
				if (val > count_all) count_all = val;
				if (map1.find(node->val) == map1.end()) {
					queue1.push(node->neighbors[i]);//压入元素：
				}
				count[node->val].push_back(val);
			}
		}
		vector<Node*> temp;//暂时存放所有结点;
		for (int i = 1; i <= count_all; i++) {
			
				Node* k1 = new Node;
				k1->val = i;
				map2[i] = k1;
				temp.push_back(k1);//使用一个temp保存结点;
		}
		//开始构建连接整个图;
		for (int i = 0; i < temp.size(); i++) {
			for (int j = 0; j < count[i].size(); i++) {
				temp[i]->neighbors.push_back(map2[count[i+1][j]);//注意是i+1,因为索引0,代表结点1.
			}
		}
		return temp[0];
```
```
