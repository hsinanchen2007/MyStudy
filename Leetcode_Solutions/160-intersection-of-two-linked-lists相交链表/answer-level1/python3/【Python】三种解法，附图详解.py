### 解题思路

### 方法1：存链表节点进行查询
（1）遍历链表A，并将其节点存入集合（2）遍历B的每个节点并在集合中进行查询，一旦遍历过程中查询到相同节点，即说明有交点，否则无
### 代码
```python3
class Solution:
    def getIntersectionNode(self, headA: ListNode, headB: ListNode) -> ListNode:
        A = set()
        cur1 = headA
        cur2 = headB
        while cur1:
            A.add(cur1)
            cur1 = cur1.next
        while cur2:
            if cur2 in A:
                return cur2
            cur2 = cur2.next
        return None
```



### 方法2：算出链表距离差挨个对比
分别遍历两个链表，并记录两链表的长度差n，将出现两种情况，（1）如果遍历完，尾部的空节点不是同一节点（内存地址不同），那么必然是不相交
（2）若是同一节点，则说明两链表存在相交，让长链表先走n步，再同时开始走，并对比两个链表的当前节点，节点相等时即为交点
![图片2.png](https://pic.leetcode-cn.com/5f9dfc218c25dacaf6712e1a9280d4234a12647832441252e47517704c6df3b9-%E5%9B%BE%E7%89%872.png)


### 代码
```python3
class Solution:
    def getIntersectionNode(self, headA: ListNode, headB: ListNode) -> ListNode:
        cur1 = headA
        cur2 = headB
        n = 0
        while cur1:
            n += 1
            cur1 = cur1.next
        while cur2:
            n -= 1
            cur2 = cur2.next
        if cur1 != cur2:
            return None
        cur1 = headA if n > 0 else headB
        cur2 = headB if cur1 == headA else headA
        n = abs(n)
        while n:
            n -= 1
            cur1 = cur1.next
        while cur1 != cur2:
            cur1 = cur1.next
            cur2 = cur2.next
        return cur1

        
        return None
```




### 方法3：拼接链表
拼接方式：（1）当A走到尾部的Null的时候，转到B链表的头节点继续走（2）当B走到尾部的Null的时候，转到B链表的头节点继续走
值得注意的是，如图所示，无论是相交还是不相交，对于无环的链表来说，都一定会相遇，因此不会死循环。
![图片1.png](https://pic.leetcode-cn.com/33571b44c5885703832d01df7dc697a6356e7b4476663d5447f5d3ce22c966e2-%E5%9B%BE%E7%89%871.png)
### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def getIntersectionNode(self, headA: ListNode, headB: ListNode) -> ListNode:
        cur1 = headA
        cur2 = headB
        while cur1 != cur2:
            cur1 = cur1.next if cur1 else headB
            cur2 = cur2.next if cur2 else headA
        return cur1

```