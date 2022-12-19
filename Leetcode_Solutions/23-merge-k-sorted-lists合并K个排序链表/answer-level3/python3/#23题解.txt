### 解题思路1
分治法，分别两两合并，最终组成一个链表。
时间复杂度o（Nlogk），其中N为所有元素个数，k为链表个数。分治法共合并了logk轮，每轮比较了N次。

### 代码

```python3
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
### 解题思路2
依次比较，找到最小的开头（超时）

### 代码
```
from queue import PriorityQueue
class Solution(object):
    def mergeKLists(self, lists):
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


### 解题思路3
依次比较，找到最小的开头（超时）

### 代码
```
class Solution(object):
    def mergeKLists(self, lists):
        minnum=None
        index=-1
        linked=ListNode(0)
        linked1=linked
        while True:
            for i,num in enumerate(lists):
                if num:
                    if minnum==None or minnum>=num.val:
                        minnum=num.val
                        index=i
            if minnum!=None:
                lists[index]=lists[index].next
                linked.next=ListNode(minnum)
                linked=linked.next
            else:
                break
            index=-1
            minnum=None
        return linked1.next
```
