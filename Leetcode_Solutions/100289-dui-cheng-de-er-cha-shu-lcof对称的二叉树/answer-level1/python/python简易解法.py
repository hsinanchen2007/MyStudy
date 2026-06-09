一起组队刷题打卡，微博 [@爱编程的周鸟](https://weibo.com/iosxxoo) 求关注求交流。

### 解题思路
思路1. 正常的层序遍历

思路2. 两种中序遍历

- 1. 左->根->右
- 2. 右->根->左

### 代码

```python
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
def isEqual(p1, p2):
    if not p1 and not p2:
        return True
    elif p1 and p2 and p1.val == p2.val:
        return True
    else:
        return False

class Solution(object):
    def isSymmetric(self, pRoot):
        """
        :type root: TreeNode
        :rtype: bool
        """
        if not pRoot: return True
        queue = [pRoot]
        while queue:
            n = len(queue)
            if queue[0] != pRoot and n % 2 != 0: 
                return False
            for i in range(n//2):
                if not isEqual(queue[i], queue[-1-i]):
                    return False
            for _ in range(n):
                node = queue.pop(0)
                if not node: continue
                queue.append(node.left)
                queue.append(node.right)
        return True
```