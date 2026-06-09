## 第一版：直接新建一个节点ans，用于保存答案。每次取出一个节点，然后用头插法插入到ans链表中。实现思路简单，用时较长。代码如下：

```
class Solution {
    public ListNode insertionSortList(ListNode head) {
        ListNode ans = new ListNode(0);
        ListNode node = head;
        ListNode pre, nodeNext;
        while (node != null) {
            nodeNext = node.next;   // 保存node的下一个节点
            pre = ans;  // 让pre从头开始遍历
            
            // 头插法，满足条件则遍历下一个
            while(pre.next != null && pre.next.val < node.val){
                pre = pre.next;
            }
            node.next = pre.next;
            pre.next = node;
            node = nodeNext;
        }
        return ans.next;
    }
}
```

## 第二版：用时10ms左右，大致思路为将原来的链表拆分为两个链表，并为ans链表标记一个尾节点，这样每次做比较可以先比较尾节点，如果如何，则不需要再遍历整个节点了，因此可以节约时间。

```
class Solution {
    public ListNode insertionSortList(ListNode head) {
        if (head == null)
            return head;
        ListNode ans = new ListNode(0);
        ans.next = head;

        ListNode ansLast = head;
        ListNode node = head.next;
        head.next = null;

        while (node != null) {
            ListNode pre = ans;
            ListNode next = pre.next;
            ListNode nodeNext = node.next;
            if(ansLast.val <= node.val){
                ansLast.next = node;
                ansLast = node;
                node.next = null;
            } else {
                while(next != null){
                    if (next.val >= node.val) {
                        pre.next = node;
                        node.next = next;
                        break;
                    } else {
                        pre = pre.next;
                        next = next.next;
                    }
                }
            }
            node = nodeNext;
        }
        return ans.next;
    }
}
```

## 第三版：基于第二版，可以做个改进，将标记位置设置为ans表的中间值，这样时间复杂度可以为原来的一半，难点是保持中间位置标记的准确性。
