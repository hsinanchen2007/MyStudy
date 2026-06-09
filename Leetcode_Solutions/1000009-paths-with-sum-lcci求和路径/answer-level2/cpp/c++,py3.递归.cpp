其实此题和这题一样：https://leetcode-cn.com/problems/path-sum-iii/solution/

```cpp []
class Solution {
public:
    int ans = 0;
    int pathSum(TreeNode* root, int sum) {
        f(root, {}, sum);
        return ans;
    }
    
    void f(TreeNode* node, vector<int> vals, int s) {
        if (node != nullptr) {
            vector<int> vs = vals;
            vs.push_back(0);
            for (int i = 0; i < vs.size(); i++) {
                vs[i] += node->val;
                if (vs[i] == s) ans++;
            }
            f(node->left, vs, s);
            f(node->right, vs, s);
        }
    }
};
```
```python3 []
class Solution:
    def pathSum(self, root: TreeNode, sum: int) -> int:
        self.ans = 0
        def f(node, vals):
            if node:
                vs = [i + node.val for i in vals] + [node.val]
                for i in range(len(vs)):
                    if vs[i] == sum:
                        self.ans += 1
                f(node.left, vs)
                f(node.right, vs)
        f(root, [])
        return self.ans
```

