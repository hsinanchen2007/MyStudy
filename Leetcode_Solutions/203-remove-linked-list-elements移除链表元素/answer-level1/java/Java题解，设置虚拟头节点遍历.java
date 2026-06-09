```
代码块
```java []
class Solution {
    public ListNode removeElements(ListNode head, int val) {
        if (head == null )return null;
        ListNode dummy = new ListNode(-1);
        dummy.next = head;
        ListNode tmp = dummy;
        while(tmp.next != null){
             if(tmp.next.val == val){
                     tmp.next = tmp.next.next;
            }else{
                 tmp = tmp.next;
             }
        }
        
      
        return dummy.next;
    }
} 
`
```
