```
public class Solution {
    public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
        ListNode h1 = headA;
        ListNode h2 = headB;

        if (headA == null || headB == null) {
            return null;
        }

        
        boolean isMark = false;
        while(true) {
            // System.out.println("h1:"+h1.val + ",h2:"+h2.val);
            if (h1 == h2) {
                return h1;
            }
            
            if (h1.next == null) {
                if (isMark == false) {
                    h1 = headB;
                    isMark = true;
                } else {
                    break;
                }
            } else {
                h1 = h1.next;
            }
            
            
            h2 = h2.next == null?headA:h2.next;
        }
        return null;
    }
}
```
