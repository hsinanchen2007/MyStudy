## 思路
### 代码
```c++
class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (node == nullptr) return nullptr;
        unordered_map<Node*, Node*> umap;
        queue<Node*> que;
        que.push(node);
        Node* clone = new Node(node->val, {});
        umap[node] = clone;
        while (!que.empty()) {
            Node* cur = que.front();
            que.pop();
            for (Node* nei : cur->neighbors) {
                if (umap.count(nei) == 0) {
                    umap[nei] = new Node(nei->val, {});
                    que.push(nei);
                }
                umap[cur]->neighbors.push_back(umap[nei]);
            }
        }
        return clone;        
    }
};
```
