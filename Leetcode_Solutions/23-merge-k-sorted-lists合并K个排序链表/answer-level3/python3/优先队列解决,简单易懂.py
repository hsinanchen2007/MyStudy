### 解题思路
遍历lists,将每一个链表的节点添加到堆中,之后不断从堆中取最小值,添加到新的链表中,最后返回这个列表
![image.png](https://pic.leetcode-cn.com/1e50ae5dda3ab2bc7c87e103f6244009c74fa6cb33a42f161b176ed66c93feee-image.png)

### 代码

```python3
import heapq
class Solution:
    def mergeKLists(self, lists: [ListNode]) -> ListNode:
        k=len(lists)
        heap=[]
        pre=ListNode(0)#用于构成返回链表的头节点
        cur=pre
        node=ListNode(0)#用于访问lists的头节点
        for i in range(k):
            node.next=lists[i]
            while node.next:
                node = node.next
                heapq.heappush(heap,node.val)#存入堆的元素只能是数值,不能是链表的节点,所以是node.val
        while heap:
            b=heapq.heappop(heap)
            cur.next=ListNode(b)#将返回的int型变量转换为链表的结点型,然后不断先后
            cur=cur.next
        return pre.next
```