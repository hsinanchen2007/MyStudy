### 解题思路
先遍历计数t，然后再剥t/2层呗   用时0ms就TM离谱

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
        ListNode head2 = head,head3;
        int i = 1;
        for(;head2.next != null;head2 = head2.next,i++);
        for(int j = i / 2;j != 0;j--) {
            head = head.next;
        }
        return head;
    }
}
```