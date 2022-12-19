本题要求我们改变链表结构，使得值小于 `x`的元素，位于值大于等于`x`元素的前面。这实质上意味着在改变后的链表中有某个点，在该点`之前`的元素全部小于`x` ，该点`之后`的元素全部 大于等于`x`。
我们将这个点记为`JOINT`。

![image.png](https://pic.leetcode-cn.com/a89965965f8d98076fa32bef306a8580044874dc8cfe2c9fb28de155901658f9-image.png){:width=700px}
{:align="center"}

对该问题的逆向工程告诉我们，如果我们在`JOINT`将改后链表拆分，我们会得到两个更小的链表，其中一个包括全部值小于`x`的元素，另一个包括全部值大于`x`的元素。在解法中，我们的主要目的是创建这两个链表，并将它们连接。
#### 双指针法：

**直觉**

我们可以用两个指针`before` 和 `after` 来追踪上述的两个链表。两个指针可以用于分别创建两个链表，然后将这两个链表连接即可获得所需的链表。

**算法**

1. 初始化两个指针 `before` 和 `after`。在实现中，我们将两个指针初始化为哑 `ListNode`。这有助于减少条件判断。（不信的话，你可以试着写一个不带哑结点的方法自己看看！）

![image.png](https://pic.leetcode-cn.com/c688c95bea37ba6d146f5488544cf775f27a6275baf06a4e0721971931701de4-image.png){:width=400px}
{:align="center"}

2. 利用`head`指针遍历原链表。
3. 若`head` 指针指向的元素值 *小于*  `x`，该节点应当是 `before` 链表的一部分。因此我们将其移到 `before` 中。

![image.png](https://pic.leetcode-cn.com/dcca771242fd52f47eec9d46a7a9f28e14f12aa3f7812a7e4ed10bec699fd45c-image.png){:width=700px}
{:align="center"}

4. 否则，该节点应当是`after` 链表的一部分。因此我们将其移到 `after` 中。

![image.png](https://pic.leetcode-cn.com/e3ba113ee4b09ec646723077ae35774e077262d4596c122dbd26a5f6090c77ef-image.png){:width=700px}
{:align="center"}

5. 遍历完原有链表的全部元素之后，我们得到了两个链表 `before` 和 `after`。原有链表的元素或者在`before` 中或者在 `after` 中，这取决于它们的值。


![image.png](https://pic.leetcode-cn.com/f1c7797cce53e0a2334af83bfd207c84e1195db4b74a962253c49e3798b4eb45-image.png){:width=700px}
{:align="center"}

    *`注意:` 由于我们从左到右遍历了原有链表，故两个链表中元素的相对顺序不会发生变化。另外值得注意的是，在图中我们完好地保留了原有链表。事实上，在算法实现中，我们将节点从原有链表中移除，并将它们添加到别的链表中。我们没有使用任何额外的空间，只是将原有的链表元素进行移动。*

6. 现在，可以将 `before` 和 `after` 连接，组成所求的链表。


![image.png](https://pic.leetcode-cn.com/f1bb41e5ae3a34bed722b5a703fb4a81474850781da1597617cd52ce5d3676e4-image.png){:width=700px}
{:align="center"}

为了算法实现更容易，我们使用了哑结点初始化。不能让哑结点成为返回链表中的一部分，因此在组合两个链表时需要向前移动一个节点。

```Java [solution 1]
class Solution {
    public ListNode partition(ListNode head, int x) {

        // before and after are the two pointers used to create the two list
        // before_head and after_head are used to save the heads of the two lists.
        // All of these are initialized with the dummy nodes created.
        ListNode before_head = new ListNode(0);
        ListNode before = before_head;
        ListNode after_head = new ListNode(0);
        ListNode after = after_head;

        while (head != null) {

            // If the original list node is lesser than the given x,
            // assign it to the before list.
            if (head.val < x) {
                before.next = head;
                before = before.next;
            } else {
                // If the original list node is greater or equal to the given x,
                // assign it to the after list.
                after.next = head;
                after = after.next;
            }

            // move ahead in the original list
            head = head.next;
        }

        // Last node of "after" list would also be ending node of the reformed list
        after.next = null;

        // Once all the nodes are correctly assigned to the two lists,
        // combine them to form a single list which would be returned.
        before.next = after_head.next;

        return before_head.next;
    }
}
```

```Python [solution 1]
class Solution(object):
    def partition(self, head, x):
        """
        :type head: ListNode
        :type x: int
        :rtype: ListNode
        """

        # before and after are the two pointers used to create two list
        # before_head and after_head are used to save the heads of the two lists.
        # All of these are initialized with the dummy nodes created.
        before = before_head = ListNode(0)
        after = after_head = ListNode(0)

        while head:
            # If the original list node is lesser than the given x,
            # assign it to the before list.
            if head.val < x:
                before.next = head
                before = before.next
            else:
                # If the original list node is greater or equal to the given x,
                # assign it to the after list.
                after.next = head
                after = after.next

            # move ahead in the original list
            head = head.next

        # Last node of "after" list would also be ending node of the reformed list
        after.next = None
        # Once all the nodes are correctly assigned to the two lists,
        # combine them to form a single list which would be returned.
        before.next = after_head.next

        return before_head.next
```

**复杂度分析**

* 时间复杂度: $O(N)$，其中$N$是原链表的长度，我们对该链表进行了遍历。
* 空间复杂度: $O(1)$，我们没有申请任何新空间。值得注意的是，我们只移动了原有的结点，因此没有使用任何额外空间。
