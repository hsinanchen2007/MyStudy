## 思路:

这道题和[105. 从前序与中序遍历序列构造二叉树](https://leetcode-cn.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/)是一样的

我们想了解, 后序遍历是 : 左->右->根;中序遍历是:左->根->右

所以我们可以通过后序遍历,可以把树分成左右部分.

例如示例中, 后序遍历最后一个节点`3`,那么节点`3`左右子树为`[9]`;`[15,20,7]`,然后我们递归下去,简单想法如下

```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def buildTree(self, inorder: List[int], postorder: List[int]) -> TreeNode:
        if not inorder: return None
        root = TreeNode(postorder[-1])
        loc = inorder.index(postorder[-1])
        root.left = self.buildTree(inorder[ : loc], postorder[ :loc])
        root.right = self.buildTree(inorder[loc+1:], postorder[loc:-1])
        return root
```

注意: 

1. 我们保证递归下去的 `postorder` 和 `inorder` 个数是一样的(关键!!!)
2. 每次都要`index`;所以我们可以`map` 节约时间.

我们把代码优化, 代码中有注释,很好理解!

## 代码:

```python [1]
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def buildTree(self, inorder: List[int], postorder: List[int]) -> TreeNode:
        from collections import defaultdict
        n = len(inorder)
        inorder_map = defaultdict(int)
        for idx, val in enumerate(inorder):
            inorder_map[val] = idx
        #print(inorder_map)
        def helper(in_start, in_end, post_start, post_end):
            if in_start == in_end:
                return None
            #print(post_end)
            root = TreeNode(postorder[post_end - 1])
            loc = inorder_map[postorder[post_end - 1]]
            root.left = helper(in_start, loc, post_start, post_start + loc - in_start)
            root.right = helper(loc + 1, in_end, post_start + loc - in_start, post_end - 1)
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
    public TreeNode buildTree(int[] inorder, int[] postorder) {
        Map<Integer, Integer> inorder_map = new HashMap<>();
        int n = inorder.length;
        for (int i = 0; i < n; i++) inorder_map.put(inorder[i], i);
        return helper(inorder, 0, n, postorder, 0, n, inorder_map);
    }

    private TreeNode helper(int[] inorder, int in_start, int in_end, int[] postorder, int post_start, int post_end, Map<Integer, Integer> inorder_map) {
        if (in_start == in_end) return null;
        TreeNode root = new TreeNode(postorder[post_end - 1]);
        int loc = inorder_map.get(postorder[post_end - 1]);
        root.left = helper(inorder, in_start, loc, postorder, post_start, post_start + loc - in_start, inorder_map);
        root.right = helper(inorder, loc + 1, in_end, postorder, post_start + loc - in_start, post_end - 1, inorder_map);
        return root;
    }
}
```

