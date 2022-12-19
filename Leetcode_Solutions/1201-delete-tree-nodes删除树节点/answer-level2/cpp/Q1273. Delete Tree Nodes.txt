### 深度优先搜索(DFS)
1. 首先，通过`parent`建立一棵树`treeNodes`；
2. 然后，使用深度优先搜索(DFS)计算各个子树的值`treeValue`；
3. 最后，再DFS遍历整棵树，计算还剩下的节点的数目。
4. 第3步可以直接在第2步时就做好，这样就不用再多一个`treeValue`，可以节省O(N)的空间复杂度。
```
class Solution {
public:
	int deleteTreeNodes(int nodes, vector<int>& parent, vector<int>& value) {
		vector<vector<int>> treeNodes(nodes);
		for (int i = 1; i < nodes; ++i)
			treeNodes[parent[i]].push_back(i);

		vector<int> treeValue(nodes, 0);
		treeValue[0] = dfsCalcTreeValue(treeNodes, value, treeValue, 0);

		size_t nLeftNodesCount = dfsCountRemainNodes(treeNodes, treeValue, 0);
		return nLeftNodesCount;
	}

	int dfsCalcTreeValue(
		const vector<vector<int>>& treeNodes,
		const vector<int>& value,
		vector<int>& treeValue,
		size_t idx)
	{
		treeValue[idx] = value[idx];
		for (size_t i = 0; i < treeNodes[idx].size(); ++i) {
			treeValue[idx] += dfsCalcTreeValue(treeNodes, value, treeValue, treeNodes[idx][i]);
		}

		return treeValue[idx];
	}

	size_t dfsCountRemainNodes(
		const vector<vector<int>>& treeNodes,
		const vector<int>& treeValue,
		size_t idx)
	{
		if (treeValue[idx] == 0)
			return 0;

		size_t nCount = 1;
		for (size_t i = 0; i < treeNodes[idx].size(); ++i) {
			nCount += dfsCountRemainNodes(treeNodes, treeValue, treeNodes[idx][i]);
		}

		return nCount;
	}
};
```