### 解题思路
这样不太好

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
    List<Integer> list = new ArrayList<>();

    public int kthToLast(ListNode head, int k) {
        while (head != null) {
            list.add(head.val);
            head = head.next;
        }
        return list.get(list.size() - k );
    }
}
```