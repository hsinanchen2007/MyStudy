### 解题思路
此处撰写解题思路
![QQ截图20200324124651.jpg](https://pic.leetcode-cn.com/f0ddd6e95b0eeb5e1131ab11f477356c43c465c9aef601146960618466cb1a8a-QQ%E6%88%AA%E5%9B%BE20200324124651.jpg)

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
        ListNode newHead = null;
        while (head != null) {
            ListNode temp = head.next;
            head.next = newHead;
            newHead = head;
            head = temp;
        }
        return newHead;
    }
}
```