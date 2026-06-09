```非递归 []
class Solution:
    def preorder(self, root: 'Node') -> List[int]:
        if root is None:
            return []
        stack = [root]                                  #初始化一个数据
        out = []
        while stack:
            temp = stack.pop()                          #先把栈顶的数据弹出来加入到 输出 集
            out.append(temp.val)
            if temp.children:                           #如果该元素有子节点children 则反转加入到 stack 里(因为是前序遍历)
                for item in temp.children[::-1]:
                    stack.append(item)
        return out
```

```递归 []
class Solution:
    def preorder(self, root: 'Node') -> List[int]:
        if root is None:
            return []
        list = []
        #根,左,右
        list.append(root.val)
        if root.children:
            for item in root.children:
                list += self.preorder(item)
        return list
```