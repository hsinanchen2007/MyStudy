### 解题思路

// 1-2-3-2-1
// 利用快慢两个指针，当快指针走到尾部时，慢指针走向中间
// 在快慢指针移动过程中，将慢指针之前的所有节点倒置成2-1和慢指针之后的所有对比
// 只要有一个不相等，则返回false

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

        // 1-2-3-2-1
        // 利用快慢两个指针，当快指针走到尾部时，慢指针走向中间
        // 在快慢指针移动过程中，将慢指针之前的所有节点倒置成2-1和慢指针之后的所有对比
        // 只要有一个不相等，则返回false

        // 你能否用 O(n) 时间复杂度和 O(1) 空间复杂度解决此题？
        ListNode current = head; // 慢指针
        ListNode fastPoint = head; // 快指针
        ListNode reverse = null; // 逆向
        ListNode reverseHead = null;
        boolean fastPointEnd = false;
        while (current != null) {
            // 快指针未结束
            if (!fastPointEnd) {
                if (fastPoint == null) { // 偶数
                    fastPointEnd = true; // 数量为偶数时，这次直接开始比较
                } else if (fastPoint.next == null) { // 奇数
                    fastPointEnd = true;
                    current = current.next;// 数量为奇数时，将指针先后一定一步，下一次开始比较
                } else {
                    fastPoint = fastPoint.next.next; // 快指针走两步
                    // 翻转前半部分
                    reverseHead = current;
                    current = current.next;
                    reverseHead.next = reverse;
                    reverse = reverseHead;
                }
            }

            // 当前与reverse对比
            if (fastPointEnd) { // 快指针结束，开始对比
                if (reverseHead.val != current.val) {
                    return false; // 只要有个不相同，则返回false
                }
                // 前后两部分都向后移动一步
                reverseHead = reverseHead.next; // 前半部分
                current = current.next; // 后半部分，慢指针走一步
            }
        }

        return true;
    }
}
```