```java
class Solution {
    public boolean isPalindrome(ListNode head) {
        if(head==null||head.next==null) return true;
        //找中点
        ListNode fast = head.next.next,slow=head;
        while(fast!=null&&fast.next!=null){
            fast=fast.next.next;
            slow=slow.next;
        }
        // 1 2 3 4    5 6 7 8 9 ->5
        // 1 2 3 4    5 6 7 8   ->5
        //断开中点，避免成环
        ListNode tmp=slow;
        slow=slow.next;
        tmp.next=null;
        //反转后半段链表
        ListNode lastHalf =reverse(slow),lastHalf1=lastHalf;
        
        ListNode preHalf = head;
        boolean result=true;
        //判断回文
        while(preHalf!=null&&lastHalf!=null){
            if(preHalf.val!=lastHalf.val){
                result=false;
                break;
            }
            preHalf=preHalf.next;
            lastHalf=lastHalf.next;
        }

        //恢复链表
        lastHalf1=reverse(lastHalf1);
        //连接前后半段
        tmp.next=lastHalf1;
        return result;
    }

    public ListNode reverse(ListNode head){
        if(head==null||head.next==null) return head;
        ListNode p=head,q=p.next;
        p.next=null;
        while(q!=null){
            ListNode tmp=q.next;
            q.next=p;
            p=q;
            q=tmp;
        }
        return p;
    }
}
```
