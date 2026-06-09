### 解题思路
这题乍一看，直接把所有的左子树扔掉不就可以了？
不对，如果某棵树只有左子树不就凉凉了吗
再考虑考虑
我们从右边看的话，看到的数是什么？是每一层的最右边那个。
那么我们层序遍历，然后将每层的最后一个存起来，就可以了


### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def rightSideView(self, root: TreeNode) -> List[int]:
        if not root:
            return []
        stack=[root]
        res=[]
        while len(stack)>0:
            current_level=stack.copy()
            res.append(current_level[-1].val)
            stack=[]
            for i in current_level:
                if i.left:
                    stack.append(i.left)
                if i.right:
                    stack.append(i.right)
        return res
            
            
```