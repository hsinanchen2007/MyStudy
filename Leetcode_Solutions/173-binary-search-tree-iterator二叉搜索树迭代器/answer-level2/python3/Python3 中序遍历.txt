```
class BSTIterator:
    """二叉搜索树迭代器

    二叉搜索树的特点：中序遍历（左，根，右）为有序列表
    """

    def __init__(self, root: TreeNode):
        self.result = self.in_order(root)  # 返回二叉搜索数中序遍历的有序数组  
        

    def next(self) -> int:
        """返回二叉搜索树的下一个最小的数

        @return the next smallest number
        """
        return self.result.pop(0)
    

    def hasNext(self) -> bool:
        """
        @return whether we have a next smallest number
        """
        return self.result
        
    def in_order(self, root:TreeNode) -> List[int]:
        result = []
        def helper(root: TreeNode) -> None:
            if not root: return 
            helper(root.left)
            result.append(root.val)
            helper(root.right)
        helper(root)
        return result
```

利用二叉搜索树的特性：中序遍历为有序数组
1.构造函数的时候执行中序遍历，并指定应用self.result
2.next()函数直接使用self.result出队即可。
3.hasNext()函数直接判断self.result是否为空