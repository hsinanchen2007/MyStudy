执行用时 :2 ms, 在所有 Java 提交中击败了96.72%的用户
内存消耗 :49 MB, 在所有 Java 提交中击败了5.05%的用户

```
public class Demo160 {
    public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
        if(headA == null || headB == null) return null;
        int len1 = 0;
        int len2 = 0;
        ListNode a = headA, b = headB;
        while (a != null) {
            a = a.next;
            len1++;
        }
        while (b != null) {
            b = b.next;
            len2++;
        }
        a = headA;
        b = headB;
        if (len1 > len2) {
            int num = len1 - len2;
            while (num > 0) {
                a = a.next;
                num--;
            }
        } else {
            int num = len2 - len1;
            while (num > 0) {
                b = b.next;
                num--;
            }
        }
        while (a != null) {
            if (a == b) return a; //没有说这是个有序或者无重复的单链表，
                                  // 因此涉及到的判断必须是(a == b) , 而不是 (a.val == b.val)
            else {
                a = a.next;
                b = b.next;
            }
        }
        return null;
    }
}

```
