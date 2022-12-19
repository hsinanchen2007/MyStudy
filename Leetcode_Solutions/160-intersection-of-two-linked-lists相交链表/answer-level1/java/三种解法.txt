### 解题思路
方法1，双循环，对于每一次a的结点，循环遍历b，对比，注意，当内循环结束后，内循环的结点重新定位到头位置，需要一个新的指针。
方法2，hash法，将a存入hashset，遍历b，如果相等则返回，循环结束返回空。
方法3，a + b == b + a；相交的时候一定是焦点，当走完之后 返回空。

### 代码

```java
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {

        public ListNode getIntersectionNode(ListNode headA, ListNode headB) {

        if (headA == null || headB == null) return null;

        while (headA != null) {

            ListNode curB = headB;
            while (curB != null) {
                if (headA == curB) {
                    return headA;
                }
                curB = curB.next;
            }
            headA = headA.next;
        }
        return null;
    }

    三种方法，2hash，把a存入set，循环b比较
    public ListNode getIntersectionNode(ListNode headA, ListNode headB) {

        if (headA == null || headB == null) return null;

        HashSet<ListNode> setA = new HashSet<>();
        while (headA != null) {
            setA.add(headA);
            headA = headA.next;
        }

        while (headB != null) {
            if (setA.contains(headB)) {
                return headB;
            }
            headB = headB.next;
        }
        return null;
    }

        //三种方法，3.添加，a + b == b + a
    public ListNode getIntersectionNode(ListNode headA, ListNode headB) {

        if (headA == null || headB == null) return null;

        ListNode curA = headA;
        ListNode curB = headB;
        while (true) {
            
            if (curA == curB) {
                return curA;
            }
            curA = curA == null ? headB: curA.next;
            curB = curB == null ? headA: curB.next;
        }

    }
}
```