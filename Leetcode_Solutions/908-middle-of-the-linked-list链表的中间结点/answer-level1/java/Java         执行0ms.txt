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
    public ListNode middleNode(ListNode head) {
        if(head == null) {
            return null;
        }
        ListNode cur = head;
        int count = 0;
        while(cur != null) {
            cur = cur.next;
            count++;
        }
        cur = head;
        int c = count/2;
        for(int i = 0; i < c; i++) {
            cur = cur.next;
        }
        return cur;
    }
}
```