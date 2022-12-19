### 解题思路
仅仅就是两两交换而已，毫无科技含量啊，看代码吧

### 代码

```java
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode swapPairs(ListNode head) {
        if(head == null || head.next == null){
            return head;
        }
        ListNode remember = head;
        while(head != null){
            ListNode thisNode = head;
            ListNode nextNode = head.next;
            if(nextNode == null){
                return remember;
            }
            int middle = thisNode.val;
            thisNode.val = nextNode.val;
            nextNode.val = middle;
            head = nextNode.next;
        }
        return remember;
    }
}
```