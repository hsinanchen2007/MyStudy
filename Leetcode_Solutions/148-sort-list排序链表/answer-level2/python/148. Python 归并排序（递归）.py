### 解题思路
时间复杂度为O(nlogn)的常见排序方法有两种，分别是快速排序和归并排序，但是对于单链表来说快速排序显然并不有效，因为无法从后向前遍历（理论上也能实现，比较麻烦），所以使用归并排序。两个有序链表的合并操作时间复杂度是O(l1 + l2)的，所以整个归并排序合并的总时间复杂度也是O(nlogn)。
这里简单说一下快速排序和归并排序的步骤：
1. 快速排序：（1）选择基；（2）用基将待排序数组分成左右两部分；（3）进行递归，对左右两部分分别进行以上操作。
2. 归并排序：（1）将线性数据结构（链表或者顺序表）分成左右两部分；（2）分别对两部分进行递归；（3）对递归结果进行合并。

### 代码

```python
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def sortList(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        
        def get_res(head):
            # print(head, '||', head.next)
            if head is None or head.next is None:
                return head
            p = q = head
            # 找到分割点
            while q.next and q.next.next:
                p = p.next
                q = q.next.next
            q = p.next
            p.next = None # 分割两个链
            p = get_res(head)
            q = get_res(q)
            v_head = ListNode(0)
            temp = v_head
            while p or q:
                if not q or p and p.val < q.val:
                    temp.next = p
                    p = p.next
                else:
                    temp.next = q
                    q = q.next
                temp = temp.next
            return v_head.next

        return  get_res(head)
```