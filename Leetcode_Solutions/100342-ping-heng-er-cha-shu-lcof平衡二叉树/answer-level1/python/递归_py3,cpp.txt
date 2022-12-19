```cpp []
class Solution {
public:
    bool ans = true;
    bool isBalanced(TreeNode* root) {
        f(root);
        return ans;
    }
    
    int f(TreeNode* node) {
        if (node == nullptr) return 0;
        int left = f(node->left) + 1;
        int right = f(node->right) + 1;
        if (abs(left - right) > 1) ans = false;
        return max(left, right);
    }
};
```
```python []
class Solution:
    def isBalanced(self, root: TreeNode) -> bool:
        self.ans = True
        def f(node):
            if not node:
                return 0
            left = f(node.left) + 1
            right = f(node.right) + 1
            if abs(left - right) > 1:
                self.ans = False
            return max(left, right)
        f(root)
        return self.ans
```

