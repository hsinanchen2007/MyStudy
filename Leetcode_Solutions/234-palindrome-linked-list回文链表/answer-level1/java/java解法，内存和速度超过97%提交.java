1. 以下是我的题解，关键是找中点的时候同时翻转前半部分链表
```
/*
     * 快慢指针找中点同时翻转前半部分链表
     * 遍历比较前后半链表是否相等
     * */
    public boolean isPalindrome(ListNode head) {
        if (head == null) {
            return true;
        }
        //翻转
        ListNode fast = head;
        ListNode slow = head;
        //以下两个节点用于辅助找中点的同时进行前半部分链表翻转
        ListNode ahead = null;
        ListNode cur = head;
        while (fast != null && fast.next != null) {

            slow = slow.next;
            fast = fast.next.next;

            cur.next = ahead;
            ahead = cur;
            cur = slow;
        }

        //这里考虑的是链表长度是奇数还是偶数的情况
        if (fast != null) {
            cur = cur.next;
        }

        //判断两个链表是否相等
        while (cur != null && ahead != null) {
            if (cur.val != ahead.val) {
                return false;
            }
            cur = cur.next;
            ahead = ahead.next;
        }
        if (cur == null && ahead == null) {
            return true;
        } else {
            return false;
        }

    }
```
2.以下是我从leetcode提交里面找到的打败100%的解法，看不懂。。。
```
public boolean isPalindrome(ListNode head) {
        if (head == null || head.next == null) {
            return true;
        }
        if (head.next.next == null) {
            return head.val == head.next.val;
        }
        ListNode slow = head;
        ListNode fast = head.next;

        while (fast.next != null) {
            if (slow.val == fast.next.val) {
                if (fast.next.next != null) {
                    return false;
                }
                fast.next = null;
                slow = slow.next;
                fast = slow.next;
                if (fast == null || slow.val == fast.val) {
                    return true;
                }
            } else {
                fast = fast.next;
            }
        }
        return false;
    }
```
