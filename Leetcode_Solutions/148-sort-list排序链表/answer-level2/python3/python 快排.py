
用快排，为避免超时，在 partition 中分成三部分 (小于 pivot、等于 pivot、大于 pivot)。

first_pivot 是第一个等于 pivot 的位置，last_pivot 是最后一个等于 pivot 的位置。

如果 tmp.val < pivot，为了跳过中间等于 pivot 的部分，要换两次。

输入 [7, 5, 7, 10, 4]，当 pivot = 7, tmp.val = 4 时。
需要先 4 和 10 换，[7, 5, 7, 4, 10]，
然后 4 和 7 换，[7, 5, 4, 7, 10]。

```python
class Solution:
    def sortList(self, head: ListNode) -> ListNode:
        if not head or not head.next:
            return head

        def partition(begin, end):
            pivot = begin.val
            tmp = begin.next
            first_pivot = begin
            last_pivot = begin
            while tmp != end:
                if tmp.val < pivot:
                    last_pivot = last_pivot.next
                    tmp.val, last_pivot.val = last_pivot.val, tmp.val
                    first_pivot = first_pivot.next
                    first_pivot.val, last_pivot.val = last_pivot.val, first_pivot.val
                elif tmp.val == pivot:
                    last_pivot = last_pivot.next
                    last_pivot.val, tmp.val = tmp.val, last_pivot.val
                tmp = tmp.next
            begin.val, first_pivot.val = first_pivot.val, begin.val
            return first_pivot, last_pivot
            
        def quicksort(begin, end):
            if begin == end or begin.next == end:
                return
            first_pivot, last_pivot = partition(begin, end)
            quicksort(begin, first_pivot)
            quicksort(last_pivot.next, end)
        
        quicksort(head, None)
        return head
```