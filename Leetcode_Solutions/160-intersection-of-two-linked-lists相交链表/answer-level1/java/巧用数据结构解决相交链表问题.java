使用Set来找出相交节点.每次都分别从两个链表里面取一个节点加入Set,第一次遇到无法加入的节点，说明这个节点之前已经加入了Set，这就是两个链表的相交节点。

```java
public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
        Set<ListNode> set = new HashSet<>();
        int prevCount = 0;
        while (headA != null || headB != null) {
            if (headA != null) {
                set.add(headA);
                int count = set.size();
                if (count > prevCount) {
                    prevCount = count;
                    headA = headA.next;
                } else return headA;
            }
            if (headB != null) {
                set.add(headB);
                int count = set.size();
                if (count > prevCount) { 
                    prevCount = count;
                    headB = headB.next;
                } else return headB;
            }
        }
        return null;
    }
```
