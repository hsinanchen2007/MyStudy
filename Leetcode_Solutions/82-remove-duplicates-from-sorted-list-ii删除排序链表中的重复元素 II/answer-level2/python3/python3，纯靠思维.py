```
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def deleteDuplicates(self, head: ListNode) -> ListNode:
        if not head or not head.next:
            return head
        flag=False  #flag指示当前节点和前面节点的关系，是否是重复节点
        res=None
        write=None
        while head:
            '''不存在next'''
            if not head.next:
                if flag:    #最后一个节点和前面是重复的，相同的
                    if res:
                        write.next=None     #初始了结果节点，后面不写了，重复节点去掉
                else:   
                    if not res:
                        return head
                    else:
                        write.next=head 
                head=head.next
            '''存在next'''
            elif head.next.val==head.val:
                flag=True
                head=head.next
            else:
                if not flag:
                    if not res:
                        res=head
                        write=head
                    else:
                        write.next=head
                        write=write.next
                flag=False  
                head=head.next
        return res
```
