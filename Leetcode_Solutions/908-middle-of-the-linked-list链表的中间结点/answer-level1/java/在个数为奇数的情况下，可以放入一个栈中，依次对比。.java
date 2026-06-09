 ```
public ListNode middleNode(ListNode head) {
        if(head==null){
            return null;
        }       
        ListNode fast=head;
        ListNode slow=head;
        while(fast.next!=null){
                slow=slow.next;
            
                fast=fast.next.next;
                if(fast==null){
                    break;
                }
        }
        return slow;
    }
```