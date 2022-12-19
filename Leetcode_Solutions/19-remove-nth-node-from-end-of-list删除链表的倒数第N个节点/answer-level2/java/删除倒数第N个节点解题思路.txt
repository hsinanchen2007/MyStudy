### 解题思路
整体思路是让前面的指针先移动n步，之后前后指针共同移动直到前面的指针到尾部为止
可以使用两个指针，s (start) 、e(end)
因为第一个元素head可能是需要被删除的元素
所以，需要创建创建一个结点pre，pre的下一个节点为head
首先，先让 s 指针向后走n步，如果n.next != null,
就让s、e分别指向下一个元素
这个时候发现，e指向的元素就是该删除元素的前一个元素，
使用e.next = e.next.next可以删除需要删除的元素
最后返回pre.next
————————————————
版权声明：本文为CSDN博主「H_Q_Li」的原创文章，遵循 CC 4.0 BY-SA 版权协议，转载请附上原文出处链接及本声明。
原文链接：https://blog.csdn.net/H_Q_Li/article/details/104242771

### 代码

```java
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode removeNthFromEnd(ListNode head, int n) {
        ListNode pre = new ListNode(0);
        pre.next = head;
        ListNode s = pre;
        ListNode e = pre;
        while(n!= 0){
            s = s.next;
            n--;
        }
        while(s.next != null){
            s = s.next;
            e = e.next;

        }
        e.next = e.next.next;
        return pre.next;

    }
}
```