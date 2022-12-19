### 解题思路
递归时需要考虑三种情况，分别是当前根的值大于、小于、等于目标值；
大于、小于时直接进入相应子树继续搜索即可，注意储存返回值；
等于时说明要删除当前根节点，并要进行左、右子树的重新连接，此时又可大致分为两种情况，在以下代码注释中已详细讨论，可参考具体代码。

### 代码

```python3
class Solution:
    def deleteNode(self, root: TreeNode, key: int) -> TreeNode:
        if not root:
            return root
        if key==root.val:
            #一、当左、右子树一方存在，则跳过根root，直接返回存在的那个子树即可（左、右子树都不存在可看作此类的特殊情况，不用单独讨论）
            if not root.left:
                return root.right
            if not root.right:
                return root.left

            #二、当左、右子树同时存在时，寻找左子树中最大值对应的节点（也就是根root的前驱结点），将其赋值给leftMax
            leftMax=root.left
            while leftMax.right:
                leftMax=leftMax.right
            #将根root的右子树连接到leftMax节点下，使其成为leftMax的右子树
            leftMax.right=root.right
            #跳过根root，直接返回root的左子树即可
            return root.left

        if key < root.val:
            root.left=self.deleteNode(root.left,key)
        else:
            root.right=self.deleteNode(root.right,key)
        return root
```