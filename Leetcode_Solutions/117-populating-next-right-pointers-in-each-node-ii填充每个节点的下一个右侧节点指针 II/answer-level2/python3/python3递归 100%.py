第一次写题解，写的不好的地方还请原谅
```
"""
# Definition for a Node.
class Node:
    def __init__(self, val: int = 0, left: 'Node' = None, right: 'Node' = None, next: 'Node' = None):
        self.val = val
        self.left = left
        self.right = right
        self.next = next
"""
class Solution:
    def connect(self, root: 'Node') -> 'Node':
        def helper(root,num):
            if root==None:
                return None
            if num not in dep:
                dep[num]=root
            else:
                root.next=dep[num]
                dep[num]=root
            helper(root.right,num+1)
            helper(root.left,num+1)
        dep={}
        helper(root,0)
        return root
```
结果
![TIM.png](https://pic.leetcode-cn.com/8d11a495092b1fef9b9a322dc7e43e5de465231800cf63ca43972bbb1a11dfe2-TIM.png)
