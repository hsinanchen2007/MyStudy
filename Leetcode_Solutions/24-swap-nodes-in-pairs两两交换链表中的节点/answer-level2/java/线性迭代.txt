```java
class Solution {
    public ListNode swapPairs(ListNode head) {
        // pre -> 1 -> 2 -> 3 -> 4
        //        c    n
        
        // c.next = n.next
        //        c
        // pre -> 1 -> 3 -> 4
        // 2 -> 3 -> 4
        // n
        
        // n.next = c
        //        c
        // pre -> 1 -> 3 -> 4
        //   2 -> 1 -> 3 -> 4
        //   n
        
        // pre.next = n
        //             c
        // pre -> 2 -> 1 -> 3 -> 4
        //        n
        
        // pre = c;
        // c = c.next;
        //     pre
        // 2 -> 1 -> 3 -> 4
        //           c
        
        if(head == null) return null;
        
        ListNode first = new ListNode(-1);
        first.next = head;
        
        ListNode pre = first, cur = pre.next;
        while(cur != null && cur.next != null){
            ListNode next = cur.next;
            cur.next = next.next;
            next.next = cur;
            pre.next = next;
            
            
            pre = cur;
            cur = cur.next;
        }
        
        return first.next;
    }
}
```

![image.png](https://pic.leetcode-cn.com/c0f9cc10190dcfe7da96f6c61df262b19b95566a03673c30a34480b1b791e765-image.png)
