# 思路：

    1、找到链表的切分点，然后切割为两段
    2、将两段连接起来，即可   
## 找寻切分点：
倒数第k个节点即为切分后的头节点，倒数第k+1个节点点即为切分后的尾节点
其中注意k大于链表长度的情况，直接除以链表长度取余数作为新的k

```
class Solution:
    def rotateRight(self, head: ListNode, k: int) -> ListNode:

        #类似于第19题，找出倒数第k个节点即为头节点，倒数第k+1个几点即为尾节点
        #本题即为找出倒数第k+1个头节点

        #判断边界条件
        if not head:
            return head

        #头节点存下来，以便后边成环
        dummy = head
        num = 0
        #链表长度
        while head:
            num += 1
            head = head.next

        #从头数第m个节点为尾节点
        head = dummy
        m = abs(num-(k%num))

        #循环整数倍的列表长度，可以直接退出
        if m == num:
            return dummy
        #找到尾节点        
        for i in range(m-1):
            head = head.next
        tail = head
        #新的头节点
        head_new = tail.next

        pre = tail

        while pre.next:
            pre = pre.next

        tail.next = None
        pre.next = dummy
        # print(head_new)
 
        return head_new


```
