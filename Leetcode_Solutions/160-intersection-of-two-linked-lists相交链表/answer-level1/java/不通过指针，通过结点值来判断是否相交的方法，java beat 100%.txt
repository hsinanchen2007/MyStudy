一种不通过指针，而是通过结点值来判断是否相交的方法，java beat 100%

大致思路是：
1. 把 A 链表的所有值变到 0 以下
2. 把 B 链表的所有值加一个值，如果 A，B 相交，能把相交部分的结点值变到 0 以上
3. 遍历 A 链表，如果发现第一个值大于 0 的结点，就是相交结点
4. 最后恢复 A，B 链表的值
```java
public class Solution {
    public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
        if(headA == null || headB == null) return null;
        int maxA = headA.val, minA = headA.val;
        ListNode pa = headA.next;
        while(pa != null){
            if(pa.val > maxA) maxA = pa.val;
            if(pa.val < minA) minA = pa.val;
            pa = pa.next;
        }
        pa = headA;
        while(pa != null){
            pa.val -= maxA;
            pa = pa.next;
        }
        int b = maxA-minA+1;
        ListNode pb = headB;
        while(pb != null){
            pb.val += b;
            pb = pb.next;
        }
        ListNode result = null;
        pa = headA;
        while(pa != null){
            if(pa.val > 0){
                result = pa;
                break;
            }
            pa = pa.next;
        }
        pa = headA;
        while(pa != null){
            pa.val += maxA;
            pa = pa.next;
        }
        pb = headB;
        while(pb != null){
            pb.val -= b;
            pb = pb.next;
        }
        return result;
    }
}
```
