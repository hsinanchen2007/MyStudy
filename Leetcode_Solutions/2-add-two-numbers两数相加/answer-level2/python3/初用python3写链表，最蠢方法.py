### 解题思路
此处撰写解题思路
第一次接触python的链表，之前都是用C写的，所以沿用的还是C的思路，应该是最蠢的方法了。L最为表头先记录，然后l作为变量一位位记录l1和l2之和。估计是方法比较蠢，所以要考虑的东西比较多，比如while循环完之后，L链表是多出一位的，若此时有进位，则该为为1，否则要把该为去掉，为此我设了l_pre来记录倒数第二个节点。最后用时80ms，击败48.95%，内存消耗13.1MB，击败56.18%。
### 代码

```python3
#Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        l = L = ListNode(None)
        add = 0
        l1_val = l1.val if l1 else 0
        l2_val = l2.val if l2 else 0
        while l1!=None or l2!=None:
            l.val = (l1_val + l2_val+add)%10
            add = int((l1_val + l2_val+add)/10)
            l.next = ListNode(None)
            l_pre = l
            l = l.next
            if l2!=None:
                l2 = l2.next
            if l1!=None:                
                l1 = l1.next
            l1_val = l1.val if l1 else 0
            l2_val = l2.val if l2 else 0
        if add ==1:
            l.val = 1
        else:
            l_pre.next = None
        return L
        
```