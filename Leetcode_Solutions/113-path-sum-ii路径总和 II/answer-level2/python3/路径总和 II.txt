### 解题思路
我的思路：刚开始在节点添加的地方写错了...
	

复杂度分析：                                                             
	• 时间复杂度：o(n)
	• 空间复杂度：o(n)



### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def pathSum(self, root: TreeNode, sum: int) -> List[List[int]]:
        lists = []
        lujing = []
        def helper(root,sum,lujing):
            if not root:
                return None
            sum -= root.val
            children = [root.left,root.right]
            if not any(children) and sum == 0:
                lujing.append(root.val)
                lists.append(lujing)
            for child in children:
                if child:
                    helper(child,sum,lujing+[root.val])
        helper(root,sum,lujing)
        return lists

            
```