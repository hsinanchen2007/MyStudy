
思路: 采取中序遍历, 比较相邻两个元素之差, 这里的差是绝对值

#### 非递归实现
```
    def minDiffInBST(self, root: TreeNode) -> int:
        """
        思路:中序遍历 升序输出 比较相邻两个元素之差
        """
        if root is None: 
            return 0
        
        curr = root
        stack = []
        min_value = float('inf')
        last_val = None

        while curr or len(stack):
            if curr is not None:
                stack.append(curr)
                curr = curr.left
            else:
                node = stack.pop()
                if last_val is not None:
                    min_value = min(abs(node.val - last_val), abs(min_value))
        
                last_val = node.val
                curr = node.right
                
        return min_value   
```

##### 复杂度分析
时间复杂度: 需要遍历一遍, 所以时间复杂度为O(n)
空间复杂度: 开辟一个栈空间, 所以空间复杂度为 O(n)


#### 递归实现
```
    def __init__(self):
        self.last_node = None
        self.min_value = float('inf')
        
    def minDiffInBST(self, root: TreeNode) -> int:
        """
        思路:中序遍历 升序输出 比较相邻两个元素之差
        """
        if root is None: 
            return 0
        
        self.minDiffInBST(root.left)
        if self.last_node:
            self.min_value = min(abs(root.val - self.last_node.val), abs(self.min_value))
        self.last_node = root
        
        self.minDiffInBST(root.right)
        
        return self.min_value 
```

##### 复杂度分析
时间复杂度: O(n)
空间复杂度:  O(1) (ps:这里self.min_value我用的全局变量, 操作的应该是同一块空间, 所以我认为空间复杂度为O(1), 这里我不是很清楚,欢迎大神指正)