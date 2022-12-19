```
class Solution:
    def removeNthFromEnd(self, head: ListNode, n: int) -> ListNode:
        '''先求长度，之后再计数删除'''
        def length(head):
            count=0
            cur=head
            while(cur!=None):
                count+=1
                cur=cur.next
            #print("count=",count)
            return count
        List_Len=length(head)
        def delete(head):
            index=List_Len-n
            if index==0:#第一个节点
                cur=head
                head=head.next
                return head
                
            else:
                cur=head
                count=1
                while (count<index):
                    count+=1
                    cur=cur.next
                cur.next=cur.next.next
                return head
        if List_Len==0:
            return None
        else:
            return delete(head)
```
