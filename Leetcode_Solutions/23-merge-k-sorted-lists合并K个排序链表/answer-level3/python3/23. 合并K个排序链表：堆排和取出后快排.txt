堆排
```python []
class Solution:
    def mergeKLists(self, lists: List[ListNode]) -> ListNode:
        heap = [[node.val, id(node), node] for node in lists if node]
        heapq.heapify(heap)
        ans = tmp = ListNode(0)
        while heap:
            *_, node = heapq.heappop(heap)
            node.next and heapq.heappush(heap, [node.next.val, id(node.next), node.next])
            tmp.next = node
            tmp = tmp.next
        return ans.next
```
快排
```python []
class Solution:
    def mergeKLists(self, lists: List[ListNode]) -> ListNode:
        vals = []
        for node in lists:
            while node:
                vals.append(node.val)
                node = node.next
        vals.sort()
        ans = tmp = ListNode(0)
        for val in vals:
            tmp.next = ListNode(val)
            tmp = tmp.next
        return ans.next
```

![image.png](https://pic.leetcode-cn.com/0251cf25ea94207c58094baf083c76b84359a347abb46d9cefd5a4e7306fe230-image.png)
