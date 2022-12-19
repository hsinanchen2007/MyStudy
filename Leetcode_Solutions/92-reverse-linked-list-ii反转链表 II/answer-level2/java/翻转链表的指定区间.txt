分为三段处理，很简单：
```java
class Solution {
    public ListNode reverseBetween(ListNode head, int m, int n) {
        if (head == null || m == n) {
            return head;
        }

        // 找到第 m 节点👇
        
        // 第m个节点的前一个节点
        ListNode oneEnd = null;
        // 第 m 个节点
        ListNode mNode = head;
        for (int i = 1; i < m; i++) {
            oneEnd = mNode;
            mNode = mNode.next;
        }

        // 开始翻转节点👇

        ListNode pre = null;
        ListNode current = mNode;
        ListNode temp = null;

        // 期望翻转的长度
        int expectLength = n - m;
        // 实际已经翻转的长度
        int length = 0;

        // 开始翻转
        while(expectLength >= length) {
            temp = current.next;
            current.next = pre;
            pre = current;
            current = temp;
            length++;
        }

        // 拼接第一段与第二段
        if (oneEnd != null) {
            oneEnd.next = pre;
        }
        
        // 拼接第二段与第三段
        mNode.next = current;

        return m == 1 ? pre : head;
    }
}
```