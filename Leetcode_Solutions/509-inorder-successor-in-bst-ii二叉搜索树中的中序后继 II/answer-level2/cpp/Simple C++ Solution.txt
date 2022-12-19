```
Node* inorderSuccessor(Node* node) {
    if (node == NULL) return NULL;
    if (node->right) {
        node = node->right;
        while (node->left) node = node->left;
    } else {
        while (node->parent && node == node->parent->right) node = node->parent;
        node = node->parent;
    }
    return node;
}
```
