```递归实现 []
def preorderTraversal(self, root: TreeNode) -> List[int]:
        list = []
        #递归思路操作 先根节点 ->左节点->右节点
        if root is None:   # 基准条件
            return []
        list.append(root.val)
        list += self.preorderTraversal(root.left)
        list += self.preorderTraversal(root.right)
        return list
```

```栈实现 []
def preorderTraversal(self, root: TreeNode) -> List[int]:
        if root is None:
            return []
        #用栈操作先压右节点,然后是左节点,这样弹出来的就是先左节点,再右节点
        list = []
        stack = [root] #把根节点放进去
        while stack:                        #基准条件
            item = stack.pop()              #把栈内元素弹出来一个 先把这个节点加入到输出列表 然后 进行判断 该节点是否有 右节点
            if item:
                list.append(item.val)       #先把节点加入输出
                if item.right is not None:  #判断当前弹出的节点是不是拥有右节点
                    stack.append(item.right)
                if item.left is not None:   #判断当前弹出的节点是否拥有左节点
                    stack.append(item.left)
        return list
```