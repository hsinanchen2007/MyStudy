### 解题思路
此处撰写解题思路

### 代码

```python3


class Solution:
    def reverseKGroup(self, head: ListNode, k: int) -> ListNode:
        if k == 1:
            return head
        count = 0
        flag = False
        # 判断够不够k个
        head_temp = head
        while True:
            if head_temp is None:
                flag = False
                break
            count += 1
            if count >= k:
                flag = True
                break
            head_temp = head_temp.next
        if not flag:
            return head
        # 反转
        tail = head
        while True:
            tail_next = tail.next
            if tail_next == head_temp:
                tail_next.next = self.reverseKGroup(tail_next.next, k)
            tail.next = tail_next.next
            tail_next.next = head
            head = tail_next
            if head == head_temp:
                break
        return head

```