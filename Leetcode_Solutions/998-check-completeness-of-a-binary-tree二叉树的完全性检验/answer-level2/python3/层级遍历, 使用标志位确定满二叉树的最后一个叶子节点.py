从左向右把每一次的节点后入列表中, 然后从头取出. 如果发现该节点的子节点(先左后右)为`None', 那么他的上一个节点就为满二叉树的最后一个叶子节点.如果之后再出现节点那么该树,就不是满二叉树.

```
from collections import deque
class Solution:
    def isCompleteTree(self, root: TreeNode) -> bool:
        memo, flag = deque(), False
        if root: memo.append(root)
        while memo:
            for i in range(len(memo)):
                x = memo.popleft()
                if not flag and x.left: memo.append(x.left) 
                elif x.left: return False
                elif not flag: flag = True
                
                if not flag and x.right: memo.append(x.right) 
                elif x.right: return False
                elif not flag: flag = True
        return True
```

时间复杂度:O(n), 需要遍历整个树, 空间复杂度:O(n), 需要将最后一层的叶子节点压入列表, 满二叉树最后一层右 2/n 个节点, 所以空间复杂度为O(n)