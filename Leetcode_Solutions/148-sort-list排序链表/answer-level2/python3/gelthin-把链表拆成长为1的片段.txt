### 解题思路
把一个长为 n 的链表拆成 n 个长为 1 的链表， 然后两两合并。
同习题 [23. 合并K个排序链表](https://leetcode-cn.com/problems/merge-k-sorted-lists/solution/gelthin-liang-liang-he-bing-by-gelthin/) 的思路。

突然发现这是一种新的分治排序的思路啊，完全不需要递归。有点像建堆，堆的结构是从底部到顶部，每个局部局部搭上去的。
对于数组也可以使用的，但没有链表这么爽快，对于数组，需要记录每段数组开始和结束的位置。


题解[Sort List （归并排序链表）](https://leetcode-cn.com/problems/sort-list/solution/sort-list-gui-bing-pai-xu-lian-biao-by-jyd/) 的第一种递归的思路是完全使用归并排序的分治递归思路。
他人代码写的比我巧妙很多啊
``` python3
class Solution:
    def sortList(self, head: ListNode) -> ListNode:
        if not head or not head.next: 
            return head # termination.

        slow, fast = head, head.next
        while fast and fast.next:
            fast, slow = fast.next.next, slow.next
        mid, slow.next = slow.next, None # save and cut.

        left, right = self.sortList(head), self.sortList(mid)

        h = res = ListNode(0)  # 无需写 h.next = None
        while left and right:
            if left.val <= right.val: 
                h.next, left = left, left.next
            else: 
                h.next, right = right, right.next
            h = h.next  # 只需要这一句就好

        h.next = left if left else right # 这里也是, 可以补一个 None

        return res.next
```
这段代码很好。 


### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def sortList(self, head: ListNode) -> ListNode:
        def sort_2_lists(a, b):
            prehead = ListNode(-1)
            prehead.next = None
            prev = prehead
            while a and b:
                if a.val <= b.val:
                    prev.next = a
                    prev = a # 漏了此导致 bug
                    a = a.next
                else:
                    prev.next = b
                    prev = b
                    b = b.next
            if a:
                prev.next = a
            if b:
                prev.next = b
            return prehead.next

        lists = []
        while head != None: # 把 4->2->1->3 拆开为 4,2,1,3
            p = head
            head = head.next
            p.next = None
            lists.append(p)
        if lists == []:
            return None
            
        new_lists = lists
        while len(new_lists) >= 2: # 两两合并
            result = []
            i = 0
            while i<len(new_lists)-1:
                result.append(sort_2_lists(new_lists[i], new_lists[i+1]))
                i += 2
            if i < len(new_lists): #两两分组， 最后一个落单的那个
                result.append(new_lists[i])  
                # result.append(new_lists) # 偶数时，没有报 bug，因为没有运行    
            new_lists = result

        return new_lists[0]

        
```