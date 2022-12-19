```
class Solution(object):
    def __init__(self):
        self.seque = []

    def levelOrder(self, root):
        def order(root, i=0):
            if not root:
                return
            #层号=层数 重新开辟一层存储节点数据
            if i == len(self.seque):
                self.seque.append([root.val])
            #如果层数>层号 当前层存储节点数据
            else:
                self.seque[i].append(root.val)
            order(root.left, i + 1)
            order(root.right, i + 1)

        order(root)
        return self.seque
```