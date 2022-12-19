先过一遍中序遍历，对中序遍历递增排序后就能找到应该交换的点（排序前后不相等的点）。
然后在树里面查找找到要交换的两个点，交换即可
注意交换只换值，不要改变原来的结构。
```
class Solution:
    def recoverTree(self, root: TreeNode) -> None:
        """
        Do not return anything, modify root in-place instead.
        """
        midOrder = []
        wrongNode = []
        def findMidorder(node):
            if node.left != None:
                findMidorder(node.left)
            midOrder.append(node.val)
            if node.right != None:
                findMidorder(node.right)
        def search(root,i):
            if midOrder.index(root.val) == i:
                return root
            elif midOrder.index(root.val) < i:
                return search(root.right,i)
            else:
                return search(root.left,i)
        findMidorder(root)
        rightOrder = midOrder.copy()
        rightOrder.sort()
        for i in range(len(midOrder)):
            if midOrder[i] != rightOrder[i]:
                wrongNode.append(i)
        node1 = search(root,wrongNode[0])
        node2 = search(root,wrongNode[1])
        swichNode1Val = node1.val
        swichNode2Val = node2.val
        node1.val = swichNode2Val
        node2.val = swichNode1Val

```
