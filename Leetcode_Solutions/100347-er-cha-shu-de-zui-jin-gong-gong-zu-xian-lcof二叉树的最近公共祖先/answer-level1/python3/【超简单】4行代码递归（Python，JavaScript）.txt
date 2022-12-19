
## 思路

由于lowestCommonAncestor(root, p, q)的功能是找出以root为根节点的两个节点p和q的最近公共祖先。 我们考虑：

- 如果p和q分别是root的左右节点，那么root就是我们要找的最近公共祖先
- 如果root是None，说明我们在这条寻址线路没有找到，我们返回None表示没找到
- 我们继续在左右子树执行相同的逻辑。
- 如果左子树没找到，说明在右子树，我们返回lowestCommonAncestor(root.right,  p , q)
- 如果右子树没找到，说明在左子树，我们返回lowestCommonAncestor(root.left,  p , q)
- 如果左子树和右子树分别找到一个，我们返回root


## 代码

Python：

```python
class Solution:
    def lowestCommonAncestor(self, root: TreeNode, p: TreeNode, q: TreeNode) -> TreeNode:
        if not root or root.val == p.val or root.val == q.val: return root
        l = self.lowestCommonAncestor(root.left,  p , q)
        r = self.lowestCommonAncestor(root.right,  p , q)
        return root if l and r else l or r
```

JavaScript：

```js
var lowestCommonAncestor = function(root, p, q) {
  if (!root || root === p || root === q) return root;
  const left = lowestCommonAncestor(root.left, p, q);
  const right = lowestCommonAncestor(root.right, p, q);
  if (!left) return right; // 左子树找不到，返回右子树
  if (!right) return left; // 右子树找不到，返回左子树
  return root;
};
```


**复杂度分析**
- 时间复杂度：$O(N)$
- 空间复杂度：$O(N)$

欢迎关注我的公众号《脑洞前端》获取更多更新鲜的LeetCode题解

![](https://pic.leetcode-cn.com/89ef69abbf02a2957838499a96ce3fbb26830aae52e3ab90392e328c2670cddc-file_1581478989502)
