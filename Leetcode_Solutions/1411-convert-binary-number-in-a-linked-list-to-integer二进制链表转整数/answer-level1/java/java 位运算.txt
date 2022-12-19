# 思路
链表移动到右侧下一个节点的过程，其实就是二进制数左移1位的结果。

```java
    public int getDecimalValue(ListNode head) {
        ListNode cur = head;
        int ans = 0;
        while (cur != null) {
            ans <<= 1;
            ans += cur.val;
            cur = cur.next;
        }
        return ans;
    }
```