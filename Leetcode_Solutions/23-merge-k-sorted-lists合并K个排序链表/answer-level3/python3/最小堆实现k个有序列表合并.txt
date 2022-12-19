### 解题思路
时间负责度：O(n*logk)
空间复杂度：n+k
堆内元素是 （node.val, idx）
idx被弹出后，要补充lists[idx]的下个节点，没有的话要再弹出新的最小值
最小堆更新方法如下：
    import heapq
    heapq.heappop([])
    heapq.heappush([], iterm)
### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def mergeKLists(self, lists: List[ListNode]) -> ListNode:
        import heapq
        heap = []
        head = ListNode(-1)
        flag = head
        # 初始化最小堆
        for i, node in enumerate(lists):
            if node:
                heapq.heappush(heap, (node.val, i))
        # 每次取出堆顶最小值，补充最小值对应的链表的下个node
        while heap:
            val, idx = heapq.heappop(heap)
            head.next = ListNode(val)
            head = head.next
            # 找到补充的节点（有可能某个链表被提取完了）
            while not lists[idx].next and heap:
                val, idx = heapq.heappop(heap)
                head.next = ListNode(val)
                head = head.next
            # 补充节点
            if lists[idx].next:
                lists[idx] = lists[idx].next # 更新 链表 头节点
                heapq.heappush(heap, (lists[idx].val, idx))
        return flag.next

```
时间负责度：O(n*logk)