
```cpp
class Solution {
public:
unordered_map<int,Node*> map;
Node* cloneGraph(Node* node) {
	if (node == NULL)return NULL;
	if (map.find(node->val) != map.end()) return map[node->val];//如地图中已存在
	Node* new_node = new Node(node->val);//建立新节点
	map[new_node->val] = new_node;//先更新地图
	for (int i = 0;i < node->neighbors.size();i++) {
		new_node->neighbors.push_back(cloneGraph(node->neighbors[i]));//再更新邻接节点
	}
	return new_node;
}
};
```