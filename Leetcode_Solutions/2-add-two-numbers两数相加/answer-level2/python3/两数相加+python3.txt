### 解法1：创建一个新的链表
```python []
class Solution(object):
    def addTwoNumbers(self, l1, l2):
        target = ListNode(0)   # 作为根节点的引用
        p = target
        add = 0    # 作为上一次相加是否需要进1的依据
        while l1 and l2:
            p.next = ListNode((l1.val+l2.val+add)%10)
            add = (l1.val+l2.val+add)//10
            p, l1, l2 = p.next, l1.next, l2.next
        l1 = l1 if l1 else l2
        while add:
            if l1:
                p.next = ListNode((l1.val+add)%10)
                add = (l1.val+add)//10
                p, l1 = p.next, l1.next
            else:
                p.next = ListNode(add)
                p = p.next
                break
        p.next = l1 
        
        return target.next
```
