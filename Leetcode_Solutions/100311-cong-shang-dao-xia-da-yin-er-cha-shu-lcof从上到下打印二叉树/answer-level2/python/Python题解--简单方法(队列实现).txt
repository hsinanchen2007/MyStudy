### 
![image.png](https://pic.leetcode-cn.com/238ea2156e55622bde5c6769972c73f3864f9663141b62022965be3ec459f7eb-image.png)
- 思路很简单,与我之前在题目`32-`中有写到,大家可以去看看

### 代码

```python
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
        while deque:
            out = []
            for i in deque:
                result.append(i.val)
                if i.left:
                    out.append(i.left)
                if i.right:
                    out.append(i.right)
            deque = out  
        return result
```