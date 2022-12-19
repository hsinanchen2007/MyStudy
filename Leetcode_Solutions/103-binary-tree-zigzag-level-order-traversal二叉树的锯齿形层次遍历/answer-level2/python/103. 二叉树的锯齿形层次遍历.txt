### 解题思路
要确保每层的结点顺序正确，就必须使用bfs，但要求锯齿形，所以弄个flag，判断要不要改变方向。下面的代码可以考虑用list模拟queue，会更快点也更省内存，其中使用list.pop(0)来弹出头部元素。

### 代码

```python3
class Solution:
    def zigzagLevelOrder(self, root: TreeNode) :
        if not root:
            return []
        # 队列实现树的层次遍历
        from queue import Queue
        q = Queue()
        q.put(root)
        flag = 0 #奇数则从右向左
        res = []
        while not q.empty():
            tmp = []
            length = q.qsize()
            while length>0:
                node = q.get()
                tmp.append(node.val)
                if node.left:
                    q.put(node.left)
                if node.right:
                    q.put(node.right)
                length-=1
            if flag%2==1:
                tmp.reverse()
            res.append(tmp.copy())
            flag += 1
        return res
```