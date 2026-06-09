自上而下，不断更新节点出现的最大值和最小值。所得到的最大值和最小值的差值就是答案。
```cpp []
class Solution {
public:
    int ans = 0;
    int maxAncestorDiff(TreeNode* root) {
        f(INT_MIN, INT_MAX, root);
        return ans;
    }
    
    void f(int mx, int mn, TreeNode* node) {
        if (node != nullptr) {
            mx = max(mx, node->val); //更新mx最大值
            mn = min(mn, node->val); //更新mn最小值
            ans = max(ans, abs(mx - mn)); //abs可以去掉
            f(mx, mn, node->left);  //将值传递到左右子节点
            f(mx, mn, node->right);
        }
    }
};
```
```python []
class Solution:
    def maxAncestorDiff(self, root: TreeNode) -> int:
        self.ans = 0;
        def f(mx, mn, node):
            if node:
                mx = max(mx, node.val)  #最大值
                mn = min(mn, node.val)  #最小值
                self.ans = max(self.ans, abs(mx - mn))
                f(mx, mn, node.left)
                f(mx, mn, node.right)
        f(float("-inf"), float("inf"), root)
        return self.ans
```
