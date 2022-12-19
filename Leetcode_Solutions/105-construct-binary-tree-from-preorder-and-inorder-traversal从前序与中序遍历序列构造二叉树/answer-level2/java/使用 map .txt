
## 思路:

这道题和[106. 从中序与后序遍历序列构造二叉树](https://leetcode-cn.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/)是一样的

我们想了解, 前序遍历是 : 根->左->右;中序遍历是:左->根->右

所以我们可以通过前序遍历,可以把树分成左右部分.

例如示例中, 前序遍历`3`,那么节点`3`左右子树为`[9]`;`[15,20,7]`,然后我们递归下去,简单想法如下

```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def buildTree(self, preorder: List[int], inorder: List[int]) -> TreeNode:
        if not preorder:return None
        root = TreeNode(preorder[0])
        loc = inorder.index(preorder[0])
        root.left = self.buildTree(preorder[1 : loc + 1], inorder[ : loc])
        root.right = self.buildTree(preorder[loc+1 : ], inorder[loc+1: ])
        return root
```

注意: 

1. 我们保证递归下去的 `preorder` 和 `inorder` 个数是一样的
2. 每次都要`index`;所以我们`map` 节约时间.

我们将我们代码优化, 代码中有注释,很好理解的!

## 代码:

```python [1]
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def buildTree(self, preorder: List[int], inorder: List[int]) -> TreeNode:
        from collections import defaultdict
        n = len(preorder)
        inorder_map = defaultdict(int)
        for idx, val in enumerate(inorder):
            inorder_map[val] = idx

        def helper(pre_start, pre_end, in_start, in_end):
            if pre_start == pre_end:
                return None
            root = TreeNode(preorder[pre_start])
            loc = inorder_map[preorder[pre_start]]
            # 这里要注意 因为 一开始可以明确是 pre_start + 1,in_start,loc,因为前序和中序个数是相同,所以可以求出前序左右边界
            root.left = helper(pre_start + 1, pre_start + 1 + loc - in_start, in_start, loc)
            # 根据上面用过的, 写出剩下就行了
            root.right = helper(pre_start + 1 + loc - in_start, pre_end, loc + 1, in_end)
            return root

        return helper(0, n, 0, n)
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
    public TreeNode buildTree(int[] preorder, int[] inorder) {
        Map<Integer, Integer> inorder_map = new HashMap<>();
        int n = inorder.length;
        for (int i = 0; i < n; i++) inorder_map.put(inorder[i], i);

        return helper(preorder, 0, n, inorder, 0, n, inorder_map);


    }

    private TreeNode helper(int[] preorder, int pre_start, int pre_end, int[] inorder, int in_start, int in_end, Map<Integer, Integer> inorder_map) {
        if (pre_start == pre_end) return null;
        TreeNode root = new TreeNode(preorder[pre_start]);
        int loc = inorder_map.get(preorder[pre_start]);
        root.left = helper(preorder, pre_start + 1, pre_start + 1 + loc - in_start, inorder, in_start, loc, inorder_map);
        root.right = helper(preorder, pre_start + 1 + loc - in_start, pre_end, inorder, loc + 1, in_end, inorder_map);
        return root;
    }
}
```

