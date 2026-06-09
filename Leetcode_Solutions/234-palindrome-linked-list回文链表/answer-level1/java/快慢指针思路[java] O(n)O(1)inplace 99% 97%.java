### 解题思路
快慢指针同时遍历链表 快指针stride=2 慢指针stride=1  慢指针遍历过程中反转前半段链表。

结束时
偶数情况  null <- 1 <- 2[prev]    [slow]2 -> 1 -> null[fast]

奇数情况   慢指针=终点元素 快指针最后一个元素
             null <- 1 <- 2[prev]   3[slow]    2 -> 1[fast] ->null
多一步 slow to slow.next即可
对比两个链表内容即可判断是否为回文字串
边界情况：head->null    null

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
    public boolean isPalindrome(ListNode head) {
        if(head == null || head.next == null) return true;
        ListNode prev = null;
        ListNode slow = head;
        ListNode fast = head;
        ListNode next = null;
        while(fast!=null && fast.next!=null){
            next = slow.next;
            fast = fast.next.next;
            slow.next = prev;
            prev = slow;
            slow = next;
        }
        if(fast != null) {//odd number of nodes
            slow = slow.next;
        }
        while(slow!=null && prev!=null){
            if(slow.val!=prev.val) return false;
            slow = slow.next;
            prev = prev.next;
        }
        return true;
    }
}
```