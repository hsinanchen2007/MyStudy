
```
class BSTIterator(object):

    def __init__(self, root):
        """
        :type root: TreeNode
        """
        self.stack = []
        self.res = self.push(root)
        
    def next(self):
        """
        @return the next smallest number
        :rtype: int
        """
        return self.res.pop(0) if self.hasNext() else None

    def hasNext(self):
        """
        @return whether we have a next smallest number
        :rtype: bool
        """
        return True if self.res else False
    
    def push(self, root):
        res = []
        #此条件包含两种特殊情况，stack有值但root为None说明已到底层结点，需要栈弹出新的父节点继续。stack为空root不为空说明是最后一个最右结点
        #stack：当前结点还未遍历的所有父节点
        while root or self.stack: 
            while root:               
                self.stack.append(root)
                root = root.left
            #上面循环跳出，说明root结点的上一结点已是最左端，输出上一结点，开始遍历上一结点的右子树(左->中->右)
            #弹出上一结点
            root = self.stack.pop()
            #因为已是最左，输出
            res.append(root.val)
            #开始遍历右边
            root = root.right
        return res   
```
