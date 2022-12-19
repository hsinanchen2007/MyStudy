### 深度优先遍历
```cpp
class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (node == nullptr) return node;
        unordered_map<Node *, Node*> table;
        return cloneGraph_helper(node, table);
    }

    Node* cloneGraph_helper(Node* node, unordered_map<Node *, Node*> &table) {
        auto it = table.find(node);
        if (it != table.end()) {
            return it->second;
        }

        Node *node_clone = new Node(node->val);
        table[node] = node_clone;
        for (auto neighbor: node->neighbors) {
            Node *neighbor_clone = cloneGraph_helper(neighbor, table); 
            node_clone->neighbors.push_back(neighbor_clone);
        }
        
        return node_clone;
    }
};
```

### 广度优先遍历
```cpp
class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (node == nullptr) return node;

        queue<Node *> quk;
        quk.push(node);
        unordered_map<Node *, Node*> table;
        Node *node_clone = new Node(node->val);
        table[node] = node_clone;

        while (!quk.empty()) {
            Node *cur = quk.front();
            quk.pop();
            for (auto neighbor: cur->neighbors) {
                auto it = table.find(neighbor);
                if (it == table.end()) {
                    quk.push(neighbor);
                    table[neighbor] = new Node(neighbor->val);
                }
                table[cur]->neighbors.push_back(table[neighbor]);
            }
        }
        return node_clone;
    }
};
```
