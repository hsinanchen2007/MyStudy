####  方法一：双指针迭代
尽管问题看起来很简单，但是要编写一个涵盖所有情况的解决方案其实不简单。

通常对于链表的问题，可以采用双指针迭代的方法，用两个指针遍历链表。

用两个指针遍历的原因之一是在单链表中的没有对前继节点的引用，因此我们用一个指针指向当前节点的前继节点。

我们使用 `prev` 和 `curr` 两个指针遍历循环链表，当我们找到合适的插入位置时，我们将其插入到 `prev` 和 `curr` 之间。

![在这里插入图片描述](https://pic.leetcode-cn.com/3e1d0ddfc8aeccebc11c7890cab9deefa63a8c921ecdd85afe9e754f27814521-file_1578973196651){:width=500}

**算法：**

首先，我们定义双指针迭代的算法框架如下：
- 我们用 `prev` 和 `curr` 两个指针循环遍历链表。循环的终止条件是两个指针返回到起点，即 `prev==head`。
- 在每一次迭代过程中，我们都会检查由两个指针限定的位置是否是新值插入的正确位置。
- 如果不是正确的位置，则两个指针都向前移动一步。现在困难的地方是如何设计出一个简洁的逻辑来处理解决不同的情况。我们分为三个不同的情况。

**情况 1：** 新节点的值位于当前链表的最小值和最大值之间。因此，应该将其插入到链表中间。

![在这里插入图片描述](https://pic.leetcode-cn.com/578912ab9d1c8828de3c636289ba8655dc1092a868209105b9261f6aab8ce52e-file_1578973196682){:width=500}

从上面的例子我们可以看到，新值（`6`）位于链表的最大值和最小值之间（即 `1` 和 `9`）之间。无论从哪个节点开始（在本例子中从节点 `{3}` 开始），新节点最终会被插入到节点 `{5}` 和 `{7}` 之间。

我们要找到满足 `{prev.val <= insertVal <= curr.val}` 条件的位置。

**情况 2：** 新值超出了链表中的最小值和最大值，即小于最小值或大于最大值。在任一情况下，新值都应插入在尾节点（即链表最大值的节点）之后。

![在这里插入图片描述](https://pic.leetcode-cn.com/ecc9c26f2fd682a51edfa44f4547dab10b4b8accc11deae8aa2ea6914b042e7c-file_1578973196665){:width=500}

![在这里插入图片描述](https://pic.leetcode-cn.com/3f1610a44f083e5210993d227335546dc929b9a2e84c137988496f7d4064f22b-file_1578973196685){:width=500}

首先我们要在链表中找到相邻节点值下降的位置，即 `{prev.val>curr.val}` 来找到尾节点。因为节点值是升序排序的，所以尾节点在链表中具有最大的值。

此外，检查新值是大于尾节点的值还是小于头节点的值，分别由 `prev` 和 `curr` 指向。

图片 case 2.1 对应于新值大于或等于尾节点值的条件，即 `{insertVal>=prev.val}`。

图片 case 2.2 对应于新值小于或等于头节点值的条件，即 `{insertVal<=curr.val}`。

一旦找到头尾节点，就可以通过在头尾节点之间插入新值来扩展链表，即在 `prev` 和 `curr` 之间插入新值。

**情况 3：** 链表的元素的值相同。
尽管在问题描述中没有说明，但是链表可能出现所有节点的值均相同。

![在这里插入图片描述](https://pic.leetcode-cn.com/a3e646fc09da1631ccedfb02ec03b10974a20197eac538dbc488e824993ba7d7-file_1578973196625){:width=500}

在这种情况下，我们最终会遍历链表回到起点。然后我们可以在任一节点后插入新值，那我们不如在入口节点之后插入新值。

注意，我们不能够跳过迭代，因为必须遍历链表来确定链表是否只存在一个唯一的值。

还有一种情况，是当链表为空时，我们可以在进入循环之前解决它。

```python [solution1-Python]
class Solution:
    def insert(self, head: 'Node', insertVal: int) -> 'Node':

        if head == None:
            newNode = Node(insertVal, None)
            newNode.next = newNode
            return newNode
 
        prev, curr = head, head.next
        toInsert = False

        while True:
            
            if prev.val <= insertVal <= curr.val:
                # Case #1.
                toInsert = True
            elif prev.val > curr.val:
                # Case #2. where we locate the tail element
                # 'prev' points to the tail, i.e. the largest element!
                if insertVal >= prev.val or insertVal <= curr.val:
                    toInsert = True

            if toInsert:
                prev.next = Node(insertVal, curr)
                # mission accomplished
                return head

            prev, curr = curr, curr.next
            # loop condition
            if prev == head:
                break
        # Case #3.
        # did not insert the node in the loop
        prev.next = Node(insertVal, curr)
        return head
```

```java [solution1-Java]
class Solution {
  public Node insert(Node head, int insertVal) {
    if (head == null) {
      Node newNode = new Node(insertVal, null);
      newNode.next = newNode;
      return newNode;
    }

    Node prev = head;
    Node curr = head.next;
    boolean toInsert = false;

    do {
      if (prev.val <= insertVal && insertVal <= curr.val) {
        // Case 1).
        toInsert = true;
      } else if (prev.val > curr.val) {
        // Case 2).
        if (insertVal >= prev.val || insertVal <= curr.val)
          toInsert = true;
      }

      if (toInsert) {
        prev.next = new Node(insertVal, curr);
        return head;
      }

      prev = curr;
      curr = curr.next;
    } while (prev != head);

    // Case 3).
    prev.next = new Node(insertVal, curr);
    return head;
  }
}
```

**复杂度分析**

* 时间复杂度：$\mathcal{O}(N)$。其中 $N$ 指的时链表的元素个数。最坏的情况下我们会遍历整个链表。
* 空间复杂度：$\mathcal{O}(1)$，仅仅使用了两个指针。