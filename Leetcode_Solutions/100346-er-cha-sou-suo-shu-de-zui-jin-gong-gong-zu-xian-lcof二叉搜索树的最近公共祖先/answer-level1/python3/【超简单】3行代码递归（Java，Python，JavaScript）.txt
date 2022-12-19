
## 思路

这道题和[二叉树的最近公共祖先](https://leetcode-cn.com/problems/er-cha-shu-de-zui-jin-gong-gong-zu-xian-lcof/solution/chao-jian-dan-di-gui-pythonjavascript-by-azl397985/)的唯一差别就是本题的树是二叉搜索树（BST），也就暗示我们需要使用BST的特性。

由于lowestCommonAncestor(root, p, q)的功能是找出以root为根节点的两个节点p和q的最近公共祖先。 我们考虑：

- 如果p和q分别在root两侧，那么root就是最近公共祖先。我们使用(root.val - p.val) * (root.val - q.val) <= 0来判断即可。
- 否则的话（p和q在某一颗子树上），我们继续判断p是否在左子树。如果在（p在q一定也在），我们返回递归去左子树找。如果不在我们返回递归去右子树找


## 代码

Python：
```python
class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        if (root.val - p.val) * (root.val - q.val) <= 0: return root
        if p.val < root.val: return self.lowestCommonAncestor(root.left, p, q)
        return self.lowestCommonAncestor(root.right, p, q)
```

Java：

```java
class Solution {
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        if ((root.val - p.val) * (root.val - q.val) <= 0) {
            return root;
        } 
        if (p.val < root.val) {
            return lowestCommonAncestor(root.left, p, q);
        }
        return lowestCommonAncestor(root.right, p, q);
    }
}
```


JavaSCript：
```js
var lowestCommonAncestor = function(root, p, q) {
    if ((root.val - p.val) * (root.val - q.val) <= 0) return root
    if (p.val < root.val) return lowestCommonAncestor(root.left, p, q)
    return lowestCommonAncestor(root.right, p, q)
};
```


**复杂度分析**
- 时间复杂度：$O(logN)$
- 空间复杂度：$O(logN)$

欢迎关注我的公众号《脑洞前端》获取更多更新鲜的LeetCode题解

![](https://pic.leetcode-cn.com/89ef69abbf02a2957838499a96ce3fbb26830aae52e3ab90392e328c2670cddc-file_1581478989502)
