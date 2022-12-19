```c++
vector<int> preorder(Node* root) {
    std::stack<Node*> s;
    std::vector<int> v;
    if (root) {
        s.push(root);
    }
    while (!s.empty()) {
        auto node = s.top();
        s.pop();
        v.push_back(node->val);
        for (int i = (int)node->children.size() - 1; i >= 0; --i) {
            if (node->children[i]) {
                s.push(node->children[i]);
            }
        }
    }
    return v;
}
```