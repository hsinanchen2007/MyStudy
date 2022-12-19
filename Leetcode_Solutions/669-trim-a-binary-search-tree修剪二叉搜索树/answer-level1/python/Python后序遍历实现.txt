
## 解题思路

看到这个题让我直接想到了后序遍历，可以参照1325题《删除给定值的叶子节点》这两题有相似之处。
我是分类讨论可能出现的情况，然后针对各种情况返回修剪后应该的样子的树。看了官方题解之后，感觉基于当前值得和目标值范围的大小来判断会简洁明了很多。

## 代码

```
class Solution:
    def trimBST(self, root: TreeNode, L: int, R: int) -> TreeNode:
        
        def helper(node):
            if not node:
                return None
            
            node.left = helper(node.left)
            node.right = helper(node.right)

            if node.val < L or node.val > R:
                ## leaf node
                if node.left == None and node.right == None:
                    return None
                
                ## have sigle child
                if node.left != None and node.right == None:
                    return node.left
                
                if node.left == None and node.right != None:
                    return node.right
                
                ## have 2 children 
                if node.right != None and node.left != None:
                    # find new root
                    root_new = node.right
                    # change struct
                    root_new_left = root_new.left
                    while not root_new_left.left:
                        root_new_left = root_left.left
                    root_new_left.left = node.left
                    return root_new
                
            return node
        return helper(root)
```
