![image.png](https://pic.leetcode-cn.com/087ef52b591c349064b28531aa2578446acd30a9e96cd4a278f3063612a7765c-image.png)

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
        if(head == null || head.next == null) return head;
        ListNode pre = new ListNode(0);
        pre.next = head;
        ListNode slow = pre.next;
        ListNode fast = slow.next;
        ListNode another = new ListNode(0);
        another.next = fast;
        while(fast != null && fast.next != null){
            slow.next = fast.next;
            slow = slow.next;
            fast.next = slow.next;
            fast = fast.next;
        }
        slow.next = another.next;
        return pre.next;
    }
}
```