层次遍历 入队时增加标记判断是否为同父
```
class Solution:
    def isCousins(self, root: TreeNode, x: int, y: int) -> bool:
        queue = [(0,root)]  
        newqueue = []
        n = 0
        thislevel = False
        while queue:
            num,node = queue.pop()
            if node:  
                if node.val == x or node.val == y:      #通过标记判断是否同父，判断部分写的比较乱。。。可以优化
                    if thislevel:
                        if thislevel == num:
                            return False
                        else:
                            return True
                    else:
                        thislevel = num          
                newqueue.append((n,node.left))          #入队时增加标记，同一父节点为同一标记
                newqueue.append((n,node.right))
                n += 1                                  #标记+1
            if not queue:
                queue = newqueue                        #一层遍历结束，重置标记
                newqueue = []
                n = 0
                if thislevel:
                    return False                       #同层只有一个目标值，返回False
        return False
```
复杂度分析

时间复杂度：O(N)，一次遍历。

空间复杂度：O(N)，维护一个队列，无需额外空间。