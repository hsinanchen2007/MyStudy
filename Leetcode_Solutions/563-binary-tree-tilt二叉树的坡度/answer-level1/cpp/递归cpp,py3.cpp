```cpp []
class Solution {
public:
    int ans = 0;
    int findTilt(TreeNode* root) {
        f(root);
        return ans;
    }
    
    int f(TreeNode* node) {
        if (node == nullptr) return 0;
        int left = f(node->left);
        int right = f(node->right);
        ans += abs(left - right);
        return left + right + node->val;
    }
};
```
```python []
class Solution:
    def findTilt(self, root: TreeNode) -> int:
        self.ans = 0
        def f(node):
            if not node:
                return 0
            left = f(node.left)
            right = f(node.right)
            self.ans += abs(left - right)
            return left + right + node.val
        f(root)
        return self.ans
```
