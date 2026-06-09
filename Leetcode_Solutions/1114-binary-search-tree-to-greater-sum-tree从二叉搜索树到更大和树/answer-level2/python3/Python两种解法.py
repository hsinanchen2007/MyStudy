### 解题思路：
  
**1.**  这道题要求将二叉搜索树中每个节点 `node` 的值修改为树中大于或等于 `node.val` 的值之和，我们可以按照先右子树，然后根节点，然后左节点的顺序对该树进行遍历并修改节点的值，具体地，每个节点的值都应该加上其右子树上所有节点的值，如果该节点在某个节点b的左子树上，则该节点的值还应该加上所有大于等于节点b的值之和。  

**2.** 由于二叉搜索树的中序遍历就是按照节点值从小到大的顺序进行的，因此我们可以先对该二叉搜索树进行中序遍历，按顺序将访问到的节点的值保存到一个数组当中。然后按照先右子树，然后根节点，然后左节点的顺序对树中节点的值进行修改，修改后的值为中序遍历数组中对应该节点的数组元素以及该元素之后的所有元素之和。  

### 代码：  
```Python []
class Solution:
    def bstToGst(self, root: TreeNode) -> TreeNode:
        def helper(node, basic):
            if node is None:
                return 0
            tmp = node.val
            r,l = 0,0
            node.val += basic
            if node.right:
                r = helper(node.right, basic)
                node.val += r
                basic = node.val
            if node.left:
                l = helper(node.left, basic)
            return r + tmp + l
        helper(root, 0)
        return root
```      
```Python []
class Solution:
    def bstToGst(self, root: TreeNode) -> TreeNode:
        def in_order(node):
            if node is None:
                return
            nonlocal vals
            in_order(node.left)
            vals.append(node.val)
            in_order(node.right)

        def modify_val(node):
            if node is None:
                return
            nonlocal cur_index,cur_sum,vals
            modify_val(node.right)
            cur_sum += vals[cur_index]
            node.val = cur_sum 
            cur_index -= 1
            modify_val(node.left)

        vals = []
        in_order(root)
        cur_index = len(vals) - 1
        cur_sum = 0
        modify_val(root)
        return root
```
