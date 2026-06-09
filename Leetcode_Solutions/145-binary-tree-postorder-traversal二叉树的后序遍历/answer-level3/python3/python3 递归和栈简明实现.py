```递归 []
class Solution:
    def postorderTraversal(self, root: TreeNode) -> List[int]:
        list = []
        if root is None:                            #基准条件
            return []
        list += self.postorderTraversal(root.left)  #先添加左节点
        list += self.postorderTraversal(root.right) #再添加右节点
        list += [root.val]                          #最后添加根节点
        return list  
```

```栈 []
class Solution:
    def postorderTraversal(self, root: TreeNode) -> List[int]:
        # 前序遍历 是  根 左 右, 我们把前序遍历改成 根 右 左输出
        if root is None:
            return []
        stack = [root]
        out = []
        while stack:
            item = stack.pop()
            if item:
                out.append(item.val)
                if item.left:
                    stack.append(item.left)
                if item.right:
                    stack.append(item.right)
        #后序遍历为 左右根, 只需要将上一步的输出 倒序
        return out[::-1]
```