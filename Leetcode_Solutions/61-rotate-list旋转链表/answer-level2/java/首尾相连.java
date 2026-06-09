详细看代码

```
class Solution {
    public ListNode rotateRight(ListNode head, int k) {
        if (head == null) {return null;}
        if (head.next == null) {return head;}
        // find the last node of the list
        int l = 1;
        ListNode end = null;
        ListNode pointer = head;
        while(pointer.next != null) {
            pointer = pointer.next;
            l++;
            end = pointer;
        }
        // connect the first and the last
        if (end != null) {
            end.next = head;
        }
        // reset the pointer
        for(int i = 0; i <= l - k % l - 1; i++) {
            pointer = pointer.next;
        }
        ListNode result = head;
        if (pointer != null) {
            result = pointer.next;
        }
        else {
            return head;
        }
        pointer.next = null;
        return result;
    }
}
```
