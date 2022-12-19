# 压入栈（但是空间复杂度不满足题意）

```
public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
        if (headA == null || headB == null) return null;
        Stack<ListNode> stackA = new Stack<>();
        Stack<ListNode> stackB = new Stack<>();
        ListNode pA = headA;
        ListNode pB = headB;
        while (pA != null) {
            stackA.push(pA);
            pA = pA.next;
        }
        while (pB != null) {
            stackB.push(pB);
            pB = pB.next;
        }
        ListNode res = null;
        while (!stackA.empty() && !stackB.empty() && stackA.peek() == stackB.peek()) {
            res = stackA.peek();
            stackA.pop();
            stackB.pop();
        }
        return res;
    }
```