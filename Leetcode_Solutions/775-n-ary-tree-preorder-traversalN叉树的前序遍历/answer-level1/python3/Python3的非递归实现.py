
```python []
class Solution:
    def postOrder(self, root: Node):
        list = []
        if root is None:
            return list
        stack = []
        stack.append(root)
        while stack:
            node = stack.pop(-1)                   #pop(-1)表示出栈，弹出栈顶元素
            list.append(node.val)
            if node.children:
                length = len(stack)                #记录栈的元素个数
                for child in node.children:
                    stack.insert(length, child)    #把孩子节点插入length的位置，相当于倒序插入
        return list



