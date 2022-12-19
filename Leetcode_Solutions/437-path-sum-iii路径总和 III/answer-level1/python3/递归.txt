自上向下不断记录所有路径的和。
```
       10
     /  \
    5   -3
   / \    \
  3   2   11
 / \   \
3  -2   1
```
第1层，只有一个路径：10
第2层，四个路径：10 -> 5,   10 -> -3,   5, -3。那么和也有四个：15, 7, 5, -3。
继续向下，第3层，有如下路径：
**1)**    10 -> 5 -> 3,   10 -> 5 -> 2, 10 -> -3 ->11
**2)**    5 -> 3, 5 -> 2, -3 -> 11
**3)**    3,  2,  11
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
                for i in vs:
                    if i == sum:
                        self.ans += 1
                f(node.left, vs)
                f(node.right, vs)
        f(root, [])
        return self.ans
```

