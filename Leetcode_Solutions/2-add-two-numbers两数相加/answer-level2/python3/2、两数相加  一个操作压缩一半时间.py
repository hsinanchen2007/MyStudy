（今天开始刷题啦！

拿到题，先用数学思想想一下怎么做最简便，发现大致思路同官方题解，不再赘述。

一开始运行时间120ms，时间上击败5%，让我怀疑人生。
在参照了大家的解法之后，觉得应该是我的几个if判断语句后赋值过于累赘：
于是将
```
if(q == None):
    rp, rq = p.val, 0
    elif(p == None):
        rp, rq = 0, q.val
    else:
        rp, rq = p.val, q.val
```
修改成
```
rp = p.val if p else 0              # 修改
rq = q.val if q else 0
```
运行时间68ms，击败上击败86%，舒服了一些。

但想请教各位大神如何可以进一步提升效率！

```
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        p, q = l1, l2
        node = ListNode(0)
        r = node
        add = 0

        while(q != None or p != None):
            #if(q == None):
            #    rp, rq = p.val, 0
            #elif(p == None):
            #    rp, rq = 0, q.val
            #else:
            #    rp, rq = p.val, q.val
            rp = p.val if p else 0              # 修改
            rq = q.val if q else 0
            
            res = rp+rq+add
            if(res >= 10):
                add = 1
                final = res%10
            else:
                add = 0
                final = res
            new = ListNode(final)
            r.next = new

            r = r.next
            if(q!=None): q = q.next
            if(p!=None): p = p.next

        if(add == 1):           # 进位
            new = ListNode(1)
            r.next = new
            
        return node.next
            
```
