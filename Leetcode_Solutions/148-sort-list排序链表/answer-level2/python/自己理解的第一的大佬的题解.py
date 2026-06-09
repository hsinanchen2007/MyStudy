### 解题思路
非递归归并
翻写第一的大佬

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def sortList(self, head: ListNode) -> ListNode:
        h = head
        legth = 0 
        intv = 1
        while h:
            h = h.next
            legth += 1
        
        res = ListNode(0)
        res.next = head
        while intv < legth:
            h = res.next
            #设置傀儡
            pre = res
            while h:
                x1, i = h, intv

                #找到间隔距离的下一起点
                while i and h:
                    h = h.next
                    i = i-1 
                #如果链表已经走完还没有到达指定长度就break
                if i: break 
                x2, i = h, intv
                while i and h: 
                    h, i = h.next, i - 1
                #如果间隔不够把链表走完，那么i =0，x1和x2的长度都是间隔intv。反之，如果链表长度小于间隔，则剩余段长度为intv - i
                #因为要原地修改，所以无法把链表断掉，用长度来确定链表何时走完之前规划好的间隔
                length_x1, length_x2 = intv, intv - i
                # 归并上方两链表
                while length_x1 and length_x2:
                    if x1.val < x2.val: 
                        pre.next, x1, length_x1 = x1, x1.next,length_x1 - 1
                    else: 
                        pre.next, x2, length_x2 = x2, x2.next,length_x2 - 1
                    pre = pre.next
                pre.next = x1 if length_x1 else x2
                #两个间隔长度可能不够将整个链表走完，所以要对sort完部分的剩余部分进行相同操作
                while length_x1 > 0 or length_x2 > 0: 
                    pre, length_x1, length_x2 = pre.next, length_x1 - 1, length_x2 - 1
                #起点设于未排序部分的第一个节点，直到所以节点走完
                pre.next = h 
            intv = intv*2
        return res.next





        
```