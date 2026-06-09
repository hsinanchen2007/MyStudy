### 解题思路

用一个list保存下所有没有重复出现的节点，当出现重复时，返回list中相同的节点即可
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
    public ListNode detectCycle(ListNode head) {
        ArrayList<ListNode> list = new ArrayList<>();
        while(head != null && !list.contains(head)) {
            list.add(head);
            head = head.next;
        }
        if(head != null) {
            return list.get(list.indexOf(head));
        }
        return null;
    }
}
```