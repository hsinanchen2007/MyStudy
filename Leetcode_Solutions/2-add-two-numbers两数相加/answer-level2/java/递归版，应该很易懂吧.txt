```
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        return recur(l1, l2, false);
    }

    // 合并两个有序链表的递归函数，flag为是否有来自低位的进位
    private ListNode recur(ListNode l1, ListNode l2, boolean flag) {
        // 递归结束条件
        if (l1 == null && l2 == null)
            return flag ? new ListNode(1) : null;
        else if (l1 == null)
            return recur(new ListNode(0), l2, flag);
        else if (l2 == null)
            return recur(l1, new ListNode(0), flag);

        // 递归逻辑 
        int sum = 0;
        sum += flag ? l1.val + l2.val + 1 : l1.val + l2.val;
        flag = (sum) / 10 == 1;
        l1.val = sum % 10;
        l1.next = recur(l1.next, l2.next, flag);
        return l1;
    }
```
执行用时 :2 ms, 在所有 Java 提交中击败了99.97%的用户
内存消耗 :39.6 MB, 在所有 Java 提交中击败了96.04%的用户