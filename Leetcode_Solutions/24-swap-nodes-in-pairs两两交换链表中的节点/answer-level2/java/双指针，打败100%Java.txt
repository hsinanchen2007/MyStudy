![image.png](https://pic.leetcode-cn.com/0cc55529f48319bd22743cb7b3c1e9b50f88c6cbf5f6eed4781e7fcbca1cf314-image.png)


使用cur来记录需要处理的两个节点的头节点，pre记录前一组节点的尾节点

```
public ListNode swapPairs(ListNode head) {
        if (head == null) {
            return null;
        }
        
        if (head.next == null) {
            return head;
        }

        ListNode result = head.next;

        ListNode cur = head;
        ListNode pre = null;
        while(cur != null) {
            ListNode next = cur.next;
            if (next != null) {
                if (pre != null) {
                    pre.next = next;
                }
                cur.next = next.next;
                next.next = cur;
                pre = cur;
                cur = cur.next;
            } else {
                cur = null;
            }
        }
        return result;
    }
```
