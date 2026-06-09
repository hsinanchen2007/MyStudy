### 解题思路
@powcai
这个大神的代码点醒了我 
怎么去判断是第一次访问
这个代码感觉还拿得出手 哈哈

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
        # 尝试根-右-左
        res=[]
        def helper(root,x) :
            if not root :
                return 
            # 怎么保证是该层第一次访问呢？
            if x==len(res) :
                res.append(root.val)
            helper(root.right,x+1)
            helper(root.left,x+1)
        helper(root,0)
        return res
```