```
class Solution {
    public ListNode removeElements(ListNode head, int val) {
        if(head == null) { return head;}
        ListNode res = removeElements(head.next, val);  
        if(head.val == val) {  // 最后一个节点是要删除的话， res == null
            return res;        // 
        } else {    
            head.next = res;        
            return head;
        }
        
    }
}
```
