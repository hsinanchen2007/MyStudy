```java
/*
 * @lc app=leetcode.cn id=234 lang=java
 *
 * [234] 回文链表
 */
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
        // 排除异常情况: 链表为空或只有一位时 返回真
        if (head == null || head.next == null) {
            return true;
        }
        // 排除异常情况: 链表只有两位时 直接判断这两位是否相等
        if (head.next.next == null) {
            return head.val == head.next.val;
        }
        // 声明快慢指针
        ListNode slow = head;
        ListNode fast = head;
        // 声明last指针 用以记录循环的慢指针上一次遍历的节点
        // 在遍历时转向前半部分链表
        ListNode last = null;
        // 用以记录遍历过程的临时值
        ListNode tmp = null;
        while (fast.next != null && fast.next.next != null) {
            // 记录下当前遍历的节点 等下赋值给last指针
            tmp = slow;
            slow = slow.next;
            fast = fast.next.next;
            // 反转链表
            if (last == null) {
                // 第一次循环 last指针指向头部 尾部置空（变头为尾）
                last = head;
                last.next = null;
            } else {
                // 后续循环 将last指针赋值给当前遍历节点的下一位
                tmp.next = last;
                // last指针更新为当前遍历节点
                last = tmp;
            }
        }
        // 上述遍历结束 找到中间值 fast指针使命结束
        // 接下来重新定义快慢指针使命
        // 慢指针: 往前遍历; 快指针: 往后遍历
        if (fast.next == null) {
            // 如果是奇数个 slow此时位于中间数位置
            // fast需要向后一位
            // slow需要向前一位 即当前tmp值
            fast = slow.next;
            slow = tmp;
        } else {
            // 如果是偶数个 slow此时位于前半部分最后一位数位置
            // fast需要向后一位
            // slow不需要移动 但是需要补充指针转向操作
            fast = slow.next;
            slow.next = tmp;
        }
        // 遍历判断
        while (slow != null || fast != null) {
            if (slow == null || fast == null 
                || slow.val != fast.val) {
                return false;
            }
            slow = slow.next;
            fast = fast.next;
        }
        return true;
    }
}


```