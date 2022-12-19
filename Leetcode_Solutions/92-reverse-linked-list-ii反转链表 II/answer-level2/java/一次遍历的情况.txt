```Java []
class Solution {
//理一下思路：先设置一个头节点，来确保一些边界情况能够满足
//1.由于只能遍历一次，所以需要一个count位来指示从哪一位开始翻转，哪一位停止翻转，并且要连成一个完整的链表
//由于采用迭代法完成基础链表翻转的最后标志是curr指针指向头节点的下一位，所以利用他来完成一些功能
    public ListNode reverseBetween(ListNode head, int m, int n) {
         ListNode dumpyhead=new ListNode(0);
        dumpyhead.next=head;
        ListNode   cur,curr,curr1,left,right,prev,temp;
            cur=dumpyhead;
            int count=0;
        while(count<m-1)
        {
            count++;
            cur=cur.next;
            
        }
        left=cur;
        count++;
        curr=cur.next;
        curr1=curr;
        prev=null;
        while(curr!=null&&count<=n)
        {
            temp=curr.next;
            curr.next=prev;
            prev=curr;
            curr=temp;
            count++;
        }
        right=curr;
        left.next=prev;
        curr1.next=right;
        return dumpyhead.next;
        }
                        
}
```