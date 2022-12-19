二进制编码法，利用二进制编码得到路劲。遍历：0往左边走，1往右边走。

如果n=3，二进制编码是11，去掉第一个，那就是1。因此在右边。
如果n=5，二进制编码是101，去掉第一个，那就是01。因此是：左边2，右边5。
如果n=12，二进制编码是1100，去掉第一个，那就是100。因此是：右边3，左边6，左边12。

程序实现时去掉了第一个和最后一个，小调整，也可以严格按照二进制实现。
```
class CBTInserter:
    def __init__(self, root: TreeNode):
        self._dummy = TreeNode(-1)
        self._dummy.right = root
        self._n = self.size(root)
    
    def size(self, root: TreeNode):
        if not root: 
            return 0
        return self.size(root.left) + self.size(root.right) + 1
        
    def insert(self, v: int) -> int:
        self._n += 1
        paths = bin(self._n)[3:-1] # 二进制，去掉第一个和最后一个
        p = self._dummy.right
        for i in paths:
            p = p.left if i == '0' else p.right
        
        # 插入
        if not p.left:
            p.left = TreeNode(v)
        else:
            p.right = TreeNode(v)
        return p.val

    def get_root(self) -> TreeNode:
        return self._dummy.right
```
