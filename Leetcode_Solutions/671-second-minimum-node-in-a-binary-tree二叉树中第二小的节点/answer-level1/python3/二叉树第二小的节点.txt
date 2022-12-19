排序的问题，我们很容易想到中序遍历，然后根据题意是找第二个不同的数字节点，所以一个set（）就可以解决问题
```
 if not root or not root.left or not root.right:
            return -1
        res = []
        self.order(root,res)
        s = set()
        for i in res:
            if i not in s:
                s.add(i)
        if len(s) <2:
            return -1
        return sorted(set(res))[1]

    def order(self,root,res):
        if root:
            self.order(root.left,res)
            res.append(root.val)
            self.order(root.right,res)
```