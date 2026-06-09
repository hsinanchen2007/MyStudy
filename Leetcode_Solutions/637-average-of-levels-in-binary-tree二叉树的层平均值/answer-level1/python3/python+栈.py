第一次写的代码：
```
 if not root:
            return []
        stack = [[root]]
        ans = [root.val]
        while stack[0]:
            a = stack.pop(0)
            l = []
            for node in a:
                if node.left:
                    l.append(node.left)
                if node.right:
                    l.append(node.right)
            if l:
                s = sum([x.val for x in l])/len(l)
                ans.append(s)
            stack.append(l)
        return ans
```
参考了一位评论区的大佬的代码后，做了一些修改：
```
stack = [root]
        ans = []
        while stack:
            n = len(stack)
            s = 0
            for i in range(n):
                node = stack.pop(0)
                s += node.val
                if node.left:
                    stack.append(node.left)
                if node.right:
                    stack.append(node.right)
            ans.append(s/n)
        return ans
    
```

