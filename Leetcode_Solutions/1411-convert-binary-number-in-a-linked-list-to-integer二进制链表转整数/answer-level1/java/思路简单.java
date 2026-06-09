```
//先进行反转再进行计算
class Solution {
    public int getDecimalValue(ListNode head) {
        ListNode  newHead = reverseListNotRecursive(head);
        int index = 0;
        int res = 0;
        while(newHead != null){
            if(newHead.val != 0){
                 res +=  1 << index;
            }
            newHead =  newHead.next;
            index++;
        }
        return res;
    }

    //使用递归
    public ListNode reverseList(ListNode head){
        if(head == null || head.next == null) return head;
        ListNode newhead = reverseList(head.next);
        head.next.next = head;
        head.next =null;
        return newhead;
    }
    //使用非递归
    public ListNode reverseListNotRecursive(ListNode head){
        if(head == null || head.next == null) return head;
        ListNode newhead = null;
        while(head != null){
         ListNode temp = head.next;   
         head.next= newhead;
         newhead = head;
         head = temp;
        }
        return newhead;
    }
}
```
