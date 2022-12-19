一起组队刷题打卡，微博 [@爱编程的周鸟](https://weibo.com/iosxxoo) 求关注求交流。

### 解题思路
左右交换

### 代码

```python
class Solution(object):
    def mirrorTree(self, root):
        if not root:
            return None
        tmp = self.mirrorTree(root.right)
        root.right = self.mirrorTree(root.left)
        root.left = tmp
        return root
```