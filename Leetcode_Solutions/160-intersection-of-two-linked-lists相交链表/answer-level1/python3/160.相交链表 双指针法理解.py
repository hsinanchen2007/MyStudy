### 解题思路

开始看双指针法有些奇怪，后来才觉得精妙，前人的解释很多了，下面补充两点我觉得很关键的：

- 两个链表的结尾是没有分叉的，如果有分叉，最后分叉的链表长度也必须一样；
- 默认给两个链表的末尾添加null节点；

下面分别对以上两点进行解释：

- 假设两个链表的长度分别是a与b，双指针的原理即`a+b==b+a`，因此当两个链表相交时，两个指针必能在某一点相遇；而当两个链表在相交后又分开时，特别是当再次分开的链表长度不等时，该算法是会失效的；
- `node1 = node1.next if node1 else headB`这段代码不能替换成`node1 = node1.next if node1.next else headB`，若替换会导致输入是两个平行的链表失效，而两个相交的链表正常返回。前者的写法相当于给每个链表的结尾添置一个null节点，即`a+null+b+null==b+null+a+null`，因此当两链表平行时，结尾必定都会返回null；

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def getIntersectionNode(self, headA: ListNode, headB: ListNode) -> ListNode:
        """双指针 176ms 28.8MB"""
        node1, node2 = headA, headB
        while node1!=node2:
            node1 = node1.next if node1 else headB
            node2 = node2.next if node2 else headA
        return node1

```