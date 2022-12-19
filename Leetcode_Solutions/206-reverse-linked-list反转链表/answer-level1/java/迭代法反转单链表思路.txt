Step 1. 设置一个指针 curr 表示当前遍历到的 node，初始值为 head；
Step 2. 设置一个指针 prev 表示当前遍历的 node 的**前一个 node**，初始值为 null；
Step 3. 使用一个 while 循环，当 curr 指向的 node 不为 null 时，一直遍历完所有 node；
Step 4-1. 每次遍历时，设置一个**临时指针**变量 temp，用来**暂存** curr.next 指向的 node；
Step 4-2. 接着，开始反转链表，将**当前 node 的下一个 node **指针的值设置为**前一个 node **指针的值，设置 curr.next=prev；
Step 4-3. 接着，重设**前一个 node **指针的值，设置 prev=curr；
Step 4-4. 接着，重设**当前 node **指针的值，设置 curr=temp；
Step 5. return。

```
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
        ListNode prev = null;
        ListNode curr = head;
        while (curr != null) {
            ListNode temp = curr.next;
            curr.next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }
}
```

