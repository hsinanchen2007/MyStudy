步骤1:找到m前的节点与n后的节点
步骤2:翻转m-n的链表
步骤3:将3段相连
需要一个辅助函数reverse用来翻转从m-n的链表，翻转后的链表与后面相连的任务也可以在这个函数里完成。
剩下的工作就是找到m前面的节点。这要分两种情况：
1.m == 1是head节点
2.m  > 1为中间正常节点
m是头结点时，很简单，直接调用reverse即可得到结果
m为正常节点时，只需将m前的节点preRev.next设置成翻转部分的头结点headRev即可
```
class Solution:
    def reverseBetween(self, head: ListNode, m: int, n: int) -> ListNode:
        # m对应节点是头结点，直接翻转
        if m == 1: return self.reverse(head, m, n)
        
        count = 1
        h = head
        while h:    #找到m前一个节点preRev
            if count == m - 1:
                preRev = h 
            h = h.next
            count += 1
        headRev = self.reverse(preRev.next, m, n)
        preRev.next = headRev 
        return head

    def reverse(self, head, m, n):
        '''
        该函数完成m-n的翻转以及翻转后与剩余链表相连两个任务
        '''
        pre, cur = None, head
        #翻转m-n链表
        for _ in range(n - m + 1):
            pre, pre.next, cur = cur, pre, cur.next
        head.next = cur #与剩余链表相连
        return pre    
```
