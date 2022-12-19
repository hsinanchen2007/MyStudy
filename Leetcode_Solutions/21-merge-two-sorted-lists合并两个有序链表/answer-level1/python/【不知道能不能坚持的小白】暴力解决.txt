### 解题思路
题目本身没有任何难度，只是要熟悉一下怎么用ListNode。可以把ListNode想象成一个指针，指针指向一个value和一个next，next所指向的东西也必须是一个ListNode。

**本题关键思路**：构建一个船新的List，由于l1和l2都是有序的，所以只要不停的比较l1和l2当前指针的数，小的就弄成一个ListNode赋给那个船新的List，并且把指针指向next一直循环到next为None。

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def mergeTwoLists(self, l1: ListNode, l2: ListNode) -> ListNode:
        # 先构建一个value为0的ListNode头l，并赋给l_idx。此时l_idx等价于l，可以用l_idx来帮这个ListNode串联构建List
        l = ListNode(0)
        l_idx = l
        while l1 and l2:
            # 比较l1和l2的value，以数值小的val构建一个新的ListNode，l_idx.next指向这个新的ListNode
            # 同时数值小的l1或l2指向下一个ListNode，进入循环继续对比
            if l1.val <= l2.val:
                l_idx.next = ListNode(l1.val)
                l1 = l1.next
                l_idx = l_idx.next
            else:
                l_idx.next = ListNode(l2.val)
                l2 = l2.next
                l_idx = l_idx.next
        # 检查l1和l2是否有剩余的ListNode，有的话直接赋给l_idx.next就行了，因为l1和l2都是有序的
        if l1:
            l_idx.next = l1
        if l2:
            l_idx.next = l2
        # 此时由于构建l的时候给了一个0打头，所以要返回l.next才是后面构建的List
        return l.next
            
```