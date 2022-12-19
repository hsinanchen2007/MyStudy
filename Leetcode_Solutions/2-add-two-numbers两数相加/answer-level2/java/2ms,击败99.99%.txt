- 设置一个tag记录进位，进1就将tag设为1，进2就将tag设为2。
- 当两个链表都不为空时，每次从链表中各取出一位数a、b，令temp = a + b + tag，此时temp可能会大于10，所以令tag = temp / 10，作为进位，令temp = temp % 10，作为当前位的数值。
- 当一个链表为空，另一个链表不为空时，每次从非空的链表中取出一位数a，令temp = a + tag，此时temp可能会大于10，所以令tag = temp / 10，作为进位，令temp = temp % 10，作为当前位的数值。
- 在两个链表均为空时，需要检查tag是否为0，如果tag不为0，则将tag设为最高位的值。

```java
class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
    	// 该头部只是一个定位，并不保存实际数据，实际数据从head.next开始
        ListNode head = new ListNode(0);
        ListNode p = head;// 指针
        int tag = 0;// 进位记录
        while (l1 != null || l2 != null) {
            ListNode temp;
            if (l1 == null) {
                temp = new ListNode(l2.val + tag);
                l2 = l2.next;
            }
            else if (l2 == null) {
                temp = new ListNode(l1.val + tag);
                l1 = l1.next;
            }
            else {
                temp = new ListNode(l1.val + l2.val + tag);
                l1 = l1.next;
                l2 = l2.next;
            }
            tag = temp.val / 10;// 记录当前位的进位
            temp.val %= 10;
            p.next = temp;
            p = p.next;
        }
        // 检查tag是否为空，不为空则将tag的值设为最高位的值
        p.next = tag > 0 ? new ListNode(tag) : null;
        return head.next;
    }
}
```