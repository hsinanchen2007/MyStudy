```c++
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    vector<int> preorder(Node* root) {
        if (!root) return {};
        vector<int> result;
        stack<Node*> nodes;
        nodes.push(root);
        while (!nodes.empty()) {
            auto node = nodes.top();
            nodes.pop();
            result.push_back(node->val);
            for (auto it = node->children.rbegin(); it != node->children.rend(); it++) {
                nodes.push(*it);
            }
        }
        return result;
    }
};
```