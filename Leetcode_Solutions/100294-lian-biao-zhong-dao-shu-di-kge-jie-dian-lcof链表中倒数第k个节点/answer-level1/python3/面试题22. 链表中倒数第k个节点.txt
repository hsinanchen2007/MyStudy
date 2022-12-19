### 解题思路
先获取列表的长度，然后再次遍历到达目标节点即可。

### 代码

```python
class Solution:
    def getKthFromEnd(self, head: ListNode, k: int) -> ListNode:
        # 遍历一遍链表，获取链表的长度
        dummy = head
        count = 0
        while head:
            count += 1
            head = head.next
        for _ in range(count - k):
            dummy = dummy.next
        return dummy
        
```
### 复杂度分析
- 时间复杂度：$O(N)$。
- 空间复杂度：$O(1)$