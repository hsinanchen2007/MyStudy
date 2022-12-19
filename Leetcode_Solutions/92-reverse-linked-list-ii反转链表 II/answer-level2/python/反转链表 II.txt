
#### 方法一: 递归

**直觉**

使用递归反转链表的思路来源于反转字符串时使用的类似方法。反转字符串的一个巨大优势是可以使用下标信息。我们可以创建两个指针，一个开头，一个结尾。不断地交换这两个指针指向的元素，并将两个指针向中间移动。在分析链表的情况前，先让我们看看字符串上的示例。

![image.png](https://pic.leetcode-cn.com/7f6ec0687455cfecce2019fcb560d7066d7e7dfedd46922d3cc96bcbff3c1eb5-image.png){:width=500}
{:align=center}

反转给定链表的一部分的思路基于上述方法。我们需要两个不同指针，一个指向第 $m$ 个结点，另一个指向第 $n$ 个结点。一旦有了这两个指针，我们就可以不断地交换这两个指针指向结点的数据，并将两个指针相向移动，就像字符串的情况那样。

> 然而，链表中没有向后指针，也没有下标。因此，我们需要使用递归来 **模拟** 向后指针。递归中的回溯可以帮助我们模拟一个指针从第$n$个结点向中心移动的移动过程。

**算法**

1. 我们定义一个递归函数用于反转给定链表的一部分。
2. 将函数记为 `recurse`。该函数使用三个参数: `m` 为反转的起点, `n` 为反转的终点, 以及从第 $n$ 个结点开始，随着递归回溯过程向后移动的指针 `right`。不清楚的话，可以参考后文的示意图。
3. 此外，我们还有一个指针 `left`，它从第 `m` 个结点开始向前移动。在 `P
4. 
5. 
6. thon` 中, 我们需要一个全局变量，值随着递归的进行而改变。在其他函数调用造成的变化可以持续的编程语言中，可以考虑将该指针加为函数 `recurse` 的一个变量。
4. 在
5. 递归调用中，给定 `m`，`n`，和 `right`, 首先判断 `n = 1`。 若判断为真, 则结束。
6. 于是，当 `n` 的值达到 1 时，我们便**回溯**。这时，`right` 指针在我们要反转的子链表结尾，`left` 到达了字列表的开头。于是，我们置换数据，并将 `left` 指针前移：`left = left.next`。我们需要此变化在回溯过程中保持。
7. 自此，每当我们回溯时，`right` 指针向后移一位。这就是前文所说的模拟。通过回溯模拟向后移动。
8. 当 `right == left` 或者 `right.next == left` 时停止交换。当子链表的长度为奇数时，情况为前者；当子链表长度为偶数时为后者。我们使用一个全局 boolean 变量 flag 来停止交换。

下面是一系列整个算法的示意图，希望能够帮助你理解清楚。

![image.png](http://pic.leetcode-cn.com/1adc7164bea5cd650af1545682900c792bd37a82df607aeb4f87a233d3eb69cf-image.png){:width=500}
{:align=center}

这是递归过程的第一步。给定所用链表，`left` 和 `right` 指针从链表的 `head` 开始。第一步是以更新过的 `m` 和 `n` 进行递归调用，换而言之，它们的值各自减 1。此外，`left` 和 `right` 指针向前移动一位。

![image.png](https://pic.leetcode-cn.com/162f18666a30ffd98e185da1311f2daa48b087b03d3a9eefeeb9541eafbcd013-image.png){:width=500}
{:align=center}

接下来的两步展示了 `left` 和 `right` 指针在链表中的移动。注意到在第二步之后，`left` 指针抵达了目标位置。因此，后续不再移动。从现在起，只有 `right` 指针继续移动，直到抵达结点 `6`。

![image.png](https://pic.leetcode-cn.com/4213450e7d9466ddf22f289d5e753df47a94a9a87789312a02de2979ed161718-image.png){:width=500}
{:align=center}

如你所见，在第五步之后，两个指针均抵达了目标位置，可以开始进行回溯。我们不再继续递归。回溯过程中的操作是交换 `left` 和 `right` 结点的数据。

![image.png](https://pic.leetcode-cn.com/36b2ed0c1859c5574a17597070797d8f26b77a9c13a0c3462ea150b1058fbbce-image.png){:width=500}
{:align=center}

如你所见，在第三步（回溯）之后，`right` 指针 **穿过了** `left` 指针，此时已经完成了要求部分链表的反转。结果是 `[7 → 9 → 8 → 1 → 10 → 2 → 6]`。 于是不再进行数据交换，在代码中，我们使用全局 boolean 变量 flag 来停止数据交换。不能直接跳出递归。


```Java [solution 1]
class Solution {

    // Object level variables since we need the changes
    // to persist across recursive calls and Java is pass by value.
    private boolean stop;
    private ListNode left;

    public void recurseAndReverse(ListNode right, int m, int n) {

        // base case. Don't proceed any further
        if (n == 1) {
            return;
        }

        // Keep moving the right pointer one step forward until (n == 1)
        right = right.next;

        // Keep moving left pointer to the right until we reach the proper node
        // from where the reversal is to start.
        if (m > 1) {
            this.left = this.left.next;
        }

        // Recurse with m and n reduced.
        this.recurseAndReverse(right, m - 1, n - 1);

        // In case both the pointers cross each other or become equal, we
        // stop i.e. don't swap data any further. We are done reversing at this
        // point.
        if (this.left == right || right.next == this.left) {
            this.stop = true;            
        }

        // Until the boolean stop is false, swap data between the two pointers
        if (!this.stop) {
            int t = this.left.val;
            this.left.val = right.val;
            right.val = t;

            // Move left one step to the right.
            // The right pointer moves one step back via backtracking.
            this.left = this.left.next;
        }
    }

    public ListNode reverseBetween(ListNode head, int m, int n) {
        this.left = head;
        this.stop = false;
        this.recurseAndReverse(head, m, n);
        return head;
    }
}
```
```Python [solution 1]
class Solution:
    def reverseBetween(self, head, m, n):
        """
        :type head: ListNode
        :type m: int
        :type n: int
        :rtype: ListNode
        """

        if not head:
            return None

        left, right = head, head
        stop = False
        def recurseAndReverse(right, m, n):
            nonlocal left, stop

            # base case. Don't proceed any further
            if n == 1:
                return

            # Keep moving the right pointer one step forward until (n == 1)
            right = right.next

            # Keep moving left pointer to the right until we reach the proper node
            # from where the reversal is to start.
            if m > 1:
                left = left.next

            # Recurse with m and n reduced.
            recurseAndReverse(right, m - 1, n - 1)

            # In case both the pointers cross each other or become equal, we
            # stop i.e. don't swap data any further. We are done reversing at this
            # point.
            if left == right or right.next == left:
                stop = True

            # Until the boolean stop is false, swap data between the two pointers     
            if not stop:
                left.val, right.val = right.val, left.val

                # Move left one step to the right.
                # The right pointer moves one step back via backtracking.
                left = left.next           

        recurseAndReverse(right, m, n)
        return head
```

**复杂度分析**

* 时间复杂度: $O(N)$。对每个结点最多处理两次。递归过程
* ，回溯
* 。在回溯过程中，我们只交换了一半的结点，但总复杂度是 $O(N)$。
* 空间复杂度: 最坏情况下为 $O(N)$。在最坏的情况下，我们需要反转整个链表。这是此时递归栈的大小。
<br/>
<br/>

---

#### 方法二: 迭代链接反转

**直觉**

在上个方法中，我们研究了一种反转给定链表部分的算法，该算法不改变给定链表的内在结构，只是修改了对于结点的值。 然而，有时可能无法修改结点的数据值。这时，我们就需要改变结点的链接来完成反转。

从位置 `m` 到位置 `n` 的全部结点，我们需要反转每个结点的 `next` 指针。下面来看看具体的算法。

**算法**

在看具体算法之前，有必要先弄清楚链接反转的原理以及需要哪些指针。举例而言，有一个三个不同结点组成的链表 `A → B → C`，需要反转结点中的链接成为 `A ← B ← C`。

假设我们有两个指针，一个指向结点 `A`，一个指向结点 `B`。 分别记为 `prev` 和 `cur`。则可以用这两个指针简单地实现 `A 和 B` 之间的链接反转：

```
cur.next = prev
```

这样做唯一的问题是，没有办法继续下去，换而言之，这样做之后就无法再访问到结点 `C`。因此，我们需要引入第三个指针，用于帮助反转过程的进行。因此，我们不采用上面的反转方法，而是：

```
third = cur.next
cur.next = prev
prev = cur
cur = third
```


 **迭代** 地进行上述过程，即可完成问题的要求。下面来看看算法的步骤。

1. 如上所述，我们需要两个指针 `prev` 和 `cur`。
2. `prev` 指针初始化为 `None`，`cur` 指针初始化为链表的 `head`。
3. 一步步地向前推进 `cur` 指针，`prev` 指针跟随其后。
4. 如此推进两个指针，直到 `cur` 指针到达从链表头起的第 $m$ 个结点。这就是我们反转链表的起始位置。
5. 注意我们要引入两个额外指针，分别称为 `tail` 和 `con`。`tail` 指针指向从链表头起的第$m$个结点，此结点是反转后链表的尾部，故称为 `tail`。`con` 指针指向第 $m$ 个结点的前一个结点，此结点是新链表的头部。下图可以帮助你更好的理解这两个指针。

![image.png](https://pic.leetcode-cn.com/bf38eaeb92184fbfb55bd76336c7f746b6f01b3c83bd921268afe84a3c3cf183-image.png){:width=500}
{:align=center}

6. `tail` 和 `con` 指针在算法开始时被初始化，在算法最后被调用，用于完成链表反转。
7. 如前文所解释的那样，抵达第 $m$ 个结点后，在用到上述两个指针前，先迭代地反转链接。不断迭代，直到完成指向第 $n$ 个结点的链接。此时，`prev` 指针会指向第 $n$ 个结点。
8. 我们使用 `con` 指针来连接 `prev` 指针，这是因为 `prev` 指针当前指向的结点(第 $n$ 个结点)会代替第 $m$ 个结点的位置。 类似地，我们利用 `tail` 指针来连接 `prev` 指针之后的结点（第 $n+1$ 个结点）。

为了便于理清每个指针的用法，我们来看一个算法运行的实例。给定一个链表 `7 → 9 → 2 → 10 → 1 → 8 → 6`，我们需要反转从第 3 个结点到第 6 个结点的子链表。

![image.png](https://pic.leetcode-cn.com/08d4eb39be0db6ded442a208399b5778bbab1cf75c26bc5b3d93128b7c224cb4-image.png){:width=500}
{:align=center}

从上图可以看到迭代法的前几步。第一步展示了两个指针的初始化，第三步展示了链表反转过程的初始位置。

![image.png](https://pic.leetcode-cn.com/77af1e2ca8bd5f9ccc89802094ce07e2505c6b4483ccd6887f2762a6e67310e1-image.png){:width=500}
{:align=center}

上图详细显示了链接反转的过程以及反转两个结点的链接后如何向前移动。如下图所示，本步骤将执行多次。

![image.png](https://pic.leetcode-cn.com/f634c434bcc5092d84b3125a4cd7c723aa3ddd53dcfb9ec3077423cbff1d2f85-image.png){:width=500}
{:align=center}

![image.png](https://pic.leetcode-cn.com/b11861e6d3a86cdec19152d442dd243aaf0fb6c914787e7cf60990f2ecf0d558-image.png){:width=500}
{:align=center}

如上图所示, 两个指针都已经到达最终位置。我们完成了子链表的反转工作。然而，还有一些链接需要调整。下图展示了利用 `tail` 和 `con` 指针完成链接调整的过程。

![image.png](https://pic.leetcode-cn.com/968684e83b4cbc4b4db6f80e3bda03748729af672e702a8d3473b24cd04a7092-image.png){:width=500}
{:align=center}

```Java [solution 2]
class Solution {
    public ListNode reverseBetween(ListNode head, int m, int n) {

        // Empty list
        if (head == null) {
            return null;
        }

        // Move the two pointers until they reach the proper starting point
        // in the list.
        ListNode cur = head, prev = null;
        while (m > 1) {
            prev = cur;
            cur = cur.next;
            m--;
            n--;
        }

        // The two pointers that will fix the final connections.
        ListNode con = prev, tail = cur;

        // Iteratively reverse the nodes until n becomes 0.
        ListNode third = null;
        while (n > 0) {
            third = cur.next;
            cur.next = prev;
            prev = cur;
            cur = third;
            n--;
        }

        // Adjust the final connections as explained in the algorithm
        if (con != null) {
            con.next = prev;
        } else {
            head = prev;
        }

        tail.next = cur;
        return head;
    }
}
```
```Python [solution 2]
class Solution:
    def reverseBetween(self, head, m, n):
        """
        :type head: ListNode
        :type m: int
        :type n: int
        :rtype: ListNode
        """

        # Empty list
        if not head:
            return None

        # Move the two pointers until they reach the proper starting point
        # in the list.
        cur, prev = head, None
        while m > 1:
            prev = cur
            cur = cur.next
            m, n = m - 1, n - 1

        # The two pointers that will fix the final connections.
        tail, con = cur, prev

        # Iteratively reverse the nodes until n becomes 0.
        while n:
            third = cur.next
            cur.next = prev
            prev = cur
            cur = third
            n -= 1

        # Adjust the final connections as explained in the algorithm
        if con:
            con.next = prev
        else:
            head = prev
        tail.next = cur
        return head
```

**复杂度分析**

* 时间复杂度: $O(N)$。考虑包含 $N$ 个结点的链表。对每个节点最多会处理
* （第 $n$ 个结点之后的结点不处理）。
* 空间复杂度: $O(1)$。我们仅仅在原有链表的基础上调整了一些指针，只使用了 $O(1)$ 的额外存储空间来获得结果。
<br />

