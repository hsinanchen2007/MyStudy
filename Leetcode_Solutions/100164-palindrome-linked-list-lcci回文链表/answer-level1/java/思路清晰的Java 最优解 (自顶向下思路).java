/**
 * 时间复杂度： O(n) : 因为整个链表需要进行遍历。
 * 空间复杂度： O(1)： 申请里有限个变量。
 * 思路：
 * 1. 先进行条件判断： 节点数量为0，或者1 ， 直接返回为true。 (这种情况也可以不判断。一般为false 情况进行判断)
 * 2. 先找出中间节点。 这里需要注意链表长度为奇数、偶数来判断哪个部分为后半部分链表起点。(枚举方式推到出，记住进行)
 *                     若为奇数： fast == null ; 中间节点为slow , 则后半部分起点为 slow.next ;
 *                     若为偶数： fast != null;  有2个中间节点， slow 次数落在后半部分。刚好是起点。不用移动。
 * 3。对后半部分节点，进行反转。(链表反转需要非常熟悉。1min 内写完)
 * 4. 前后2个链表进行遍历， 比较是否相等。
 */
class Solution {
    public boolean isPalindrome(ListNode head) {
        if (head == null || head.next == null) {
            return true;
        }
        // Step 1: 找到中间节点。
        ListNode fast = head;
        ListNode slow = head;

        while (fast != null && fast.next != null) {
            slow = slow.next;
            fast = fast.next.next;
        }

        // Step 1.2  确定后续节点。
        // 若节点数量为奇数， 中间节点刚好落在中间， 则后部分链表， 是中间节点的next;
        // 若节点数量为偶数， 遍历结束时， slow 节点刚好落在后部分节点开头。 后部链表就是slow 节点。
        if (fast != null) {
            slow = slow.next;
        }

        // Step2:  反转后续的链表

        ListNode newHead = reserve(slow);

        // Step3： 两个链表进行直接比较。
        while (head != null && newHead != null) {
            if (head.val != newHead.val) {
                return false;
            }
            head = head.next;
            newHead = newHead.next;
        }
        return true;

    }

    // 链表的反转， 一定需要非常的熟悉! 使用的时候，很快可以拿来。
    private ListNode reserve(ListNode head) {
        ListNode pre = null;
        ListNode curr = head;
        ListNode temp = null;
        while (curr != null) {
            temp = curr.next;
            curr.next = pre;
            pre = curr;
            curr = temp;
        }
        return pre;
    }
}