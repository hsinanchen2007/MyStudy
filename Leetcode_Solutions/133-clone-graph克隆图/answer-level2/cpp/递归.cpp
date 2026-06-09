### 解题思路
递归地复制每一个顶点，同时存储前面复制出来的顶点指针。注意副本顶点的指针一定要new出来。

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
    Node* copys[101]={nullptr}; //顶点编号到其副本指针

    Node* cloneGraph(Node* node) {
        //复制一个顶点
        if(node==nullptr) return nullptr;
        if(copys[node->val]!=nullptr) return copys[node->val];
        Node* _node = new Node(node->val);
        copys[node->val] = _node;
        for(Node* x:node->neighbors){
            _node->neighbors.emplace_back(cloneGraph(x));
        }
        return _node;
    }
};
```