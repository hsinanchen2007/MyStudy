执行用时 : 592 ms, 在Populating Next Right Pointers in Each Node II的Python提交中击败了92.17% 的用户
内存消耗 : 54.8 MB, 在Populating Next Right Pointers in Each Node II的Python提交中击败了7.21% 的用户

```
class Solution(object):
    def __init__(self):
        self.seque = []
    def levelOrder(self, root):
        def order(root, i=0):
            if not root:
                return
            if i == len(self.seque):
                self.seque.append([root])
            else:
                self.seque[i].append(root)
                self.seque[i][-2].next = root
            order(root.left, i + 1)
            order(root.right, i + 1)
        order(root)
        return self.seque
    def connect(self, root):
        self.levelOrder(root)
        return root
```