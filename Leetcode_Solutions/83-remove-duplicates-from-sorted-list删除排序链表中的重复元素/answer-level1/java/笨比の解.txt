### 解题思路
只有笨比想得出来

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
    public ListNode deleteDuplicates(ListNode head) {
        if(head == null|| head.next == null) {
            return head;
        }
        ListNode h = head;

        HashSet<Integer> hashset = new HashSet<>();
        hashset.add(head.val);
        while(head!= null &&  head.next != null) {
            //如果下一个存在重复
            if(hashset.contains(head.next.val)) {
                head.next = head.next.next;
            } else {
                hashset.add(head.next.val);
                head = head.next;
            }

        }

        return h;
    }
}
```