### 解题思路
此处撰写解题思路

### 代码

```python3

class Solution:
    def reverseBetween(self, head: ListNode, m: int, n: int) -> ListNode:
        # pre_node
        if m == n: return head

        head0 = ListNode(0)
        head0.next = head
        head = head0
        i = 0
        while head0:
            if i == m - 1:
                pre_node = head0
            if i == m:
                cur_node = head0
            if m < i:
                # 反转在此进行
                next_node = head0.next
                head0.next = cur_node
                cur_node = head0
                head0 = next_node
            else:
                head0 = head0.next
            if i == n:
                pre_node.next.next = head0
                pre_node.next = cur_node
                break

            i += 1
        return head.next

```