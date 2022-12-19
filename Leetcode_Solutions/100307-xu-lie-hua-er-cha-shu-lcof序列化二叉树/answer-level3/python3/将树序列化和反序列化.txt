### 解题思路
前序遍历，递归，因为前序遍历，生成序列的第一个值是root的值，方便重建
后续遍历和前序的方向相反，也可以重建树
只有，中序遍历的时候，不能重建树，因为无法确定总根的位置，每次的子树都找不到总根，因此需要前序和后序作为找根节点的辅助。

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Codec:
    """将树序列化和反序列化"""
    
    def __init__(self):
        self.seria = []

    def serialize(self, root):
        """Encodes a tree to a single string.
            前序遍历，得到序列
        """
        if root is None:
            self.seria.append(None)
            return
        self.seria.append(root.val)
        self.serialize(root.left)
        self.serialize(root.right)
        return self.seria

    def deserialize(self, s):
        
        if s is None:
            # 当数组s是空时，重构的树也是none，
            return None

        num = s.pop(0)
        if num is not None:
            root = TreeNode(num)
            root.left = self.deserialize(s)
            root.right = self.deserialize(s)
        else:
            return None
        # 每次返回的root，是上一层root的left,或者right。最后一次return树的根节点的    
        return root

```