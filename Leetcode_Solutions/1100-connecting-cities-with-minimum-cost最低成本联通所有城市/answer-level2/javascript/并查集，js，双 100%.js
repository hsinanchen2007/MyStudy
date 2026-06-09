### 代码

```javascript
/**
 * @param {number} N
 * @param {number[][]} connections
 * @return {number}
 */
var minimumCost = function(N, connections) {
    if (N <= 1) {
    	return 0;
    }
	// 先把 connections 按照 cost 从小到高排序
    connections.sort(function(conn1, conn2) {
    	return conn1[2] - conn2[2];
    });

	// 创建一个并查集对象
    var dsu = new DSU(N);
    var costs = 0;
    for (var i = 0; i < connections.length; i++) {
		// 题目的城市编号是 1 ~ N，但我们的并查集里的城市编号是 0 ~ N-1，因此这里要转换一下
    	var id1 = connections[i][0] - 1;
    	var id2 = connections[i][1] - 1;
    	if (dsu.isConnected(id1, id2)) {
			// 如果 id1 和 id2 已经相连了，那就不要再修建这条连接了，纯属浪费，因此直接 continue
    		continue;
    	}
		// 修建这条连接
    	costs += connections[i][2];
    	dsu.union(id1, id2);
    }
	// 最后，如果连通分量降为了 1 则说明全部城市都被连接了
    if (dsu.connectedComponents == 1) {
    	return costs;
    }
    return -1;
};

// 并查集对象的模板
var DSU = function(count) {
	if (count > 0) {
		this.connectedComponents = count;
	} else {
		this.connectedComponents = 0;
	}
	this.add = function(id) {
		if (_parents[id]) {
			return;
		}
		_parents[id] = id;
		_ranks[id] = 1;
		this.connectedComponents++;
	};
	this.union = function(id1, id2) {
		var root1 = _find(id1);
		var root2 = _find(id2);
		if (root1 == root2) {
			return;
		}

		if (_ranks[root1] > _ranks[root2]) {
			_parents[root2] = root1;
		} else if (_ranks[root1] == _ranks[root2]) {
			_parents[root2] = root1;
			_ranks[root1]++;
		} else if (_ranks[root1] < _ranks[root2]) {
			_parents[root1] = root2;
		}
		this.connectedComponents--;
	};
	this.isConnected = function(id1, id2) {
		return _find(id1) == _find(id2);
	}

	var _parents = [];
	var _ranks = [];

	if (count > 0) {
		for (var i = 0; i < count; i++) {
			_parents[i] = i;
			_ranks[i] = 1;
		}
	}

	var _find = function(id) {
		if (_parents[id] == id) {
			return id;
		}
		var root = _find(_parents[id]);
		_parents[id] = root;
		return root;
	}
}
```