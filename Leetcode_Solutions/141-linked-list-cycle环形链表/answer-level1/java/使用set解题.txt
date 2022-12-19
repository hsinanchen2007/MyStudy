### 解题思路
将链表中的数据 依次放入 set中
head 为 null 时为非环形
出现与 set 中数据相等的 为环形

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
        Set<ListNode> nodesSeen = new HashSet<>();

        while (head != null){
            if (nodesSeen.contains(head)){
                return true;
            }else {
                nodesSeen.add(head);
            }
            head = head.next;
        }
    return false;

    }
}
```