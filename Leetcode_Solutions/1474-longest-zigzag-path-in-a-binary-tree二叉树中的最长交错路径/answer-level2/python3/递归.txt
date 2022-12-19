```cpp []
class Solution {
public:
    int ans = 0;
    int longestZigZag(TreeNode* root) {
        f(root, true, 0);
        f(root, false, 0);
        return ans - 1;
    }
    
    void f(TreeNode* node, bool right, int s) {
        if (node != nullptr) {
            ans = max(ans, 1 + s);
            if (right) {
                f(node->left, !right, 1 + s);
                f(node->right, right, 1);
            } else {
                f(node->right, !right, 1 + s);
                f(node->left, right, 1);
            }
        }
    }
};
```
```python3 []
class Solution:
    def longestZigZag(self, root: TreeNode) -> int:
        self.ans = 0
        def f(node, right, s):
            if node:
                self.ans = max(self.ans, 1 + s)
                if right:
                    f(node.left, not right, 1 + s)
                    f(node.right, right, 1)
                else:
                    f(node.right, not right, 1 + s)
                    f(node.left, right, 1)
        f(root, True, 0)
        f(root, False, 0)
        return self.ans - 1
```
