### 解题思路
时间复杂度O(n)，顺序遍历，三个指针分别指向上一节点pre、当前节点curr、下一节点next_n，每次都使curr.next转为指向前一节点从而实现反转，而后三个指针都往后顺延。
注意：为保证head.next指向NULL，pre的初始值可设为NULL

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
        ListNode curr = head;
        while (curr != null) {
            ListNode next_n = curr.next;
            curr.next = pre;
            pre = curr;
            curr = next_n;
        }
        return pre;
    }
}
```