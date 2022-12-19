```
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public void deleteNode(ListNode node) {
        ListNode nextNode = node.next;
        if(nextNode!=null) {
            node.val = nextNode.val;
            while(nextNode.next!=null) {
                node.next = nextNode.next;
                nextNode = nextNode.next;
                node = nextNode;
            } 
            node.next = null;
        } else {
            node = null;
        }
    }
}
```

