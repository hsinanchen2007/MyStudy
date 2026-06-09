欢迎大家关注我的LeetCode代码仓：[https://github.com/617076674/LeetCode]()
几乎所有题目都会提供多种解法，真诚求star！

# 解法一：暴力破解法

时间复杂度是O(n * m)，其中n为lists数组的长度，m为lists数组中链表总节点个数。
空间复杂度是O(1)。

执行用时：398ms，击败12.72%。消耗内存：52MB，击败22.17%。

```java
public class Solution {
    public ListNode mergeKLists(ListNode[] lists) {
        int n;
        if (null == lists || (n = lists.length) == 0) {
            return null;
        }
        ListNode[] curs = new ListNode[n];
        for (int i = 0; i < n; i++) {
            curs[i] = lists[i];
        }
        ListNode dummyHead = new ListNode(-1), cur = dummyHead;
        do {
            //index索引的作用是寻找一个非空的链表
            int index = 0;
            for (int i = 0; i < n; i++) {
                if (curs[i] != null) {
                    break;
                }
                index++;
            }
            if (index == n) {
                break;
            }
            int minIndex = index;
            for (int i = index + 1; i < n; i++) {
                if (curs[i] != null && curs[i].val < curs[minIndex].val) {
                    minIndex = i;
                }
            }
            cur.next = curs[minIndex];
            cur = cur.next;
            curs[minIndex] = curs[minIndex].next;
        } while (true);
        return dummyHead.next;
    }
}
```

# 解法二：优先队列

时间复杂度是O(mlogm)，其中m为lists数组中链表总节点个数。
空间复杂度是O(m)。

执行用时：14ms，击败56.53%。消耗内存：43.9MB，击败57.53%。

```java
public class Solution {
    public ListNode mergeKLists(ListNode[] lists) {
        int n;
        if (null == lists || (n = lists.length) == 0) {
            return null;
        }
        PriorityQueue<Integer> pq = new PriorityQueue<>();
        for (int i = 0; i < n; i++) {
            ListNode cur = lists[i];
            while (cur != null) {
                pq.add(cur.val);
                cur = cur.next;
            }
        }
        ListNode dummyHead = new ListNode(-1), cur = dummyHead;
        while (!pq.isEmpty()) {
            cur.next = new ListNode(pq.poll());
            cur = cur.next;
        }
        return dummyHead.next;
    }
}
```

# 解法三：优先队列，限制优先队列大小为n

时间复杂度是O(mlogn)，其中m为lists数组中链表总节点个数，n为lists数组的长度。
空间复杂度是O(n)。

执行用时：85ms，击败35.29%。消耗内存：40.9MB，击败81.11%。

```java
public class Solution {
    public ListNode mergeKLists(ListNode[] lists) {
        int n;
        if (null == lists || (n = lists.length) == 0) {
            return null;
        }
        PriorityQueue<ListNode> pq = new PriorityQueue<>(n, Comparator.comparingInt(node -> node.val));
        for (int i = 0; i < n; i++) {
            if (lists[i] != null) {
                pq.add(lists[i]);
            }
        }
        ListNode dummyHead = new ListNode(-1), cur = dummyHead;
        while (!pq.isEmpty()) {
            ListNode temp = pq.poll();
            if (temp.next != null) {
                pq.add(temp.next);
            }
            cur.next = temp;
            cur = cur.next;
        }
        return dummyHead.next;
    }
}
```

# 解法四：两两合并链表

时间复杂度是O(n * m)，其中n为lists数组的长度，m为lists数组中链表总节点个数。
空间复杂度是O(1)。

执行用时：374ms，击败14.23%。消耗内存：53.7MB，击败20.79%。

```java
public class Solution {
    public ListNode mergeKLists(ListNode[] lists) {
        int n;
        if (null == lists || (n = lists.length) == 0) {
            return null;
        }
        ListNode result = lists[0];
        for (int i = 1; i < n; i++) {
            result = mergeTwoLists(result, lists[i]);
        }
        return result;
    }

    private ListNode mergeTwoLists(ListNode l1, ListNode l2) {
        ListNode cur1 = l1, cur2 = l2, dummyHead = new ListNode(-1), cur = dummyHead;
        while (cur1 != null || cur2 != null) {
            if (cur1 == null) {
                cur.next = cur2;
                cur2 = cur2.next;
            } else if (cur2 == null) {
                cur.next = cur1;
                cur1 = cur1.next;
            } else if (cur1.val > cur2.val) {
                cur.next = cur2;
                cur2 = cur2.next;
            } else {
                cur.next = cur1;
                cur1 = cur1.next;
            }
            cur = cur.next;
        }
        return dummyHead.next;
    }
}
```