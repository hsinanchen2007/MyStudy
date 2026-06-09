非递归方法，
1.找出第一个树的叶子
2.再找第二个树的叶子（两层非递归遍历的嵌套）
3.直接进行比较值是否相等。如果相等就重复上1，2操作，不相等就直接return false。
这样可以在中途退出，效率会更高
```
    def leafSimilar(self, root1: TreeNode, root2: TreeNode) -> bool:
        stack1 = []
        stack2 = []
        leaf_val = 0
        while root1 or stack1:
            while root1:
                stack1.append(root1)
                root1 = root1.left
            if stack1:
                t1 = stack1.pop()
                root1 = t1.right
                if not (t1.left or t1.right):
                    leaf_val = t1.val
                    while root2 or stack2:
                        while root2:
                            stack2.append(root2)
                            root2 = root2.left
                        if stack2:
                            t2 = stack2.pop()
                            root2 = t2.right
                            if not (t2.left or t2.right):
                                if leaf_val != t2.val:
                                    return False
                                else:
                                    break
        return True
``````
代码块
```
