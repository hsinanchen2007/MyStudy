### 解题思路
遍历链表找到对应的位置,如果链表长度比k小，k=k%count,重新遍历一次。

### 代码

```java

public class Solution {

    private ListNode start;
    private ListNode end;
    private int count = 0;

    public ListNode rotateRight(ListNode head, int k) {
        if (head == null || k < 0) return null;
        ListNode pre = new ListNode(0);

        pre.next = head;
        move(pre,k);
        if (count <= k) {
            k %= count;
        }
        if (k == 0) return pre.next;
        if(count > k) move(pre,k);
        ListNode tmp = start.next;
        end.next = pre.next;
        pre.next = tmp;
        start.next = null;
        return pre.next;
    }

    private void move(ListNode pre, int k) {
        start = pre;
        end = pre;
        count = 0;
        while (end.next != null) {
            if (count >= k) {
                start = start.next;
            }
            end = end.next;
            count++;
        }
    }
}

```