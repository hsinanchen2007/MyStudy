第一种方法：采用两个指针指向两个不同的链表，判断当前两个指针指向结点是否相同
```
var getIntersectionNode = function(headA, headB) {
    var l1=headA;
    var l2=headB;
    if(l1==null||l2==null)return null;
    while(l1!=l2){
       l1= l1==null? headB:l1.next;
       l2= l2==null? headA:l2.next;
    }
    return  l1;
};
```

java
```
public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
    ListNode l1 = headA, l2 = headB;
    while (l1 != l2) {
        l1 = (l1 == null) ? headB : l1.next;
        l2 = (l2 == null) ? headA : l2.next;
    }
    return l1;
}
```
## 第二种方法
将一个链表接到另一个链表后，看是否有环