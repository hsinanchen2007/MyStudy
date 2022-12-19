我将这题看做是24题的升级版，同时解24的方法（递归法）同样也可以用到此题。
```
class Solution:
    def reverseKGroup(self, head: ListNode, k: int) -> ListNode:
        p = head
        index = 0
        while index!=k and p:
            p = p.next
            index +=1
        if index==k:
            p = self.reverseKGroup(p,k)
            while index>0:
                temp = head.next
                head.next = p 
                p = head
                head =temp
                index -=1
            head = p
        return head
```
递归三要素：
1.返回值：翻转完成的链表
2.递归单元做了什么：k长度的链表翻转
3.结束条件：全部子链表翻转完成（除长度小于K的子链表）
```
递归分步说明：(假定链表1->2->3->4->5->6->7,k=3):
第0轮：
head = 1->..
p = 4->..
    进入第1轮：
    head = 4->..
    p = 7
        进入第二轮：
        head = 7
        return head(7)
    回到第一轮：
    p=7
    循环进行链表翻转：
    index = 3
        temp = 5
        head = 4->7
        p = 4->7
        head = 5->6->4->7
    index = 2
        temp = 6
        head = 5->4->7
        p = 5->4->7
        head =6->5->4->7
    index = 1
        temp =5
        head = 6->5->4->7
        p = 6->5->4->7
        head = 6->5->4->7
    return 6->5->4->7
回到第0轮：
p = 6->5->4->7
循环进行链表翻转：
return 3->2->1->6->5->4->7

```
