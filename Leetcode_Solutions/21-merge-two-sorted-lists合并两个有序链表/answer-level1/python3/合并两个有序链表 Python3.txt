### 解题思路
解法1：递归
执行用时 :44 ms, 在所有 Python3 提交中击败了46.88%的用户
内存消耗 :13.6 MB, 在所有 Python3 提交中击败了5.04%的用户

思路：
当l1.val<l2.val时，新的链表的val应该是l1.val，新的链表的next应该是l1剩下的链表与l2组成的链表
l1剩下的链表与l2组成的链表仍然可以用mergeTwoLists这个函数来计算，因此形成了递归
当l1.val<=l2.val时，同理
当l1为空时，直接返回l2
当l2为空时，同理

注释部分是官方解法，显然看起来更简洁
### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def mergeTwoLists(self, l1: ListNode, l2: ListNode) -> ListNode:
        if not l1:
            return l2
        elif not l2:
            return l1
        elif l1.val < l2.val:
            l_new = ListNode(l1.val)
            l_new.next = self.mergeTwoLists(l1.next, l2)
            return l_new
            # l1.next = self.mergeTwoLists(l1.next, l2)
            # return l1
        else:
            l_new = ListNode(l2.val)
            l_new.next = self.mergeTwoLists(l2.next, l1)
            return l_new
            # l2.next = self.mergeTwoLists(l2.next, l1)
            # return l2
```

### 解题思路
解法2：指针
执行用时 :40 ms, 在所有 Python3 提交中击败了68.64%的用户
内存消耗 :13.6 MB, 在所有 Python3 提交中击败了5.04%的用户

思路：
新创建一个链表，l_pre和p都指向这个链表
然后p负责向后移动，不停添加p.next
当l1.val<l2.val时，将l1添加进去，然后p和l1都向后移动
当l1.val>=l2.val时，同理
当l1为空时，直接将l2添加进去
当l2为空时，同理
当l1和l2同时为空时，跳出循环

官方写法更为简洁，将l1和l2有一个为空或全为空的情况，和l1和l2没有任何一个为空的情况分开
这样一来循环的条件就是whle l1 and l2
l1和l2有一个为空或全为空的情况是：prev.next = l1 if l1 is not None else l2

注意：
Python下面编程其实是没有指针的，实际编程一般用引用来代替，比如像ListNode这样来定义一个类
### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def mergeTwoLists(self, l1: ListNode, l2: ListNode) -> ListNode:
        l_pre = p = ListNode(-1)
        
        while l1 or l2:
            if not l1:
                p.next = l2
                l2 = l2.next
            elif not l2:
                p.next = l1
                l1 = l1.next
            elif l1.val < l2.val:
                p.next = l1
                l1 = l1.next
            else:
                # 包含了l1.val==l2.val的情况
                p.next = l2
                l2 = l2.next
            p = p.next
            
        return l_pre.next
```