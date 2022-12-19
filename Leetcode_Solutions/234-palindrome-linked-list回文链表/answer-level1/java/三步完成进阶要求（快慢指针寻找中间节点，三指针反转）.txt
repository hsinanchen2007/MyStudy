### 解题思路
![屏幕快照 2020-03-08 21.52.43.png](https://pic.leetcode-cn.com/3df78fee224dec0f5fde66c3e62e947a0aaa7f778eff9700970e7916da9daa80-%E5%B1%8F%E5%B9%95%E5%BF%AB%E7%85%A7%202020-03-08%2021.52.43.png)


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
        if (head == null || head.next == null) {
            return true;
        }
        // 1.找到中间节点
        ListNode center = head,last = head;
        int index = 0;
        while (last != null) {
            last = last.next;
            if (index % 2 == 1) {
                center = center.next;
            }
            index++;
        }
        // 2.将左侧链表进行反转
        ListNode leftHead = null, left = head, move = head.next;
        while (move != center) {
            left.next = leftHead;
            leftHead = left;
            left = move;
            move = move.next;
            if (move == center) {
                left.next = leftHead;
            }
        }
        // 3.比较左右链表是否相等
        ListNode right = index % 2 == 0 ? center : center.next;
        while (left != null && right != null) {
            if (left.val != right.val) {
                return false;
            }
            left = left.next;
            right = right.next;
        }
        return true;
    }
}
```