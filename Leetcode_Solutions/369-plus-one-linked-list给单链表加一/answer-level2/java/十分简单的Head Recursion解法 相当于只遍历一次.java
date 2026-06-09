```
class Solution {
    private boolean helper(ListNode head) {
        if (head.next == null){
            head.val += 1;
            if (head.val < 10){
                return false;
            }else{
                head.val-=10;
                return true;
            }
        }
        
        boolean nextCheck = helper(head.next);
        if(nextCheck){
            head.val++;
            if (head.val == 10){
                head.val = 0;
                return true;
            }else{
                return false;
            }
        }else{
            return false;
        }
        
        
    }
    
    public ListNode plusOne(ListNode head) {
        boolean checker = helper(head);
        if (checker){
            ListNode newNode = new ListNode(1);
            newNode.next = head;
            head = newNode;
        }
        
        return head;
    }
}
```