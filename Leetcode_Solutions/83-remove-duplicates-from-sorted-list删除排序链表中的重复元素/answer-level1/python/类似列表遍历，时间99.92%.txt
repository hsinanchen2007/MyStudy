### 解题思路
此处撰写解题思路

### 代码

```python
class Solution(object):
    def deleteDuplicates(self, n):
        h=n
        while n:
            if n.next and n.next.val==n.val:
                n.next=n.next.next
            else:n=n.next
        return h
```