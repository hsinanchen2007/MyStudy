### 题解思路
一开始想到了层次遍历，但是一想感觉好多if判断好麻烦，然后看了官方题解第二种解法就是层次遍历，很多if判断，不过代码很清晰明了，很好理解。
1. 看见层次遍历就要想到队列，习惯性用了双端队列，注意要先导入deque函数；
2. 首先将根节点加入双端队列queue中，此处需要一个while循环，判断只要队列不为空，就说明遍历还没结束；
     **·** 首先取出队列最左侧的节点（也就是最先添加进去的节点）；
     **·** 判断该节点的值是否为偶数：
         1. 若为偶数：就可继续判断该节点的左节点是否存在————若存在就继续判断左节点的左右节点（即孙子节点）是否存在，若孙子节点存在即可加到res上；该节点的右节点同理。
         2. 不管是否为偶数，判断该节点的左右节点是否存在，若存在就添加进队列；
3. 最后返回res即可。 

### 代码
```
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

from collections import deque
class Solution:
    def sumEvenGrandparent(self, root: TreeNode) -> int:
        if not root:
            return 0
        queue = deque([root])
        res = 0
        while queue:
            node = queue.popleft()
            if node.val % 2 == 0:
                if node.left:
                    if node.left.left:
                        res += node.left.left.val
                    if node.left.right:
                        res += node.left.right.val
                if node.right:
                    if node.right.left:
                        res += node.right.left.val
                    if node.right.right:
                        res += node.right.right.val
            if node.left:
                queue.append(node.left)
            if node.right:
                queue.append(node.right)
        return res
```
