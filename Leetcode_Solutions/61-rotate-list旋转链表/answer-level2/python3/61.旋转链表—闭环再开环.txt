


```
class Solution:
    def rotateRight(self, head: ListNode, k: int) -> ListNode:
        #判断首节点是否存在
        if head==None:
            return head

        #count 获取链表长度
        count=1   

        #设置快慢指针
        pointer_1,pointer_2=head,head

        #链表闭环
        while pointer_1.next:
            pointer_1=pointer_1.next
            count+=1
        pointer_1.next=head

        #k对长度取模
        if k>=count:
            k=k%count

        #开环
        for i in range(count-k-1):
            pointer_2=pointer_2.next
        pointer_1=pointer_2.next
        pointer_2.next=None
        return pointer_1
```
