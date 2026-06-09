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
    public ListNode reverseList(ListNode head) {
        ListNode nextNode = null;
        ListNode result = null;

        while(head != null){
            // 先获得下一个
            nextNode = head.next;
            // 处理当前
            head.next = result;
            result = head;

            head = nextNode;
        }
        return result;
    }
}
```