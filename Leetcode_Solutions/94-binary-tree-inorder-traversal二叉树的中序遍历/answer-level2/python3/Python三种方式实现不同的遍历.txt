想要说的全部都在代码里~

```
def inorderTraverse(root):
    '''👇堆栈实现遍历'''
    stack = []
    pNode = root
    while pNode or stack:
        if pNode:
            stack.append(pNode)
            # 前序遍历
            pNode = pNode.left  # 这边表示一直向左延伸,上面的append会一直增加~
        else:
            node = stack.pop()  # 如果是🍃节点,则会pop两次,将自身和根节点全部pop掉~
            # 中序遍历
            pNode = node.right  # 左边为空,则看右边
    return ret
    # 这个后序遍历不是很好写
```

```
def inorderTraverse2(root):
    '''👇递归实现遍历'''
    lst = []

    def helper(root):
        if root:  # 这边的顺序是正序的，也就是看哪个遍历就按照那个遍历的顺序添加节点~
            # 前序遍历
            helper(root.left)
            # 中序遍历
            helper(root.right)
            # 后序遍历
    helper(root)
    # 这边拿到结果 lst，里面保存着中序遍历的结果~
```

```
def inorderTraverse3(root):
    '''👇访问标记法实现遍历'''
    # 感觉就是DFS
    if not root:
        return []
    nums, stack = [], [(0, root)]
    while stack:
        flag, cur = stack.pop()
        if not flag:
            # 这边的顺序还是要注意的，是反的，因为上面是pop，后进先出！
            
            # 后序遍历 stack.append((1, cur))
            if cur.right:stack.append((0, cur.right))  
            # 中序遍历 stack.append((1, cur))
            if cur.left:stack.append((0, cur.left))
            # 前序遍历 stack.append((1, cur))
        else:
            nums.append(cur.val)
    return nums
```


