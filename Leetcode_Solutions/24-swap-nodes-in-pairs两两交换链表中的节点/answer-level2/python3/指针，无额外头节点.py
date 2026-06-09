### 解题思路
因为无额外头节点，所以，交换的时候，由两种情况，头节点交换，和非头节点交换。
共4个指针，迭代指针，p1指针，p2指针，helper辅助交换指针
头节点的交换比较简单，
非头节点的交换需要再借助一个指针。

4个指针可以压缩为3个指针，p2可以用p1.next代替

加上额外头节点，可以将特殊情况普适化。


### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def swapPairs(self, head: ListNode) -> ListNode:
        i = head
        count = 0
        while i != None:
            if count %2 == 0:
                p1 = i
                i = i.next
            elif count == 1:
                p2 = i
                i = i.next
                # swap
                p2.next = p1
                p1.next = i
                head = p2
                # helper
                helper = p1
            else:
                p2 = i
                i = i.next
                # swap
                helper.next = p2
                p2.next = p1
                p1.next = i
                # helper
                helper = p1
            count +=1    
        return head



```