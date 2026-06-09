### 解题思路
此处撰写解题思路

### 代码

```python
class Solution(object):
    def deleteDuplicates(self, n):
        h=n
        n=ListNode(0)
        n.next=h
        tmp=n
        while True:
            if tmp.next and tmp.next.next and tmp.next.val==tmp.next.next.val:
                key=tmp.next.val
                tmp.next=tmp.next.next.next
                while tmp.next and tmp.next.val==key:
                    tmp.next=tmp.next.next
            else:
                tmp=tmp.next
                if not tmp:break
        return n.next
            
```