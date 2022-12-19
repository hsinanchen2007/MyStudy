1. 递归方法
- 处理node节点, 有node.val值 放入list中;
- node.children则需要 逐一递归处理, 处理模式和第一条一致;

```
# 简单的写还是递归
class Solution(object):
    def __init__(self):
        self.L = []
    def preorder(self, root):
        if root != None:
            self.L.append(root.val)
            map(lambda i: self.preorder(i), root.children)
        else:
            return None
        return self.L
```

2. 非递归方法
**入栈, 出栈方式, 注意的是: children 需要逆序的存入至Stack中**
```
class Solution(object):
    def preorder(self, root):
        # 每次stack以pop的方法
        Stack = [root]
        L = []
        # while len(Stack) != 0:
        while Stack:
            # 每次都pop()出去
            node = Stack.pop()
            if node != None:  
                L.append(node.val)
                # 此时[child4, child3, child2, child1] 逆序输出
                # 先处理的是child1, child1 可能还有children
                for child in node.children[::-1]:
                    Stack.append(child)
        return L
```
