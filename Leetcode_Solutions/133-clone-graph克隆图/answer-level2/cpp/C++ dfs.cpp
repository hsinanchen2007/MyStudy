### 解题思路
这个直接dfs遍历就行了，用一个map来维护已经遍历过的节点，key是需要遍历的节点，value是它对应的copy节点。

### 代码

```cpp
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {}

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
class Solution {
public:
     Node* cloneGraph(Node* node) {
        map<Node*, Node*> visited;
        return dfsClone(node, visited);
    }
    
    Node* dfsClone(Node* node, map<Node*, Node*> &visited) {
        if (visited.count(node)) {
            return visited[node];
        }
        Node* p = new Node(node->val, vector<Node*>());
        visited[node] = p;
        
        for (auto n : node->neighbors) {
             p->neighbors.emplace_back(dfsClone(n, visited));
        }
        return p;
    }
};
```