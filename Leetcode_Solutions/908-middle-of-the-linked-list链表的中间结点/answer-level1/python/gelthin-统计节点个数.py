### 解题思路
1. 先遍历整个链表，求出链表的总节点数目。注意判断总数目是奇数还是偶数，分别处理。
2. 然后计算出达到中点所需的步数。然后走这么多步数。

对 0,1,2,3,4,5 序列，中点是 (n-1)//2, n//2, n=6
对 0,1,2,3,4 序列，中点是 (n-1)//2 == n//2, n=5

对 1,2,3,4,5,6 序列，中点是 1 + (6-1)//2, 1 + 6//2
对 1,2,3,4,5 序列，中点是 1 + (5-1)//2, 1 + 5//2

#### 本题还可以使用快慢指针啊
liweiwei 大神在本题下的题解非常精彩。快慢指针以后得好好刷一下。



### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def middleNode(self, head: ListNode) -> ListNode:
        n = 0
        p = head
        while p:
            n += 1
            p = p.next
        if n%2 != 0:
            step = (n-1)//2 # 1,2,3,4,5
            p = head
            for i in range(step):
                p = p.next
            return p
        else:
            step = (n-1)//2  # 1,2,3,4
            p = head
            for i in range(step):
                p = p.next
            return p.next # 返回第二个节点
```