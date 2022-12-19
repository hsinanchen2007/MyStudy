```java
    public static ListNode deleteDuplicates(ListNode head) {
        if (head == null || head.next == null) {
            return head;
        }
        ListNode dummy = new ListNode(-1);
        dummy.next = head;
        // 快慢指针
        // 慢指针表示合法的
        ListNode slow = dummy;
        // 快指针用来遍历
        ListNode fast = head;
        while (fast != null) {
            if (fast.next != null && fast.val != fast.next.val) {
                if (slow.next == fast) {
                    // 如果slow的下一个元素就是fast，
                    // 表示slow到fast都没有重复
                    slow = fast;
                } else {
                    // 如果slow的下一个元素不是fast，则表示中间出现了
                    // 重复元素,slow.next=fast.next，跳过重复元素
                    slow.next = fast.next;
                }
            }
            // 如果fast的下一个元素为空了
            // 这里有两种情况
            // 1.slow的下一个元素就是fast，此时fast也不是一个重复的元素，
            // 不需要其他操作，slow.next=fast fast.next=null
            // 2.slow的下一个元素不是fast，此时fast与前面的元素都是重复元素，
            // 直接slow.next指向null
            if (fast.next == null) {
                if (slow.next != fast) {
                    slow.next = null;
                }
            }
            fast = fast.next;
        }
        return dummy.next;
    }
```
