### 解题思路
#优先队列：最小堆。
注意：在LEETCODE提供的python38中，heap不能包含自定义类，很无语，在anaconda上python37是允许的

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def mergeKLists(self, lists: List[ListNode]) -> ListNode:
        #优先队列：最小堆。注意：在LEETCODE提供的python38中，heap不能包含自定义类，很无语，在anaconda上python37是允许的
        import heapq
        ahead= res = ListNode(0)
        q = []
        #将lists入优先队列
        for i in range(len(lists)):
            if lists[i] :
                heapq.heappush(q, (lists[i].val, i))#(a,b)->a,b都不能为自定义类
                lists[i] = lists[i].next
        #处理从优先队列中取出的节点
        while q:
            val, idx = heapq.heappop(q)
            res.next = ListNode(val)
            res = res.next
            if lists[idx]:
                heapq.heappush(q, (lists[idx].val, idx))
                lists[idx] = lists[idx].next
        return ahead.next


```