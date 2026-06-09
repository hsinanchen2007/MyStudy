
### 第一种方案: 非递归实现方法
```
    def isValidBST(self, root: TreeNode) -> bool:
        """
        思路:利用中遍历是升序的特点,后一个值比前一个值大来进行验证
        """
        if root is None: 
            return True
        stack = []
        cur = root
        last_val =  float('-inf')
        while cur or len(stack):
            if cur is not None:
                stack.append(cur)
                cur = cur.left
            else:
                node = stack.pop()
                if node.val <= last_val:
                    return False
                cur = node.right
                last_val = node.val
        return True
```

#### 第一种方法复杂度分析
时间复杂度: 需要遍历所有节点 所以时间复杂度为O(n)
空间复杂度: 需要开辟一个栈空间 所以空间复杂度为 O(n)

### 递归实现
```
    def isValidBST1(self, root: TreeNode) -> bool:
        """
        思路: 中序遍历  因为二叉搜索树的中序遍历是升序或者降序排列
        """
        if root is None: return True
        
        if not self.isValidBST(root.left): 
            return False
        if self.last and root.val <= self.last:
            return False
        last = root.val
        
        if not self.isValidBST(root.right):
            return False
        return True
```

#### 第二种复杂度分析
时间复杂度: 同样需要遍历所有节点 所以时间复杂度为O(n)
空间复杂度: 每迭代一次都需要一个变量, 总共需要递归迭代n次, 所以空间复杂度也为 O(n)