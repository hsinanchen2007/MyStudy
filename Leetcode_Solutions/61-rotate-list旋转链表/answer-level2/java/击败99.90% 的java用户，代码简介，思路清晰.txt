先将链表连接成环，计算链表长度，移动k的取模步数，断开环。
```java
class Solution {
    public ListNode rotateRight(ListNode head, int k) {
        if (head == null) return head;
        ListNode cur = head;
        int len = 1; // 计算链表长度
        while (cur != null && cur.next != null){ // 找到最后一个节点 相连
            cur = cur.next;
            len++;
        }
        // 链接成环
        cur.next = head;
        cur = cur.next;
        // 对k取模 移动的步数
        k = k % len;
        int count = len - k - 1; // 移动
        while (count > 0){
            cur = cur.next;
            count--;
        }
        // 找到要返回的节点头 断开环
        ListNode node = cur.next;
        cur.next = null;
        return node;
    }
}
```