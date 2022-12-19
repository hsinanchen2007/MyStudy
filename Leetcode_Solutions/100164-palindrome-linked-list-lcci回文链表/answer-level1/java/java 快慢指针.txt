**思路**
使用快慢指针，让前半部分链表反转，然后比较前半部分和后半部分链表是否相等即可。具体代码如下：

```java
 public boolean isPalindrome(ListNode head) {
        ListNode slow = head;
        ListNode fast = head;
        ListNode prev = null;

        while (fast != null && fast.next != null) {
            ListNode oldCur = slow;
            slow = slow.next;
            fast = fast.next.next;
            oldCur.next = prev;
            prev = oldCur;
        }

        if (fast != null) {
            // 链表个数为奇数
            slow = slow.next;
        }

        // 判断pre和slow是否相等
        while (slow != null) {
            if (slow.val != prev.val) {
                return false;
            }
            slow = slow.next;
            prev = prev.next;
        }

        return true;
    }
```

**复杂度分析**
时间复杂度：$O(n)$
空间复杂度：$O(1)$