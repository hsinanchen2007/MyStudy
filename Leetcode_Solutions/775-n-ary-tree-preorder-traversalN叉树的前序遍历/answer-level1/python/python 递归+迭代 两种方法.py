### 递归算法
```python
# Definition for a Node.
class Node(object):
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children
"""
class Solution(object):
    def preorder(self, root):
        """
        :type root: Node
        :rtype: List[int]
        """
        if not root:
            return []
        ans=[]
        def preTreversal(node):
            if not node:
                return 
            ans.append(node.val)#先将当前节点的值写入数组ans[]中
            for cur in node.children:#前序遍历，对于每一个孩子，依此递归
                preTreversal(cur)
        preTreversal(root)
        return ans
```


### 迭代算法

```python
"""
# Definition for a Node.
class Node(object):
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children
"""
class Solution(object):
    def preorder(self, root):
        """
        :type root: Node
        :rtype: List[int]
        """
        if not root:
            return []
        stack,ans=[root],[]
        while stack:#树遍历迭代，判断条件都是这个
            cur=stack.pop(-1)
            ans.append(cur.val)
            stack.extend(cur.children[::-1])#注意是extend, 逆序压入栈中
        return ans

```