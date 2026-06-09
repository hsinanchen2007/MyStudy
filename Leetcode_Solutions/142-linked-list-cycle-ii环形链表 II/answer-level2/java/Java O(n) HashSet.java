### 解题思路
简单的利用Hash查找是否有循环。

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
        HashSet<ListNode> nodeSet = new HashSet();
        ListNode cur = head;
        while (cur != null){
            if (nodeSet.contains(cur)){
                return cur;
            }
            nodeSet.add(cur);
            cur = cur.next;
        }
        return null;
    }
}
```