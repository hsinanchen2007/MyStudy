## 深度优先(stack+unordered_map)
```cpp
    Node* cloneGraphDfs(Node* node)
	{
		if (!node) return nullptr;
		unordered_map<Node*, Node*>mp;
		stack<Node*> st({ node });
		const auto new_node = new Node(node->val);
		mp[node] = new_node;
		while (!st.empty()) {
			const auto temp = st.top();
			st.pop();
			for (const auto&e : temp->neighbors) {
				if(!mp.count(e)) {
					st.push(e);
					mp[e] = new Node(e->val);
				}
				mp[temp]->neighbors.push_back(mp[e]);
			}
		}
		return mp[node];
	}
```
## 广度优先(queue+unordered_map)
```cpp
    Node* cloneGraphBfs(Node* node)
	{
		if (!node) return nullptr;
		unordered_map<Node*, Node*> mp;
		queue<Node*> que({ node });
		const auto new_node = new Node(node->val);
		mp[node] = new_node;
		while (!que.empty()) {
			auto temp = que.front();
			que.pop();
			for (const auto&e : temp->neighbors) {
				if (!mp.count(e)) {
					que.push(e);
					mp[e] = new Node(e->val);
				}
				mp[temp]->neighbors.push_back(mp[e]);
			}
		}
		return mp[node];
	}
```
## 深度优先(递归+unordered_map)
```cpp
    unordered_map<Node*, Node*>mp;
	Node* cloneGraphDfsRecur(Node* node) {
		if (!node) return nullptr;
		if (mp.count(node)) return mp[node];
		const auto new_root = new Node(node->val);
		mp[node] = new_root;
		for (const auto&e : node->neighbors) {
			mp[node]->neighbors.push_back(cloneGraphDfsRecur(e));
		}
		return mp[node];
	}
```