```
class Solution {
    public boolean isPalindrome(ListNode head) {
       if(head==null)
            return true;
        
        //找到中间右节点
        ListNode slow=head;
        ListNode fast=head;
        while(fast!=null&&fast.next!=null){
            slow=slow.next;
            fast=fast.next.next;
        }
        
        //翻转右链表
        ListNode pre=null;
        ListNode cur=slow;
        ListNode temp;
        while(cur!=null){
            temp=cur.next;
            cur.next=pre;
            pre=cur;
            cur=temp;
        }
        
        //逐一比较
        cur=pre;
        while(cur!=null){
            if(cur.val!=head.val)
                return false;
            cur=cur.next;
            head=head.next;
        }
        return true;
    }
}
```
