#### 方法 1：哈希表

**想法**

如果我们用一个 `Set` 保存已经访问过的节点，我们可以遍历整个列表并返回第一个出现重复的节点。

**算法**

首先，我们分配一个 `Set` 去保存所有的列表节点。我们逐一遍历列表，检查当前节点是否出现过，如果节点已经出现过，那么一定形成了环且它是环的入口。否则如果有其他点是环的入口，我们应该先访问到其他节点而不是这个节点。其他情况，没有成环则直接返回 `null` 。

算法会在遍历有限个节点后终止，这是因为输入列表会被分成两类：成环的和不成环的。一个不成欢的列表在遍历完所有节点后会到达 `null` - 即链表的最后一个元素后停止。一个成环列表可以想象成是一个不成环列表将最后一个 `null` 元素换成环的入口。

如果 `while` 循环终止，我们返回 `null` 因为我们已经将所有的节点遍历了一遍且没有遇到重复的节点，这种情况下，列表是不成环的。对于循环列表， `while` 循环永远不会停止，但在某个节点上， `if` 条件会被满足并导致函数的退出。

```Java []
public class Solution {
    public ListNode detectCycle(ListNode head) {
        Set<ListNode> visited = new HashSet<ListNode>();

        ListNode node = head;
        while (node != null) {
            if (visited.contains(node)) {
                return node;
            }
            visited.add(node);
            node = node.next;
        }

        return null;
    }
}
```

```Python []
class Solution(object):
    def detectCycle(self, head):
        visited = set()

        node = head
        while node is not None:
            if node in visited:
                return node
            else:
                visited.add(node)
                node = node.next

        return None
```

**复杂度分析**

* 时间复杂度：$O(n)$

    不管是成环还是不成环的输入，算法肯定都只会访问每个节点一次。对于非成环列表这是显而易见的，因为第 $n$ 个节点指向 `null` ，这会让循环退出。对于循环列表， `if` 条件满足时会导致函数的退出，因为它指向了某个已经访问过的节点。两种情况下，访问的节点数最多都是 $n$ 个，所以运行时间跟节点数目成线性关系。

* 空间复杂度：$O(n)$

    不管成环或者不成欢的输入，我们都需要将每个节点插入 `Set` 中一次。两者唯一的区别是最后访问的节点后是 `null` 还是一个已经访问过的节点。因此，由于 `Set` 包含 $n$ 个不同的节点，所需空间与节点数目也是线性关系的。

<br />
#### 方法 2：Floyd 算法

**想法**

当然一个跑得快的人和一个跑得慢的人在一个圆形的赛道上赛跑，会发生什么？在某一个时刻，跑得快的人一定会从后面赶上跑得慢的人。

**算法**

Floyd 的算法被划分成两个不同的 _阶段_ 。在第一阶段，找出列表中是否有环，如果没有环，可以直接返回 `null` 并退出。否则，用 `相遇节点` 来找到环的入口。

*阶段 1*

这里我们初始化两个指针 - 快指针和慢指针。我们每次移动慢指针一步、快指针两步，直到快指针无法继续往前移动。如果在某次移动后，快慢指针指向了同一个节点，我们就返回它。否则，我们继续，直到 `while` 循环终止且没有返回任何节点，这种情况说明没有成环，我们返回 `null` 。

下图说明了这个算法的工作方式：

![image.png](https://pic.leetcode-cn.com/ea37804a3d86a51a1bf827b9068e1f515ffddf840a0563ea0d1174c58ac64352-image.png){:width="650px"}

环中的节点从 0 到 $C-1$ 编号，其中 $C$ 是环的长度。非环节点从 $-F$ 到 $-1$ 编号，其中 $F$ 是环以外节点的数目。 $F$ 次迭代以后，慢指针指向了 0 且快指针指向某个节点 $h$ ，其中 $F \equiv h \pmod C$ 。这是因为快指针在 $F$ 次迭代中遍历了 $2F$ 个节点，且恰好有 $F$ 个在环中。继续迭代 $C-h$ 次，慢指针显然指向第 $C-h$ 号节点，而快指针也会指向相同的节点。原因在于，快指针从 $h$ 号节点出发遍历了 $2(C-h)$ 个节点。
$$
\begin{aligned}
    h + 2(C-h) &= 2C - h \\
                &\equiv C-h \pmod C
\end{aligned}
$$

因此，如果列表是有环的，快指针和慢指针最后会同时指向同一个节点，因此被称为 _相遇_ 。

*阶段 2*

给定阶段 1 找到的相遇点，阶段 2 将找到环的入口。首先我们初始化额外的两个指针： `ptr1` ，指向链表的头， `ptr2` 指向相遇点。然后，我们每次将它们往前移动一步，直到它们相遇，它们相遇的点就是环的入口，返回这个节点。

下面的图将更好的帮助理解和证明这个方法的正确性。


![image.png](https://pic.leetcode-cn.com/99987d4e679fdfbcfd206a4429d9b076b46ad09bd2670f886703fb35ef130635-image.png){:width="650px"}
{:align="center"}

我们利用已知的条件：慢指针移动 1 步，快指针移动 2 步，来说明它们相遇在环的入口处。（下面证明中的 tortoise 表示慢指针，hare 表示快指针）

$$
\begin{aligned}
    2 \cdot distance(tortoise) &= distance(hare) \\
                        2(F+a) &= F+a+b+a \\
                         2F+2a &= F+2a+b \\
                             F &= b \\
\end{aligned}
$$

因为 $F=b$ ，指针从 $h$ 点出发和从链表的头出发，最后会遍历相同数目的节点后在环的入口处相遇。

下面的动画中动态地演示了整个算法过程：

<![image.png](https://pic.leetcode-cn.com/26d91419cd4e90a8954f4253f779681e135527eb9efcfa761fdea990f6b10770-image.png),![image.png](https://pic.leetcode-cn.com/4e82b6ff8e2e46f006da98414ae9f9e5ba342e90405ecc37802e83d7652f33aa-image.png),![image.png](https://pic.leetcode-cn.com/efe62f7f9d2b003819dc617dab2342e1b7428a9019fcd5eeceef383b0bf1c6fc-image.png),![image.png](https://pic.leetcode-cn.com/05848364a6b75ced28ad6d5f172bf18f9f37c58e89382c7c6f4c5715c00b4d17-image.png),![image.png](https://pic.leetcode-cn.com/b16ab0dbc5d98adf9b79f9cf1a83b352c1f316dde4f28aab24d980bc17e7a38d-image.png),![image.png](https://pic.leetcode-cn.com/0e1f5788dba0f811c0bfc63fa275424885d3373b43616ab51efb07c8b811f52e-image.png),![image.png](https://pic.leetcode-cn.com/566912d38a4fdf7f9fed96cd4d50104c2a110ef24c491e3b8596f0591df1e77c-image.png),![image.png](https://pic.leetcode-cn.com/c1aa9989085dacdbfc527130186eeffd1af8a1710528b5c10b318314f5c9ff79-image.png),![image.png](https://pic.leetcode-cn.com/e1f0345de3ffc0eff25b1ecd4d80e121c7f38610d2a74f3b98ac38bfd5d38c92-image.png),![image.png](https://pic.leetcode-cn.com/4f90bf4e8f1a7d44b686a23394e000573f2bf551fa62816e523161bf0d2da474-image.png),![image.png](https://pic.leetcode-cn.com/b7d865deedbda8d686fa9c57e9cc819b57527325e852f26721d1fbcd62719757-image.png),![image.png](https://pic.leetcode-cn.com/744cd130ed875602db99c9ee82f2e7d4b6681831b7674ae919764b5e87e44cd5-image.png),![image.png](https://pic.leetcode-cn.com/a0dc8d96c672509eabcd2ba856c1d533fa2208894a7e40c05981e1616576c8f4-image.png)>

```Java []
public class Solution {
    private ListNode getIntersect(ListNode head) {
        ListNode tortoise = head;
        ListNode hare = head;

        // A fast pointer will either loop around a cycle and meet the slow
        // pointer or reach the `null` at the end of a non-cyclic list.
        while (hare != null && hare.next != null) {
            tortoise = tortoise.next;
            hare = hare.next.next;
            if (tortoise == hare) {
                return tortoise;
            }
        }

        return null;
}

    public ListNode detectCycle(ListNode head) {
        if (head == null) {
            return null;
        }

        // If there is a cycle, the fast/slow pointers will intersect at some
        // node. Otherwise, there is no cycle, so we cannot find an e***ance to
        // a cycle.
        ListNode intersect = getIntersect(head);
        if (intersect == null) {
            return null;
        }

        // To find the e***ance to the cycle, we have two pointers traverse at
        // the same speed -- one from the front of the list, and the other from
        // the point of intersection.
        ListNode ptr1 = head;
        ListNode ptr2 = intersect;
        while (ptr1 != ptr2) {
            ptr1 = ptr1.next;
            ptr2 = ptr2.next;
        }

        return ptr1;
    }
}
```

```Python []
class Solution(object):
    def getIntersect(self, head):
        tortoise = head
        hare = head

        # A fast pointer will either loop around a cycle and meet the slow
        # pointer or reach the `null` at the end of a non-cyclic list.
        while hare is not None and hare.next is not None:
            tortoise = tortoise.next
            hare = hare.next.next
            if tortoise == hare:
                return tortoise

        return None

    def detectCycle(self, head):
        if head is None:
            return None

        # If there is a cycle, the fast/slow pointers will intersect at some
        # node. Otherwise, there is no cycle, so we cannot find an e***ance to
        # a cycle.
        intersect = self.getIntersect(head)
        if intersect is None:
            return None

        # To find the e***ance to the cycle, we have two pointers traverse at
        # the same speed -- one from the front of the list, and the other from
        # the point of intersection.
        ptr1 = head
        ptr2 = intersect
        while ptr1 != ptr2:
            ptr1 = ptr1.next
            ptr2 = ptr2.next

        return ptr1

```

**复杂度分析**

* 时间复杂度：$O(n)$

    对有环列表，快指针和慢指针在 $F+C-h$ 次迭代以后会指向同一个节点，正如上面正确性证明所示， $F+C-h \leq F+C = n$ ，所以阶段 1 运行时间在 $O(n)$ 时间以内，阶段 2 运行 $F < n$ 次迭代，所以它运行时间也在 $O(n)$ 以内。

    对于无环链表，快指针大约需要迭代 $\dfrac{n}{2}$ 次会抵达链表的尾部，这样不会进入阶段 2 就直接退出。

    因此，不管是哪一类链表，都会在与节点数成线性关系的时间内运行完。

* 空间复杂度：$O(1)$

  Floyd 的快慢指针算法仅需要几个指针，所以只需常数级别的额外空间。
