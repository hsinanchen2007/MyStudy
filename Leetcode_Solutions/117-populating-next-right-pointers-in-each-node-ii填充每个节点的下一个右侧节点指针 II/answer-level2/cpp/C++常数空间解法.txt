写一个辅助函数得到当前节点下一层的最左侧节点可以简化代码
```
class Solution {
public:
    Node* getNextLeftMost(Node* root) {
        while (root) {
            if (root->left) return root->left;
            if (root->right) return root->right;
            root = root->next;
        }
        return NULL;
    }
    
    Node* connect(Node* root) {
        Node* rootCopy = root;
        while (root) {
            Node* it = root;
            while (it) {
                if (it->left) {
                    if (it->right) it->left->next = it->right;
                    else it->left->next = getNextLeftMost(it->next);
                }
                if (it->right) it->right->next = getNextLeftMost(it->next);
                it = it->next;
            }
            root = getNextLeftMost(root);
        }
        return rootCopy;
    }
};
```