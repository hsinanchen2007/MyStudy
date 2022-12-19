```
def diameterOfBinaryTree(self, root: TreeNode) -> int:
    self.value = 1
    def depth(root):
        if not root:
            return 0
        left = depth(root.left)
        right = depth(root.right)
        self.value = max(self.value, left+right+1)
        return max(left,right)+1
    depth(root)
    return self.value-1
```

1.以当前节点为根节点，左子树和右子树的最大值+1（本身）作为当前节点的长度，作为返回值，因为该节点是作为上一层节点的子树，迭代所需的是子树的长度，因此返回的是当前节点的长度
return max(left,right)+1
2.用左子树的长度+右子树的长度+1（本身）作为当前的节点的节点数与最终结果进行比较，得到最长路径
self.value = max(self.vale, left+right+1)
3.当为最后节点时，左右子树迭代空，返回0，但是该节点返回0+1=1作为该节点长度，因此最终返回值没有问题
if not root:return 0
4.最终返回值是节点数-1，因为长度为节点数-1
return self.value - 1
5.初始值为1，避免空树时返回值为负，如果树长度为1，则同样返回0
self.value = 1


