### 解题思路
此处撰写解题思路
遍历两次，第一次得到总长度
通过n_inorder = count - n + 1找到正向n的值
第二次指针遍历到第n_inorder个值，通过pre.next = cur.next删除第n_inorder个值
注意：
当第n_inorder个值为head指向的值时，即pre = None的情况。

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def removeNthFromEnd(self, head: ListNode, n: int) -> ListNode:
        count = 0
        cur = head
        while cur is not None:
            count += 1
            cur  = cur.next
        n_inorder = count - n + 1

        pre = None
        cur = head
        count1 = 1
        while cur is not None:
            if count1 == n_inorder:
                if pre is None:
                    head = cur.next
                else:
                    pre.next = cur.next
                break
            else:
                count1 += 1
                pre = cur
                cur = cur.next
        return head


```