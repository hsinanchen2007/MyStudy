## 分析
第一步：找到待反转节点的前一个节点。
第二步：反转m到n这部分。
第三步：将反转的起点的next指向反转的后面一部分。
第四步：将第一步找到的节点指向反转以后的头节点。
如下图所示：
![](https://pic.leetcode-cn.com/3158b23f7e6919d47a11a2f57e921b5645fceb84212450336f2256f5659fa9e7.jpg)
## 代码
```java
public ListNode reverseBetween(ListNode head, int m, int n) {
        ListNode res = new ListNode(0);
        res.next = head;
        ListNode node = res;
        //找到需要反转的那一段的上一个节点。
        for (int i = 1; i < m; i++) {
            node = node.next;
        }
        //node.next就是需要反转的这段的起点。
        ListNode nextHead = node.next;
        ListNode next = null;
        ListNode pre = null;
        //反转m到n这一段
        for (int i = m; i <= n; i++) {
            next = nextHead.next;
            nextHead.next = pre;
            pre = nextHead;
            nextHead = next;
        }
        //将反转的起点的next指向next。
        node.next.next = next;
        //需要反转的那一段的上一个节点的next节点指向反转后链表的头结点
        node.next = pre;
        return res.next;
    }
```
**更多leetcode题解可扫描下方二维码关注公众号**
[![](https://pic.leetcode-cn.com/271220540867376d8820ad08344c43f64257efda6a44cb2f34e55374d8475914)](https://pic.leetcode-cn.com/271220540867376d8820ad08344c43f64257efda6a44cb2f34e55374d8475914)