**想法**
将链表分成2部分，小于x的构建新的链表1，大于x构建新链表2，然后串起来即可

**算法**
所见即所得，按照想法实现

**代码**

```
class Solution {
    public ListNode partition(ListNode head, int x) {
        ListNode beforeHead = new ListNode(0);
        ListNode before = beforeHead;
        ListNode afterHead = new ListNode(0);
        ListNode after = afterHead;
        
        ListNode p = head;
        while (p != null) {
            if (p.val < x) {
                before.next = p;
                before = p;
            } else {
                after.next = p;
                after = p;
            }
            p = p.next;
        }
        after.next = null;
        before.next = afterHead.next;
       
        return beforeHead.next;
    }
}
```

