### 解题思路
比较简单粗暴的解法

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
    public ListNode middleNode(ListNode head) {
        if (head.next == null) {
            return head;
        }
        int index = 1;
        Map<Integer, ListNode> nodeMap = new HashMap<Integer, ListNode>(100);
        while (head != null) {
            nodeMap.put(index, head);
            head = head.next;
            if (head != null) {
                index ++;
            }
        }
        return nodeMap.get(index / 2 + 1);
    }
}
```