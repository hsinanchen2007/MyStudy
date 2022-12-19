### 解题思路
设置一个虚拟头节点，并赋以最小值-inf，便于处理某一节点应该插在头的位置这种复杂情形。
对于每个待插入节点nxt，如果比当前节点cur大，说明已有序就位，直接处理下一节点，否则根据链表的特点，就要从前往后找，找到该插入的位置，进行链表节点重新连接即可。
最后，需要加个特判：如果是空链表，返回空。

### 执行结果
![image.png](https://pic.leetcode-cn.com/9770910dd2b7e6687c2808e385c4be07cd8dec9af4ad6f0ee172eb8def7b58e0-image.png)

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def insertionSortList(self, head: ListNode) -> ListNode:
        if not head:
            return head
        cur, nxt = head, head.next
        dummy = ListNode(float('-inf'))
        dummy.next = head
        while nxt:
            if nxt.val >= cur.val:
                cur, nxt = nxt, nxt.next
            else:
                cur.next = nxt.next
                pre1, pre2 = dummy, dummy.next
                while nxt.val > pre2.val:
                    pre1, pre2 = pre2, pre2.next
                pre1.next = nxt
                nxt.next = pre2
                nxt = cur.next
        return dummy.next
```