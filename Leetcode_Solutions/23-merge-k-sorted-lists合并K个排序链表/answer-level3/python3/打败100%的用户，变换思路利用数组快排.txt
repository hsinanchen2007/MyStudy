# 思想
## 原理非常简单，当有多个表时，我们判断每个链表的大小关系需要多个循环，非常慢，我们换一种思路来看这个问题，我们将每个链表种的元素都拿出来组成一个数组，对数组使用快排，快排之后将其转化为ListNode，这样代码执行非常快速，速度为O(N)
```
class Solution:
    def mergeKLists(self, lists: List[ListNode]) -> ListNode:
        p = ListNode(-1)
        k = p
        n,i = len(lists),0
        a = []
        for i in range(n):
            while(lists[i]):
                a.append(lists[i].val)
                lists[i] = lists[i].next
        a.sort()
        for i in a:
            k.next = ListNode(i)
            k = k.next
        return p.next
```
