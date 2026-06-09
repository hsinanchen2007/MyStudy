while 是新节点, gray 是旧节点, 
如果为新节点, 入栈的顺序 我 3, 2, 1, 
如果为前序遍历则 3右,2左,1当前节点
如果为中序遍历则 3右,2当前,1左
如果为后序遍历则 3当前,2右,1左

出栈为gray, 出栈节点根据level 层级进行append
```
class Solution:
    def levelOrder(self, root: TreeNode) -> List[List[int]]:
        WHITE, GRAY = 1, 0
        level = 0
        stack = [(WHITE, level, root)]
        data = []
        while stack:
            color, lev, root = stack.pop()
            if root is None:
                continue
           
            if color == WHITE:
                
                stack.append((WHITE, lev+1, root.right))# 3
                stack.append((WHITE, lev+1, root.left)) # 2 
                stack.append((GRAY, lev, root)) # 1
            else:
                if len(data)-1 < lev:
                    data.append([])
                data[lev].append(root.val)
                
        return data
        
```

上面的例子很容易改写成递归模式, 或者说很容易根据递归方式写成上面的格式
```
    def levelOrder(self, root: TreeNode) -> List[List[int]]:
        def fn(level, root):
            if root is None:
                return None

            if len(self.data)-1 < level:        # 此3行对应的上面的 else
                self.data.append([])            #
            self.data[level].append(root.val)   #

            fn(level+1, root.left)    # 对应上面的2 
            fn(level+1, root.right)   # 对应上面的1

        level = 0        
        fn(0, root)           
        return self.data
```
