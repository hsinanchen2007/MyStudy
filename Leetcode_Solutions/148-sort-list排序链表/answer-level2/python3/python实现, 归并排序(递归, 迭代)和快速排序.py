1. 归并排序的迭代写法思路比较简单，但是代码写的比较low，也不知道空间复杂度满不满足要求
2. 快速排序不知道为什么会超时
希望大佬们看看，给出一些宝贵的意见

- 归并排序--递归
```
class Solution:
    def sortList(self, head: ListNode) -> ListNode:
        #归并排序--递归
        if not head or not head.next:
            return head
        mid = self.getMid(head)
        left = self.sortList(head)
        right = self.sortList(mid)
        return self.merge(left,right)
        
    def getMid(self,head):
        if not head or not head.next:
            return head
        pre = head
        slow = head.next
        fast = head.next
        while fast and fast.next:
            pre = slow
            slow = slow.next
            fast = fast.next.next
        pre.next = None
        return slow
    
    def merge(self,left,right):
        res = ListNode(-1)
        pre = res
        while left and right:
            if left.val <= right.val:
                pre.next = left
                left = left.next
            else:
                pre.next = right
                right = right.next
            pre = pre.next
            #这一步是在消除left,right原链表的连接
            pre.next = None
        if left:
            pre.next = left
        if right:
            pre.next = right
        return res.next
```


- 归并排序--迭代
```
class Solution:
    def sortList(self, head: ListNode) -> ListNode:
        
        #归并排序--迭代
        '''
        思想:
        1.先获得链表的长度
        2.从要合成链表长度为interval==1开始, 遍历链表逐个合并, 注意处理区间数为奇数的情况
        '''
        if not head or not head.next:
            return head
        
        #1.get list length
        dummy = ListNode(-1)
        dummy.next = head
        tmp = head
        length = 0
        while tmp:
            length += 1
            tmp = tmp.next
        
        #2.开始逐个区间合并
        interval = 1
        while interval<=(length+1)//2:
            count = length//(interval*2)
            cur = dummy.next #用于遍历链表,注意不能用head,因为在第一次合并后head就改变了
            pre_tail = dummy #用于链接各个interval的链表
            #此处注意处理count为奇数
            while count>(1 if length%(interval*2) else 0):
                h1,h2,cur = self.find_interval(cur, interval)
                count -= 1
                #返回合并后的头尾节点
                ihead, itail = self.merge(h1, h2)
                pre_tail.next = ihead
                pre_tail = itail   
            
            #如果count!=0,说明为奇数个区间,先合并前面的一个区间,再把区间和剩余元素合并
            if count==1:
                h1,h2,cur = self.find_interval(cur, interval)
                h1, _ = self.merge(h1, h2)
                ihead, itail = self.merge(h1, cur)
                pre_tail.next = ihead
            interval *= 2
        return dummy.next
    
    #返回要合并的两个区间的开头,以及下一合并的开头
    def find_interval(self, cur, interval):
        h1 = cur
        #注意每步走一个区间的长度
        #先找h1的末尾,进行断链
        for i in range(interval-1):
            cur = cur.next
        #断链
        cur.next, cur= None, cur.next
        #找h2的开头
        h2 = cur
        #找h2的末尾
        for i in range(interval-1):
            cur = cur.next
        #断链后的cur指向下一个interval的开头
        cur.next, cur= None, cur.next
        return h1,h2,cur
    
    #返回合并链表的头尾节点
    def merge(self,left,right):
        res = ListNode(-1)
        pre = res
        while left and right:
            if left.val <= right.val:
                pre.next = left
                left = left.next
            else:
                pre.next = right
                right = right.next
            pre = pre.next
            #这一步是在消除left,right原链表的连接
            pre.next = None
        if left:
            pre.next = left
        if right:
            pre.next = right
        while pre.next:
            pre = pre.next
        #返回合并后链表的开头和结尾
        return res.next, pre
```

- 快速排序 -- 前后指针
```
class Solution:
    def sortList(self, head: ListNode) -> ListNode:
        if not head or not head.next:
            return head
        self.sort(head, None)
        return head
    
    def sort(self,left,right):
        if left==right or left.next==right:
            return left
        index = self.partition(left,right)
        self.sort(left, index)
        self.sort(index.next,right)
        
    def partition(self,left,right):
        #前后指针法
        value = left.val
        pre = left
        cur = left
        while cur!=right:
            if cur.val<value:
                pre = pre.next
                pre.val, cur.val = cur.val, pre.val
            cur = cur.next
        pre.val, left.val = left.val, pre.val
        return pre 
```
