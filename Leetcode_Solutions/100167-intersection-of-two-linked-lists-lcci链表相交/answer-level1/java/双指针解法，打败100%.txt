```
public class Solution {
    public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
        if(headA == null || headB == null){
            return null;
        }
        //定义两个指针进行遍历,当自己的遍历完就遍历另一条，使两链表都能遍历所有的节点 a+b = b+a，
        //若有交集则遍历指针必会有相等节点，若不想等只要让遍历完两个链表的节点同时变成null，即可跳出循环。

        ListNode nodeA = headA;
        ListNode nodeB = headB;
        while(nodeA != nodeB ){
            nodeA = nodeA ==null ?  headB : nodeA.next ;
            nodeB = nodeB ==null ?  headA : nodeB.next ;
        }
        return nodeA;
    }
}
```
