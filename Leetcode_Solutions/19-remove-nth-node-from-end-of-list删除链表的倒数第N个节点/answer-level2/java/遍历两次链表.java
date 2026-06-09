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
 public ListNode removeNthFromEnd(ListNode head, int n) {
        ListNode cur = head;
        int size = 0;
        while (cur!=null){
            cur = cur.next;
            size++;
        }
        if (n > size){
            throw new IllegalArgumentException("n is illegal");
        }
        size = size - n;
        ListNode dummyHead = new ListNode(0);
        dummyHead.next = head;
        ListNode pre = dummyHead;
        while (size>0){
            pre = pre.next;
            size --;
        }
        pre.next = pre.next.next;
        return dummyHead.next;
    }
}
```