### 双栈法
![image.png](https://pic.leetcode-cn.com/01085b996de6d86a78e606cf4e3929cf4786f9ec9f65909d682eecf923d07f5c-image.png)

### 代码
```
class Solution(object):
    def levelOrder(self, root):
        """
        :type root: TreeNode
        :rtype: List[List[int]]
        """
        if not root:
           return []
        deque = [root]
        result = []
        times = 1
        while deque:
            out = []
            temp = []
            while deque:
                k = deque.pop()
                temp.append(k.val)
                if times % 2:
                    if k.left:
                        out.append(k.left)
                    if k.right:
                        out.append(k.right)
                else:
                    if k.right:
                        out.append(k.right)
                    if k.left:
                        out.append(k.left)
            result.append(temp)
            deque = out
            times += 1
        return result

```


### 解题思路
![image.png](https://pic.leetcode-cn.com/fd878f0438430f79b3a7d82d340adf7c2f00425167ec12f7dca6011f8896e533-image.png)

- 这道题和之前的<从上到下打印二叉树>的思路是一致
- 我的做法是,设置一个行变量`times`,奇数行保存从左往右的输出,偶数行保存从右往左的输出

### 代码

```python
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def levelOrder(self, root):
        """
        :type root: TreeNode
        :rtype: List[List[int]]
        """
        if not root:
           return []
        deque = [root]
        result = []
        times = 1
        while deque:
            out = []
            temp = []
            for i in deque:
                temp.append(i.val)
                if i.left:
                    out.append(i.left)
                if i.right:
                    out.append(i.right)
            if times % 2:
                result.append(temp)
            else:
                result.append(temp[::-1])
            deque = out
            times += 1 
        return result





```