### 解题思路
此处撰写解题思路

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
    public ListNode removeDuplicateNodes(ListNode head) {

        Set<Integer> vals = new LinkedHashSet<>();

        ListNode cur = head;
        while (cur != null) {
            vals.add(cur.val);
            cur = cur.next;
        }

        ListNode dummyHead = new ListNode(-1), tail = dummyHead;
        for (int val : vals)
            tail = tail.next = new ListNode(val);

        return dummyHead.next;
    }
}
```