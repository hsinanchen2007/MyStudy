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
    public ListNode swapPairs(ListNode head) {
        ListNode dummy = new ListNode(0);
        dummy.next = head;
        ListNode current = dummy;

        while (current.next != null && current.next.next != null) {
            swap2(current);
            current = current.next.next;
        }
        return dummy.next;
    }

    private static void swap2(ListNode pre) {
        ListNode dummy = pre.next;
        pre.next = dummy.next;
        dummy.next = dummy.next.next;
        pre.next.next = dummy;
    }
}
![截图未命名.jpg](https://pic.leetcode-cn.com/87fc4bc0cd46370a1b8e6baf6516291d1389f617a7c5ce64f466d4f397958b0b-%E6%88%AA%E5%9B%BE%E6%9C%AA%E5%91%BD%E5%90%8D.jpg)

```