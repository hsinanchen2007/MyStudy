### 解题思路
此处撰写解题思路

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
    Node* cloneGraph(Node* node) {
        if (node == nullptr) return nullptr;
        return bfs(node);
    }

    Node* bfs(Node* node) {
        Node* firstnode = node;
        queue<Node*> breadth_search_queue_;
        breadth_search_queue_.push(node);
        while (!breadth_search_queue_.empty()){
            node = breadth_search_queue_.front();
            breadth_search_queue_.pop();
            if (setted_.find(node) != setted_.end()) continue;
            setted_.insert(node);
            if (node_to_new_node_.find(node) == node_to_new_node_.end())
                node_to_new_node_.insert(pair(node, new Node(node->val)));
            
            Node* new_node = node_to_new_node_.find(node)->second;
            for(auto iter=node->neighbors.begin(); iter!=node->neighbors.end(); iter++) {
                if(node_to_new_node_.find(*iter) == node_to_new_node_.end()) {
                    node_to_new_node_.insert(pair(*iter, new Node((*iter)->val)));
                }
                new_node->neighbors.push_back(node_to_new_node_.find(*iter)->second);
                if (setted_.find(*iter) != setted_.end()) continue;
                breadth_search_queue_.push(*iter);
            }
        }
        return node_to_new_node_.find(firstnode)->second;
    }
private:
    unordered_map<Node*, Node*> node_to_new_node_;
    unordered_set<Node*> setted_;
};
```