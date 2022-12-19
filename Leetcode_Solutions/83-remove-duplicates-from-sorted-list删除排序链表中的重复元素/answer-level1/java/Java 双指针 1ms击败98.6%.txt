### 解题思路
![image.png](https://pic.leetcode-cn.com/4a36ab9fc0d3d42f0672eeb53bd8282ecd0600b96ab4727d5acc578e5500bf8f-image.png)

**没什么技巧，就是一个fast，一个slow双指针，
只要值相等，fast就一直向前走
不相等就链接fast和slow，然后各自往前走一步
fast到了末尾就结束

时间复杂度O(n)
空间复杂度O(1)**


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
    public ListNode deleteDuplicates(ListNode head) {
        if (head == null || head.next == null) return head;
        ListNode result = head, fast = head.next, slow = head;
        while(fast != null){
            while(fast != null && fast.val == slow.val) fast = fast.next;
            slow.next = fast;
            slow = slow.next;
            if(fast == null) break;
            fast = fast.next;
        }
        return result;
    }
}
```