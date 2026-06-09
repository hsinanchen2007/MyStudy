####  方法一：创建新列表
**算法：**
- 如果链表有 $N$ 个结点，则分隔的链表中每个部分中都有 $n/k$ 个结点，且前 $N\%k$ 部分有一个额外的结点。我们可以用一个简单的循环来计算 $N$。
- 现在对于每个部分，我们已经计算出该部分有多少个节点：`width + (i < remainder ? 1 : 0)`。我们创建一个新列表并将该部分写入该列表。


```Python [ ]
class Solution(object):
    def splitListToParts(self, root, k):
        cur = root
        for N in xrange(1001):
            if not cur: break
            cur = cur.next
        width, remainder = divmod(N, k)

        ans = []
        cur = root
        for i in xrange(k):
            head = write = ListNode(None)
            for j in xrange(width + (i < remainder)):
                write.next = write = ListNode(cur.val)
                if cur: cur = cur.next
            ans.append(head.next)
        return ans
```

```Java [ ]
class Solution {
    public ListNode[] splitListToParts(ListNode root, int k) {
        ListNode cur = root;
        int N = 0;
        while (cur != null) {
            cur = cur.next;
            N++;
        }

        int width = N / k, rem = N % k;

        ListNode[] ans = new ListNode[k];
        cur = root;
        for (int i = 0; i < k; ++i) {
            ListNode head = new ListNode(0), write = head;
            for (int j = 0; j < width + (i < rem ? 1 : 0); ++j) {
                write = write.next = new ListNode(cur.val);
                if (cur != null) cur = cur.next;
            }
            ans[i] = head.next;
        }
        return ans;
    }
}
```

**复杂度分析**

* 时间复杂度：$O(N + k)$。$N$ 指的是链表的结点数，若 $k$ 很大，则还需要添加许多空列表。
* 空间复杂度：$O(max(N, k))$，存放答案所需的空间。


####  方法二：拆分链表
**算法：**
- 在方法 1 中，我们知道每个部分的大小。我们将不创建新列表，而是直接拆分原链表，并根据需要返回指向原始链表中节点的指针列表。

```Python [ ]
class Solution(object):
    def splitListToParts(self, root, k):
        cur = root
        for N in xrange(1001):
            if not cur: break
            cur = cur.next
        width, remainder = divmod(N, k)

        ans = []
        cur = root
        for i in xrange(k):
            head = cur
            for j in xrange(width + (i < remainder) - 1):
                if cur: cur = cur.next
            if cur:
                cur.next, cur = None, cur.next
            ans.append(head)
        return ans
```

```Java [ ]
class Solution {
    public ListNode[] splitListToParts(ListNode root, int k) {
        ListNode cur = root;
        int N = 0;
        while (cur != null) {
            cur = cur.next;
            N++;
        }

        int width = N / k, rem = N % k;

        ListNode[] ans = new ListNode[k];
        cur = root;
        for (int i = 0; i < k; ++i) {
            ListNode head = cur;
            for (int j = 0; j < width + (i < rem ? 1 : 0) - 1; ++j) {
                if (cur != null) cur = cur.next;
            }
            if (cur != null) {
                ListNode prev = cur;
                cur = cur.next;
                prev.next = null;
            }
            ans[i] = head;
        }
        return ans;
    }
}
```

**复杂度分析**

* 时间复杂度：$O(N + k)$。$N$ 指的是所给链表的结点数，若 $k$ 很大，则还需要添加许多空列表。
* 空间复杂度：$O(k)$，存储答案时所需的额外空格。