### 解题思路
这题目和前面重复了，最简单的思路就是计算链表长度再减去k，接着从前往后遍历减去后的次数即可，代码看看即可。

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
    public ListNode getKthFromEnd(ListNode head, int k) {
        int length = 0;
        ListNode current = head;
        while(current!=null) {
            length++;
            current = current.next;
        }
        length = length-k;
        for(int i = 0;i<length;i++) {
            head = head.next;
        }
        return head;
    }
}
```