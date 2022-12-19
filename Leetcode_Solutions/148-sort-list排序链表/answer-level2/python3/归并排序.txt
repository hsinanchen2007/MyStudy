## 思路:

归并排序, 就是分而治之!

先贴一下数组的归并排序

```python
def merge_sort(array):
    n = len(array)
    if n <= 1:
        return array
    mid = n // 2
    left = merge_sort(array[:mid])
    right = merge_sort(array[mid:])
    return merge(left, right)


def merge(left, right):
    res = []
    i = 0
    j = 0
    while i < len(left) and j < len(right):
        if left[i] < right[j]:
            res.append(left[i])
            i += 1
        else:
            res.append(right[j])
            j += 1
    res += left[i:]
    res += right[j:]
    return res
```

照着上面写,链表如下:

```python []
class Solution:
    def sortList(self, head: ListNode) -> ListNode:
    
        if not head and not head.next: return head
        slow = head
        fast = head
        # 用快慢指针分成两部分
        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next
        # 找到左右部分, 要把左部分最后置空,这样就分成两部分了
        right_part = slow.next
        slow.next = None
        left_part = head
        # 递归下去
        left = self.sortList(left_part)
        right = self.sortList(right_part)
        # 合并
        return self.merge(left, right)

    def merge(self, left, right):
        dummy = ListNode(0)
        p = dummy
        l = left
        r = right
        # 和排队一样
        while l and r:
            if l.val < r.val:
                p.next = l
                l = l.next
                p = p.next
            else:
                p.next = r
                r = r.next
                p = p.next
        if l:
            p.next = l
        if r:
            p.next = r
        return dummy.next
```



```java []
class Solution {
    public ListNode sortList(ListNode head) {
        if (head == null || head.next == null) return head;
        ListNode slow = head;
        ListNode fast = head;
        while (fast.next != null && fast.next.next != null) {
            slow = slow.next;
            fast = fast.next.next;
        }
        ListNode right_part = slow.next;
        slow.next = null;
        ListNode left_part = head;
        ListNode left = sortList(left_part);
        ListNode right = sortList(right_part);
        return merge(left, right);
    }

    private ListNode merge(ListNode left, ListNode right) {
        ListNode dummy = new ListNode(0);
        ListNode p = dummy;
        ListNode l = left;
        ListNode r = right;
        while (l != null && r != null) {
            if (l.val < r.val) {
                p.next = l;
                l = l.next;
                p = p.next;
            } else {
                p.next = r;
                r = r.next;
                p = p.next;
            }
        }
        if (l != null) p.next = l;
        if (r != null) p.next = r;
        return dummy.next;
    }
}
```

