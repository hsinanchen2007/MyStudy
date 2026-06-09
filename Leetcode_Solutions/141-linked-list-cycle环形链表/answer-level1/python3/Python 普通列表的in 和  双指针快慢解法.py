### 解题思路

比较有意思的是快慢双指针，可以有效的减少空间复杂度和时间复杂度的匹配次数

### 代码

```python
class Solution:
    def hasCycle(self, head: ListNode) -> bool:
        '''
        利用列表寻找是否存在重复的对象，时间复杂度O（n）,空间复杂度O（n）
        if not head:
            return head
        m = []
        while head:
            if head in m:
                return True
            m.append(head)
            head = head.next
        return False
        '''
        # 快慢双指针追赶碰撞解法，时间复杂度为O（n）,空间复杂度为O（1）
        if not head:
            return head
        slow = head
        quick = head
        while quick and slow:
            # 这里因为quick是跳两次，所以要判断quick和quick.next是否都为空，否则会报NoneType的异常
            slow = slow.next
            if quick.next:
                quick = quick.next.next
            else:
                return False
            if quick is slow:
                return True
        return False
```