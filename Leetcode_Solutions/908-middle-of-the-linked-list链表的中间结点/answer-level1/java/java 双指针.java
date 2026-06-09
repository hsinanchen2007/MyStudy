![image.png](https://pic.leetcode-cn.com/83f7f1ed23900c8c92fd3444522a2ffc0e10d57dfb32c342dcf578c27235cc2c-image.png)

### 解题思路
其实这道题可以用两个指针进行操作：其中一个p1步伐为1，另一个p2步伐为2，当p2遍历到链表尾时，p1刚好在中间；但是题目要求选中间（如果两个）后面的一个，所以return p1.next。

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
    public ListNode middleNode(ListNode head) {
        if (head==null) {return null;}
        ListNode p1 = head;
        ListNode p2 = head.next;
        if (p2==null) {return head;}
        while (p2!=null) {
            p2 = p2.next;
            if (p2==null||p2.next==null) {break;}
            p2 = p2.next;
            p1 = p1.next;
        }
        return p1.next;
    }
}
```