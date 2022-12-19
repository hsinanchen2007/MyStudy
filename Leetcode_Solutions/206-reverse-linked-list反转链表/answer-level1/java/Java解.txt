### 解题思路
将每一个节点处的指针反转，要注意的是链表的开头和结尾

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
        ListNode pre = null;
        ListNode cur = head;
        while(cur != null){
            ListNode nextnode = cur.next;
            cur.next = pre;
            pre = cur;
            cur = nextnode;
        }
        return pre;
    }
}
```