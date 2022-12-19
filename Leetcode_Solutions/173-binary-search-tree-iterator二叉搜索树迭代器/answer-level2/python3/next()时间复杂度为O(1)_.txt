使用栈模拟的过程是很清晰的，通过next()在栈中缓存当前左子树的节点，空间复杂度为O(h)。
```
from collections import deque
class BSTIterator:

    def __init__(self, root: TreeNode):
        self.head = root
        self.stack = deque()
        
        while root:
            self.stack.append(root)
            root = root.left

    def next(self) -> int:
        """
        @return the next smallest number
        """       

        cur = self.stack.pop()
        root = cur.right
        while root:   # 使用了循环，复杂度不应该为O(1)?
            self.stack.append(root)
            root = root.left
        
        return cur.val


    def hasNext(self) -> bool:
        """
        @return whether we have a next smallest number
        """
        return len(self.stack) > 0
```
但是很多小伙伴会对next()中的循环操作的复杂度感到疑惑，认为既然加入了循环在里面，那时间复杂度肯定是大于O(1)不满足题目要求的。

仔细分析一下，该循环只有在节点有右子树的时候才需要进行，也就是**不是每一次操作都需要循环**的，循环的次数加上初始化的循环总共会有O(n)次操作，均摊到每一次next()的话平均时间复杂度则是**O(n)/n=O(1)**，因此可以确定该实现方式满足O(1)的要求。

这种分析方式称为**摊还分析**，详细的学习可以看看**《算法导论》- 第17章 摊还分析**