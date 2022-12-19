执行用时 :84 ms, 在所有 python3 提交中击败了100.00% 的用户
内存消耗 :16.5 MB, 在所有 python3 提交中击败了100.00%的用户
### 解题思路
这里用的是大部分数据结构书中将二叉树和N叉树转换的定义，对于每个节点递归调用本函数实现转化。

### 代码

```python3
"""
# Definition for a Node.
class Node:
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children
"""
"""
# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None
"""
class Codec:

    # Encodes an n-ary tree to a binary tree.
    def encode(self, root: 'Node') -> TreeNode:
        if root is None:                                    #空节点，返回
            return None
        node = TreeNode(root.val)                           #不空，申请一个TreeNode节点装数据
        if root.children:
            node.left = self.encode(root.children[0])       #第一个孩子作为左子树，对每个节点递归调用本函数
            thenode = node.left
            for i in range(1,len(root.children)):           #剩下的孩子作为右节点接在一起
                thenode.right = self.encode(root.children[i])
                thenode = thenode.right
        return node
        

	# Decodes your binary tree to an n-ary tree.
    def decode(self, data: TreeNode) -> 'Node':
        if data is None:                                    #和编码部分思路类似，空，返回
            return None
        node = Node(data.val)                               #不空，申请一个Node节点装数据
        node.children = []                                  #注意初始化一个列表，不然会报错
        if data.left is None:                               #如果没有左子树，那么肯定没有右子树，返回
            return node
        thenode = data.left                                 #有左子树，那么左节点以及其右节点都作为当前节点的子树
        while thenode:                                      #把使用右节点都作为子树加入列表
            node.children.append(self.decode(thenode))
            thenode = thenode.right
        return node
        

# Your Codec object will be instantiated and called as such:
# codec = Codec()
# codec.decode(codec.encode(root))
```