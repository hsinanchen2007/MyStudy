方案：（运行时间0ms，哈哈哈哈哈）
1. 判断head是否位空或者head.next是否为空，符合条件直接返回head
2. 因为第一个node没有上一个节点，所以进行特殊处理，将其与第二个节点位置交换
3. 除了上述情况，则每个需要交换的节点都有上一个节点，标识三个节点，分别为head（需要交换的第一个节点）、end（需要交换的第二个节点）、prev（交换的第一个节点的前一节点）
4. 交换规则，将head的next指向end的next，然后end的next指向head，这时候prev的next还是head，需要修改为end
5. 更新三个节点，其中prev指向start，而start则为start的next，end则为修改后start的next

```
public ListNode swapPairs(ListNode head) {
    if (head == null || head.next == null) return head;
    ListNode start = head;
    ListNode end = head.next;
    start.next = end.next;
    end.next = start;
    head = end;

    ListNode prev = start;
    start = start.next;
    if (start == null)
        return head;
    end = start.next;

    while (end != null){
        start.next = end.next;
        end.next = start;
        prev.next = end;
        prev = start;
        start = start.next;
        if (start == null)
            break;
        end = start.next;
    }
    return head;
}
```
