```
class Solution {
    public ListNode getKthFromEnd(ListNode head, int k) {
        while(head != null){
            ListNode tmp = head;
            for(int i = 0; i < k; i++){
                tmp = tmp.next;
            }
            if(tmp == null)
                return head;
            head = head.next;
        }

        return head;
    }
}
```
