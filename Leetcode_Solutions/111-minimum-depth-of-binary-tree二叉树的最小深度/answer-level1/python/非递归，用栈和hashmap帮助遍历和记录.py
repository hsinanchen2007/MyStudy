### 解题思路
![image.png](https://pic.leetcode-cn.com/d00cbd65e7550b692d6769ba5d0d580ece1b1db3babcec530e5c6e8d15c8b2af-image.png)

和最大的那道题不一样在把数据存入res之前要确定这是个叶子结点
且不是根节点
if not pre.right and not pre.left and pre != start:res.append(count[pre])
其他都差不多
同样我还是理解不了递归。。。
像个傻子。。。

### 代码

```python
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def minDepth(self, root):
        if not root : return 0
        if not root.left and not root.right:return 1
        pre,count,stack,start,res=root,{},[],root,[]
        stack.append(pre)
        count[pre]=1
        cur=root.left
        while stack or cur:
            while cur:
                stack.append(cur)
                count[cur]=count[pre]+1
                pre=cur
                cur=cur.left
            if not pre.right and not pre.left and pre != start:res.append(count[pre])
            top=stack.pop()
            pre=top
            cur=top.right
        return min(res)
```