## 思路:

二叉搜索树, 一节点大于左子树节点, 小于右子树节点

所以我们节点是从`1`到`n`,当一个节点为`val`那么它的左边是`<= val`,右边是`>=val`,

我们用递归解决!

----------

相关题型 : [96. 不同的二叉搜索树](https://leetcode-cn.com/problems/unique-binary-search-trees/)

## 代码:

```python [1]
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
import functools
class Solution:
    def generateTrees(self, n: int) -> List[TreeNode]:
        if n == 0: return []
        @functools.lru_cache(None)
        def helper(start, end):
            res = []
            if start > end:
                res.append(None)
            for val in range(start, end + 1):
                for left in helper(start, val - 1):
                    for right in helper(val + 1, end):
                        root = TreeNode(val)
                        root.left = left
                        root.right = right
                        res.append(root)
            return res

        return helper(1, n)
```



```java [1]
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    public List<TreeNode> generateTrees(int n) {

        if (n == 0) return new ArrayList<>();
        return helper(1, n);

    }

    private List<TreeNode> helper(int start, int end) {
        List<TreeNode> res = new ArrayList<>();
        if (start > end) {
            res.add(null);
            return res;
        }
        for (int val = start; val <= end; val++) {
            List<TreeNode> left = helper(start, val - 1);
            List<TreeNode> right = helper(val + 1, end);
            for (TreeNode l : left) {
                for (TreeNode r : right) {
                    TreeNode root = new TreeNode(val);
                    root.left = l;
                    root.right = r;
                    res.add(root);
                }
            }
        }
        return res;
    }
}
```



