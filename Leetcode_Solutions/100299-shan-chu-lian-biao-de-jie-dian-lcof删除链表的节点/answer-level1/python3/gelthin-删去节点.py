### 解题思路
关于删去节点有很多变体， 例如 [237. 删除链表中的节点](https://leetcode-cn.com/problems/delete-node-in-a-linked-list/)  给了一个非末尾节点的指针，然后需要删去此节点。


题解中 [详解 时间复杂度从 O(N) 到 O(1)](https://leetcode-cn.com/problems/shan-chu-lian-biao-de-jie-dian-lcof/solution/cong-on-dao-o1-by-ml-zimingmeng/) 
讲的很详细。




### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def deleteNode(self, head: ListNode, val: int) -> ListNode:
        prehead = ListNode(-1)  # 虚拟头节点，方便在开始位置删去
        prehead.next = head
        prev, p = prehead, head
        while p!= None:
            if p.val == val:
                prev.next = p.next
                del p
                break  #题目保证链表中节点的值互不相同
            p = p.next
            prev = prev.next

        return prehead.next
```