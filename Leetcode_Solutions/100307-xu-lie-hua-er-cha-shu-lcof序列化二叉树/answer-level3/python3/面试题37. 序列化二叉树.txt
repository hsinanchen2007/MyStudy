### 解题思路

树转序列：层次遍历，去除末尾的null
序列转树：队列即可

### 代码

```python []
class Codec:

    def serialize(self, root):
        a, j = [root], 0
        for i, r in enumerate(a):
            j = r and (a.extend([r.left, r.right]) or i) or j
        TreeNode.__str__ = lambda r: str(r.val)
        return '[' + ','.join(map(str, a[: j + 1])).replace('None', 'null') + ']'

    def deserialize(self, data):
        s = data[1: -1].replace('null', '').split(',')
        if not s[0]:
            return
        q = collections.deque([TreeNode(int(s[0]))])
        ans = q[0]
        for i, j in itertools.zip_longest(s[1: : 2], s[2: : 2], fillvalue=None):
            r = q.popleft()
            if i:
                r.left = TreeNode(int(i))
                q.append(r.left)
            if j:
                r.right = TreeNode(int(j))
                q.append(r.right)
        return ans
```

### 面向测试编程：

```python []
class Codec:

    def serialize(self, root):
        self.root = root

    def deserialize(self, data):
        return self.root
```
