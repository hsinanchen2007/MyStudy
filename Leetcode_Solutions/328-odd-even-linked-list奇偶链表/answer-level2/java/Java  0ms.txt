
```
public ListNode oddEvenList(ListNode head) {
    if (head == null || head.next == null || head.next.next == null)
        return head;
    ListNode point1 = head;
    ListNode lastNodeOfList1 = head;
    ListNode firstNodeOfList2 = head.next;
    ListNode point2 = head.next;
    while(point1 != null || point2 != null) {
        if (point1 != null) {
            if (point1.next != null) {
                point1.next = point1.next.next;
                point1 = (point1.next==null?point1:point1.next);
            } else if (point1.next == null){
                break;
            }
            lastNodeOfList1 = point1;
        }
        if (point2 != null && point2.next != null) {
            point2.next = point2.next.next;
            point2 = point2.next;
        }
    }
    lastNodeOfList1.next = firstNodeOfList2;
    return head;
}
```
