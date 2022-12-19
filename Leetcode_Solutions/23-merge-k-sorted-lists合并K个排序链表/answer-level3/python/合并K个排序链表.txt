![#023 合并K个排序链表.mp4](7edbd1ea-cfe1-43c9-a146-13ee2f994d7f)


#### 方法 1：暴力
**想法 & 算法**

- 遍历所有链表，将所有节点的值放到一个数组中。
- 将这个数组排序，然后遍历所有元素得到正确顺序的值。
- 用遍历得到的值，创建一个新的有序链表。

关于排序，你可以参考 [这里](https://www.cs.cmu.edu/~adamchik/15-121/lectures/Sorting%20Algorithms/sorting.html) 获得更多关于排序算法的内容。

```Python []
class Solution(object):
    def mergeKLists(self, lists):
        """
        :type lists: List[ListNode]
        :rtype: ListNode
        """
        self.nodes = []
        head = point = ListNode(0)
        for l in lists:
            while l:
                self.nodes.append(l.val)
                l = l.next
        for x in sorted(self.nodes):
            point.next = ListNode(x)
            point = point.next
        return head.next
```

**复杂度分析**

* 时间复杂度：$O(N\log N)$ ，其中 $N$ 是节点的总数目。
    - 遍历所有的值需花费 $O(N)$ 的时间。
    - 一个稳定的排序算法花费 $O(N\log N)$ 的时间。
    - 遍历同时创建新的有序链表花费 $O(N)$ 的时间。

* 空间复杂度：$O(N)$ 。
    - 排序花费 $O(N)$ 空间（这取决于你选择的算法）。
    - 创建一个新的链表花费 $O(N)$ 的空间。

#### 方法 2：逐一比较

**算法**
- 比较 $\text{k}$ 个节点（每个链表的首节点），获得最小值的节点。
- 将选中的节点接在最终有序链表的后面。

**复杂度分析**

* 时间复杂度： $O(kN)$ ，其中 $\text{k}$ 是链表的数目。
    - 几乎最终有序链表中每个节点的时间开销都为 $O(k)$ （$\text{k-1}$ 次比较）。
    - 总共有 $N$ 个节点在最后的链表中。


* 空间复杂度：
    - $O(n)$ 。创建一个新的链表空间开销为 $O(n)$ 。
    - $O(1)$ 。重复利用原来的链表节点，每次选择节点时将它直接接在最后返回的链表后面，而不是创建一个新的节点。

#### 方法 3：用优先队列优化方法 2

**算法**

几乎与上述方法一样，除了将 **比较环节** 用 **优先队列** 进行了优化。你可以参考 [这里](https://baike.baidu.com/item/%E4%BC%98%E5%85%88%E9%98%9F%E5%88%97/9354754?fr=aladdin) 获取更多信息。

```Python []
from Queue import PriorityQueue

class Solution(object):
    def mergeKLists(self, lists):
        """
        :type lists: List[ListNode]
        :rtype: ListNode
        """
        head = point = ListNode(0)
        q = PriorityQueue()
        for l in lists:
            if l:
                q.put((l.val, l))
        while not q.empty():
            val, node = q.get()
            point.next = ListNode(val)
            point = point.next
            node = node.next
            if node:
                q.put((node.val, node))
        return head.next
```

**复杂度分析**

* 时间复杂度： $O(N\log k)$ ，其中 $\text{k}$ 是链表的数目。
    - 弹出操作时，比较操作的代价会被优化到 $O(\log k)$ 。同时，找到最小值节点的时间开销仅仅为 $O(1)$。
    - 最后的链表中总共有 $N$ 个节点。


* 空间复杂度：
    - $O(n)$ 。创造一个新的链表需要 $O(n)$ 的开销。
    - $O(k)$ 。以上代码采用了重复利用原有节点，所以只要 $O(1)$ 的空间。同时优先队列（通常用堆实现）需要 $O(k)$ 的空间（远比大多数情况的 $N$要小）。

#### 方法 4：逐一两两合并链表

**算法**

将合并 $\text{k}$ 个链表的问题转化成合并 2 个链表 $\text{k-1}$ 次。这里是 [合并两个有序链表](https://leetcode-cn.com/problems/merge-two-sorted-lists/) 的题目。

**复杂度分析**

* 时间复杂度： $O(kN)$ ，其中 $\text{k}$ 是链表的数目。
    - 我们可以在 $O(n)$ 的时间内合并两个有序链表，其中 $n$ 是两个链表的总长度。
    - 把所有合并过程所需的时间加起来，我们可以得到： $O(\sum_{i=1}^{k-1} (i*(\frac{N}{k}) + \frac{N}{k})) = O(kN)$ 。

* 空间复杂度：$O(1)$
    - 我们可以在 $O(1)$ 空间内合并两个有序链表。

#### 方法 5：分治

**想法 & 算法**

这个方法沿用了上面的解法，但是进行了较大的优化。我们不需要对大部分节点重复遍历多次。

  - 将 $\text{k}$ 个链表配对并将同一对中的链表合并。
  - 第一轮合并以后， $\text{k}$ 个链表被合并成了 $\frac{k}{2}$ 个链表，平均长度为 $\frac{2N}{k}$ ，然后是 $\frac{k}{4}$ 个链表， $\frac{k}{8}$ 个链表等等。
  - 重复这一过程，直到我们得到了最终的有序链表。

因此，我们在每一次配对合并的过程中都会遍历几乎全部 $N$ 个节点，并重复这一过程 $\log_2K$ 次。


![image.png](https://pic.leetcode-cn.com/6f70a6649d2192cf32af68500915d84b476aa34ec899f98766c038fc9cc54662-image.png){:width="400"}
{:align="center"}


```Python []
class Solution(object):
    def mergeKLists(self, lists):
        """
        :type lists: List[ListNode]
        :rtype: ListNode
        """
        amount = len(lists)
        interval = 1
        while interval < amount:
            for i in range(0, amount - interval, interval * 2):
                lists[i] = self.merge2Lists(lists[i], lists[i + interval])
            interval *= 2
        return lists[0] if amount > 0 else lists

    def merge2Lists(self, l1, l2):
        head = point = ListNode(0)
        while l1 and l2:
            if l1.val <= l2.val:
                point.next = l1
                l1 = l1.next
            else:
                point.next = l2
                l2 = l1
                l1 = point.next.next
            point = point.next
        if not l1:
            point.next=l2
        else:
            point.next=l1
        return head.next
```

**复杂度分析**

* 时间复杂度： $O(N\log k)$ ，其中 $\text{k}$ 是链表的数目。
  - 我们可以在 $O(n)$ 的时间内合并两个有序链表，其中 $n$ 是两个链表中的总节点数。
  - 将所有的合并进程加起来，我们可以得到：$O\big(\sum_{i=1}^{log_2k}N \big)= O(N\log k)$ 。


* 空间复杂度：$O(1)$
  - 我们可以用 $O(1)$ 的空间实现两个有序链表的合并。