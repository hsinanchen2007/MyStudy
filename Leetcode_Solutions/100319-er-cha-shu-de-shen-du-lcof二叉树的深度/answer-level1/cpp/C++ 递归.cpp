### 回溯
```cpp
class Solution {
public:
    int maxDepth(TreeNode* root) {
        _maxDepth = 0;
        backtrack(root, 0);
        return _maxDepth;
    }

    void backtrack(TreeNode *node, int depth) {
        if (node == nullptr) {
            _maxDepth = max(_maxDepth, depth);
            return;
        }

        backtrack(node->left, depth+1);
        backtrack(node->right, depth+1);
    }

    int _maxDepth;
};
```

### 化归
```cpp
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == nullptr) return 0;
        return max(maxDepth(root->left), maxDepth(root->right))+1;
    }
};
```