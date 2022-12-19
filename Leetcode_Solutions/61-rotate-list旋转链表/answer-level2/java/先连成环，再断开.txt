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
    public ListNode rotateRight(ListNode head, int k) {
        if(head == null || k < 0) return head;
        ListNode tail = head;
        ListNode cur = head;
        int len = 1;

        while(tail.next != null){
            tail = tail.next;
            len++;
        }
        
        k = k % len;
        if(k == 0) return head;

        tail.next = cur;

        int i = 1;
        while(i != len - k){
            cur = cur.next;
            i++;
        }

        ListNode result = cur.next;
        cur.next = null;

        return result;

    }
}
```