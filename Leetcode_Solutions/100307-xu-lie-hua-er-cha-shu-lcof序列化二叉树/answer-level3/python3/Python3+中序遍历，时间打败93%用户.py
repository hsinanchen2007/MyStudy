### 解题思路
1. 编码：先序遍历，需要注意的是，在遇到空节点时，我们要把一个`None`加入到序列中
2. 解码：递归解码，`solve(data, i)`寻找`data`中从位置`i`开始的部分序列所构成的子树，它的返回值为`(root, k)`，`root`为子树的根，`k`为下一个子树所对应的序列的起点，也就是`i`+当前子树的节点数(包含空的叶子节点)。从前往后遍历序列，如果当前元素为空，则返回空树，并令当前位置+1；否则返回以当前元素为根的子树：首先用当前元素的值建立根节点，然后依次建立左右子树：先令当前位置`i=i+1`，并从当前位置递归建立左子树，假设递归返回时当前位置在`j`，则从`j`位置再递归建立右子树，最后返回根节点。

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Codec:

    def serialize(self, root):
        """Encodes a tree to a single string.
        
        :type root: TreeNode
        :rtype: str
        """
        if root == None:
            return [None]
        ans = [root.val] + self.serialize(root.left) + self.serialize(root.right)
        return ans

    def deserialize(self, data):
        """Decodes your encoded data to tree.
        
        :type data: str
        :rtype: TreeNode
        """
        def solve(data, i):
            if i >= len(data) or data[i] == None:
                return (None, i+1)
            root = TreeNode(data[i])
            lchild, k = solve(data, i+1)
            rchild, j = solve(data, k)
            root.left, root.right = lchild, rchild
            return (root, j)
        return solve(data, 0)[0]

# Your Codec object will be instantiated and called as such:
# codec = Codec()
# codec.deserialize(codec.serialize(root))
```