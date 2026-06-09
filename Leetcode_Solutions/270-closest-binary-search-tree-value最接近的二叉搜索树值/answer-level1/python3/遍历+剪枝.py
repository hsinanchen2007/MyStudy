```
class Solution:
    def closestValue(self, root: TreeNode, target: float) -> int:
        def search0(root, target):
            m = root.val
            dif = abs(target-m)
            stack = []
            n = root
            while n or stack:
                while n:
                    stack.append(n)
                    if n.val<target:
                        break
                    n = n.left
                n = stack.pop()
                d = abs(n.val-target)
                if d<dif:
                    dif = d
                    m = n.val
                n = n.right
            return m
        def search1(root, target):
            m = root.val
            dif = abs(target-m)
            stack = [root]
            n = root
            while stack:
                n = stack.pop()
                if n.val == target:
                    return n.val
                elif n.val>target:
                    d = n.val - target
                    if n.left:
                        stack.append(n.left)
                else:
                    d = target - n.val
                    if n.right:
                        stack.append(n.right)
                if d<dif:
                    dif = d
                    m = n.val
            return m
        return search1(root, target)
```
