在[官方解题](https://leetcode-cn.com/problems/linked-list-cycle-ii/solution/huan-xing-lian-biao-ii-by-leetcode/)中，提到了Floyd算法，这里我给出我自己的证明。

### 算法流程简单回顾

1. 使用快慢指针的方式判断链表中是否有环，如果无环则返回，如果有环，则快慢指针相遇时应指向同一个节点。
2. 使用第三个指针指向链表根节点，让慢指针和根节点指针分别向前进，重复这个过程直到两指针相遇，相遇的结点即为环的入口。

### 算法证明

这里主要是证明第二步的正确性。为了方便理解，最好画下图，分别画出快慢指针“从开始移动到相遇走过的路线”的路线图。下面正式开始证明。

我们定义：

* 环的长度为$L$
* 起点到环入口的距离为$D$
* 两指针相遇时，慢节点在环内走过的路程为$x$、慢节点再次到达环入口的路程$y$

易知：

$$L = x + y$$

从快慢指针同时出发到两者相遇，慢指针走过的路程为：

$$D + x$$

快指针走过的路程为

$$D + nL + x$$

其中$n$为快指针与慢指针相遇前，快指针在环中走过的圈数，$n >= 1$。

相同时间内，快指针走过的路程是慢指针的两倍，因此：

$$D + x = \frac {D + nL + x} {2}$$

由前面的等式可得

$$D = (n - 1)L + y$$

这意味着在快慢指针相遇后，如果有一指针$k$从根节点处以相同的速度和慢指针一起前进，当$k$节点走过距离$D$时，慢指针已经从（快慢指针的）相遇点走到了环的入口，并且绕环多走了$n-1$圈。

### Java实现

```Java
public class Solution {
    public ListNode detectCycle(ListNode head) {
        if (head == null) {
            return null;
        }
        ListNode fast = head;
        ListNode slow = head;
        do {
            if (fast == null) {
                return null;
            }
            fast = fast.next;
            if (fast == null) {
                return null;
            }
            fast = fast.next;
            slow = slow.next;
        } while (fast != slow);
        
        while (head != slow) {
            head = head.next;
            slow = slow.next;
        }
        return head;
    }
}
```