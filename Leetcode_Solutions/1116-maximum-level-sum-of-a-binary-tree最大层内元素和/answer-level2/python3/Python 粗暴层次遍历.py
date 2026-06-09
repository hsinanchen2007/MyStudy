![image.png](https://pic.leetcode-cn.com/519fa90fc26fa1f7cc36a3f7a6a807e973618d6fc2938fec51620be0a6b4ce98-image.png)


```
'''
层次遍历即可
'''

from queue import Queue
class Solution:
    def maxLevelSum(self, root: TreeNode) -> int:
        que = Queue()

        level = 1
        que.put(root)

        max_val = -0x7fffffff
        ans = -1
        while not que.empty():
            n = que.qsize()

            total = 0
            while n > 0:
                cur = que.get()
                total += cur.val

                for child in [cur.left, cur.right]:
                    if child is not None:
                        que.put(child)
                n -= 1

            if total > max_val:
                max_val = total
                ans = level

            level += 1

        return ans
```
