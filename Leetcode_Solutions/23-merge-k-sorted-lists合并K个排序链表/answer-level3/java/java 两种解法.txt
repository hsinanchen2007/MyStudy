**解法一：**利用最小堆原理的优先队列，时间复杂度： O(N\log k)*O*(*N*log*k*) ；空间复杂度：*O*(*k*)，用于建立优先队列。

```java
class Solution {
    public ListNode mergeKLists(ListNode[] lists) {
        ListNode dummy = new ListNode(0), cur = dummy;
        PriorityQueue<ListNode> pq = new PriorityQueue<>((o1, o2) -> o1.val - o2.val);
        for (ListNode node : lists) {
            if (node != null) pq.add(node);
        }
        while (!pq.isEmpty()) {
            ListNode tmp = pq.remove();
            cur.next = tmp;
            if (tmp.next != null) pq.add(tmp.next);
            cur = cur.next;
        }
        return dummy.next;
    }
}
```

**解法二：**分治，时间复杂度： O(N\log k)*O*(*N*log*k*) ；空间复杂度：*O*(1)。

```java
// 自底向上的迭代求解
class Solution {
    public ListNode mergeKLists(ListNode[] lists) {
        if (lists.length == 0) return null;
        int size = lists.length;
        int k = 1;
        while (k < size) {
            for (int i = 0; i < size - k; i += 2 * k) {
                lists[i] = mergeTwoLists(lists[i], lists[i + k]);
            }
            k <<= 1;
        }
        return lists[0];
    }

    public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
        ListNode dummy = new ListNode(0), pre = dummy;
        while (l1 != null && l2 != null) {
            if (l1.val < l2.val) {
                pre.next = l1;
                l1 = l1.next;
            }else {
                pre.next = l2;
                l2 = l2.next;
            }
            pre = pre.next;           
        }
        pre.next = l1 != null ? l1 : l2;
        return dummy.next;
    }
}

// 自顶向下的递归求解
class Solution {
    public ListNode mergeKLists(ListNode[] lists) {
        if (lists.length == 0) return null;
        return merge(0, lists.length - 1, lists);
    }

    public ListNode merge(int l, int r, ListNode[] lists) {
        if (l == r) return lists[l];
        if (l == r - 1) return mergeTwoLists(lists[l], lists[r]);
        ListNode l1 = merge(l, (l + r) / 2, lists);
        ListNode l2 = merge((l + r) / 2 + 1, r, lists);
        return mergeTwoLists(l1, l2);
    }

    public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
        if (l1 == null) return l2;
        if (l2 == null) return l1;
        if (l1.val < l2.val) {
            l1.next = mergeTwoLists(l1.next, l2);
            return l1;
        }else{
            l2.next = mergeTwoLists(l1, l2.next);
            return l2;
        }
    }
}
```
测试了一下，最快的好像是mergeKLists()用递归，mergeTwoLists()用迭代。




