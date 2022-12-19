### 解题思路
1. 遍历链表，将链表尾部指向第一个元素，同时记录链表长度
2. 当右移的长度为k时，其实就是尾部的倒数第K个元素为表头，我们从head开始向后遍历（len-k）个元素即到达新的表头，但是要断链，所以到达第（len-k-1）个元素，然后保存下一个节点，最后断链即可。

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
        if (k == 0 || head == null)
            return head;
        int len = 0;
        ListNode res = head;
        ListNode tail = null;
        while (head != null){
            len++;
            tail = head;
            head = head.next;
        }
        tail.next = res;

        k = len - k % len - 1;
        while (k-- != 0){
            res = res.next;
        }
        ListNode result = res.next;
        res.next = null;
        return result;
    }
}
```