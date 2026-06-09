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
    public ListNode oddEvenList(ListNode head) {
        if (head == null)
            return null;
        ListNode now = head;
        ListNode pointer = head;
        ListNode pre = head.next;
        ListNode evenPointer = head.next;
        while (pointer.next != null && pointer.next.next != null){
            if (pointer == head) {
                pointer = pointer.next.next;
                continue;
            }
            ListNode next = pointer.next.next;
            ListNode nextPre = pointer.next;
            pre.next = pointer.next;
            now.next = pointer;
            pointer.next = evenPointer;
            now = now.next;
            pointer = next;
            pre = nextPre;
        }
        if (pointer != head){
            pre.next = pointer.next;
            now.next = pointer;
            pointer.next = evenPointer;
        }
        return head;
    }
}
```