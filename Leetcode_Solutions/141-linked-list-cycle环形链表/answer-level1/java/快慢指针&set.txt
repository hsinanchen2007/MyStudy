### 解题思路
此处撰写解题思路

### 代码

```java
/**
 * Definition for singly-linked list.
 * class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public boolean hasCycle(ListNode head) {
        if(head == null) return false;
        ListNode slow = head;
        ListNode fast = head.next;

         while (fast != null && fast.next != null) {
        if (slow.equals(fast)) {
            return true;
        }
        slow = slow.next;
        fast = fast.next.next;
    }



        // while(slow != null && fast != null){
        //     if(slow.equals(fast)){
        //         return true;
        //     } else{
        //         slow = slow.next;
        //         if(fast.next != null){
        //             fast = fast.next.next;
        //         }
                
        //     }
        // }

        return false;

        //set方法
        // Set<ListNode> nodeSet = new HashSet();
        // while(head != null){
        //     if(nodeSet.contains(head)){
        //         return true;
        //     } else {
        //         nodeSet.add(head);
        //     }

        //     head = head.next;
        // }

        // return false;
    }
}
```