# 第一种方法，是比较慢的，但是代码简单明了
1、每次找到最后节点，将最后的节点插入到头，其实每次步骤都一样
```
    public void reorderList(ListNode head) {
        if (head == null) return;
        ListNode curr = head;

        while (curr.next != null){
            //获取尾节点
            ListNode tail = curr;
            ListNode pre = tail;
            while (tail.next != null){
                pre = tail;
                tail = tail.next;
            }
            //说明当前节点已经到中间了，不需要再插入了
            if (curr.next == tail) break;
            tail.next = curr.next;
            curr.next = tail;
            pre.next = null;
            curr = tail.next;
        }
    }
```
# 第二种方法，使用快慢指针，提交时间100%
1、将指针定位到中间的节点，注意要讲中间节点的next置为null。
2、反转中间节点之后后的链表。
3、从两个链表的头部，开始逐个插入。
```
public void reorderList(ListNode head) {
    if (head == null) return;   
    ListNode low = head;
    ListNode fast = head;
    while (fast.next != null && fast.next.next != null) {
            low = low.next;
            fast = fast.next.next;
        }

    //反转链表
    ListNode reversList = null;
    ListNode curr = low.next;
    low.next = null;
    while (curr != null){
        ListNode n = curr;
        curr = curr.next;
        n.next = reversList;
        reversList = n;
    }

    curr = head;
    //逐个插入
    while (curr != null && reversList != null){
        ListNode tem = reversList.next;
        reversList.next = curr.next;
        curr.next = reversList;
        curr = reversList.next;
        reversList = tem;
    }
}
```


