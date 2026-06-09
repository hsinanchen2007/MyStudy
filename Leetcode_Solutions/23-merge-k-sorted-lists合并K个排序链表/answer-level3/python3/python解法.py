**第一种：暴力破解法（速度很快）**
```
class Solution:
    def mergeKLists(self, lists: List[ListNode]) -> ListNode:
        nodes = []
        if not lists:
            return None
        if len(lists) == 1:
             return lists[0] 
        for l in lists:
            while l:
                nodes.append(l)
                if not l.next:
                    break
                l = l.next
        if not nodes:
            return None
        ordered = sorted(nodes,key=lambda x:x.val)
        ordered[-1].next = None
        dummy = ListNode(0) 
        point = dummy
        for node in ordered:
            point.next = node
            point = point.next

        return dummy.next
```
![image.png](https://pic.leetcode-cn.com/89f9efd351cc876c249c7e6da6a7bd2f3c6b6c5901b5f887b4dfa3b5ad94529f-image.png)

**第二种方法：头节点逐次比较**

速度很慢，遗憾超时
```
class Solution:
    def mergeKLists(self, lists: List[ListNode]) -> ListNode:

        if not lists:
            return None
        if len(lists) == 1:
            return lists[0] 
        dummy = ListNode(0)
        point = dummy
        while True:
            lists = sorted(lists,key=lambda x:x.val if x else float('inf'))
            #print(lists[0].val)
            if not lists[0]:
                break
            point.next = lists[0]
            point = point.next    
            #print(lists[0].next.val)
            lists[0] = lists[0].next

        return dummy.next
```

**第三种解法：通过优先队列对第二种方法的优化**

```
from queue import PriorityQueue


def mergeKLists(lists):
    head = point = ListNode(0)
    q = PriorityQueue()
    for l in lists:
        if l:
            #优先级队列自动根据val值确定出列顺序
            q.put((l.val, l))
    while not q.empty():
        val, node = q.get()
        point.next = node
        point = point.next
        node = node.next
        if node:
            #当前节点若不为空，继续加入队列
            q.put((node.val, node))
    return head.next
```

由于站点已经将ListNode类定义，所以优先队列无法将节点排序，可在本地自定义该类，本地执行