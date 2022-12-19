模拟信号流动，每次选择最短的边(们)走，走完的边从当前的map中删掉，同时把新到节点带来的边加入map

```
int** MakeMatrix(int rows, int cols, int defVal) {
	int** mat = new int*[rows];
	for (int i = 0; i < rows; ++i) {
		mat[i] = new int[cols];
		fill_n(mat[i], cols, defVal);
	}
	return mat;
}

void DestroyMatrix(int** mat, int rows) {
	for (int i = 0; i < rows; ++i) {
		delete[] mat[i];
	}
	delete[] mat;
}

int networkDelayTime(vector<vector<int>>& times, int N, int K) {
	// 初始化权重（边长）矩阵
	int** weights = MakeMatrix(N + 1, N + 1, INT_MAX);
	for (auto time : times) {
		weights[time[0]][time[1]] = time[2];
	}
	
	int* arrivedTime = new int[N + 1];     // 表示每个节点的信号到达时间（到源点K的最短路径长度）
	fill_n(arrivedTime, N + 1, INT_MAX);
	arrivedTime[K] = 0;
	map<int, list<vector<int>>> currPaths; // 表示信号正在走过的边，Key为
	for (int i = 1; i <= N; ++i) {
		if (weights[K][i] != INT_MAX) {
			currPaths[weights[K][i]].push_back({K, i});
			cout << K << "->" << i << "=" << weights[K][i] << endl;
		}
	}
	if (currPaths.size() == 0)
		return -1;  // 首个节点就无路出去，返回-1
	
	int arrivedPtCnt = 1;  // 计数，信号每到达一个新节点就+1
	while (!currPaths.empty()) {
		auto shortestPaths = currPaths.begin();   // 拿出当前出发点所有边中的最短边(们)，每次都从最短边走
		auto it = shortestPaths->second.begin();
		while (it != shortestPaths->second.end()) {
			int srcPt = (*it)[0];
			int dstPt = (*it)[1];
			if (arrivedTime[dstPt] == INT_MAX) {  // 如果节点dstPt的到达时间不为INT_MAX，则说明已经在较早时间到达过，不处理
				arrivedTime[dstPt] = shortestPaths->first;  // 记录新节点的到达时间
				cout << "arrived time of " << dstPt << " is " << arrivedTime[dstPt] << endl;
				if (++arrivedPtCnt == N) {  // 所有节点都已经到达，返回最后节点的到达时间
					DestroyMatrix(weights, N + 1);
					return arrivedTime[dstPt];
				}
			}
			it = shortestPaths->second.erase(it);  // 把走完的边从当前链表中删除
			if (shortestPaths->second.empty())     // 链表若已删空则把对应的map的元素也删除
				currPaths.erase(shortestPaths);
			for (int i = 1; i <= N; ++i) {   // 新节点继续往外走
				if (weights[dstPt][i] != INT_MAX && arrivedTime[i] == INT_MAX) {
					int newPathLen = arrivedTime[dstPt] + weights[dstPt][i];  // 此处的“边”长实际上是节点i到源点K的最短路径长度
					currPaths[newPathLen].push_back({dstPt, i});
					cout << "source->" << dstPt << "->" << i << "=" << newPathLen << endl;
				}
			}
		}
	}
	
	DestroyMatrix(weights, N + 1);
	cout << "cant't reach all points." << endl;
	return -1;
}
```
![图片.png](https://pic.leetcode-cn.com/2fa37b2052b9044c6f8ddc5fbb26fd1c8542008a74c84a3c05d0eeeb51f9fda5-%E5%9B%BE%E7%89%87.png)
