### 解题思路
用一个数组存放已经NEW过的新节点, 题目条件节点数值不唯一且仅为1到100, 因此直接用val做为下标放进node池中.
DFS时先看池子里有没有节点, 没有则创建节点并放入池子, 同时搜索该节点的neighbors.
如果有节点, 直接放入neighbors即可.

### 代码

```cpp
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
class Solution {
public:
    vector<Node*> nodePool;
    Node* cloneGraph(Node* node) {
        nodePool.resize(101);
        if (!node) return NULL;
        Node* newNode = new Node(node->val);
        nodePool[node->val] = newNode;
        dfs(node, newNode);
        return newNode;
    }
    void dfs(Node* node, Node* newNode) {
        for (Node* i : node->neighbors) {
            if (!nodePool[i->val]) {
                nodePool[i->val] = new Node(i->val);
                newNode->neighbors.push_back(nodePool[i->val]);
                dfs(i, nodePool[i->val]);
                continue;
            }
            newNode->neighbors.push_back(nodePool[i->val]);
        }
    }
};
```