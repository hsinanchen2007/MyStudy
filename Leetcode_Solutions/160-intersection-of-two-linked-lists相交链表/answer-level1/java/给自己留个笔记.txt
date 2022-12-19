原理如图所示：
![image.png](https://pic.leetcode-cn.com/e0efdd908a8941e3c53a68a6049d88c437b8299e48540a772ab091b86695d981-image.png)

初始化 `pA = headA, pB = headB`，开始遍历。
以上图为例，pA会先到达链表尾，**当pA到达末尾时，重置pA为headB；同样的，当pB到达末尾时，重置pB为headA**。当pA与pB相遇时，必然就是两个链表的交点。

为什么要这样处理？因为这样的一个遍历过程，对pA而言，走过的路程即为`a+c+b`，对pB而言，即为`b+c+a`，显然`a+c+b = b+c+a`，这就是该算法的核心原理。

即使两个链表没有相交点，事实上，仍然可以统一处理，因为这种情况意味着相交点就是`null`，也就是上图中的公共部分`c`没有了，从而递推式变成了`pA: a+b`，`pB: b+a`，这同样是成立的。

代码：

```java
public class Solution {
    public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
        ListNode pA = headA, pB = headB;
        while (pA != pB) {
            pA = pA == null ? headB : pA.next;
            pB = pB == null ? headA : pB.next;
        }
        return pA;
    }
}
```

