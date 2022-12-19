### 思路一：暴力法
对于链表一上每一个节点，遍历链表二看是否有节点和链表一上的一样。


时间复杂度：O(M*N)
空间复杂度：O(1)


## 思路二：
**公共节点的意义：两节点的值和指针都一样。因此仅判断值是否相同，不可行。**
若存在公共节点，则公共节点之后的节点都是重合的，不再出现分叉。即成Y字形。
因此可以从尾部向前比较，最后一个相同的节点就是公共节点。

由于单向列表，只能从头开始遍历，因此可以借用两个辅助栈存储两链表的节点。如果相同，从栈顶弹出再比较下一个栈顶节点，直到找到最后一个相同节点。


时间复杂度：O(M+N)
空间复杂度：O(M+N)  用空间换时间


### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def getIntersectionNode(self, headA: ListNode, headB: ListNode) -> ListNode:
        if not headA or not headB:
            return None

        a,b = [], []

        while headA:
            a.append(headA)
            headA = headA.next
        while headB:
            b.append(headB)
            headB = headB.next

        for i in range(1, min(len(a), len(b))+1):
            if a[-i] is b[-i]:
                if i == min(len(a), len(b)):
                    return a[-i]
                else:
                    continue
            else:
                return a[-i].next
```

## 思路三：
思路三和思路二类似，只是不用辅助栈。
由于两个链表长度不一致，为了让从头遍历时，双指针能同时到达尾节点。可以让较长链表的指针先走几步，然后同时开始遍历。先走的长度就是两链表长度的差值。


时间复杂度：O(M+N)
空间复杂度：O(1)


### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def getIntersectionNode(self, headA: ListNode, headB: ListNode) -> ListNode:
        cnt_a, cnt_b = 0, 0
        cur_a, cur_b = headA, headB

        while cur_a:
            cnt_a += 1
            cur_a = cur_a.next
        while cur_b:
            cnt_b += 1
            cur_b = cur_b.next

        for i in range(abs(cnt_a - cnt_b)):
            if cnt_a >= cnt_b:
                headA = headA.next
            else:
                headB = headB.next
        
        while headA and headB:
            if headA is not headB:
                headA, headB = headA.next, headB.next
            else:
                return headA

        return None
```

## 思路四：相遇法
在题解中看到的非常巧妙的方法。

若有公共节点：
假设链表一的长度是L1+C,链表二的长度是L2+C，C时公共节点的长度。那么当双指针同时走过L1+L2+C时，就到达同一个位置。因此当指针一走到尾节点时，下一次从链表二的头节点开始遍历；当指针二走到尾节点时，下一次从链表一的头节点开始遍历。当双指针相遇时，就到达了公共节点。

若没有公共节点：
那么C=0，双指针走了L1+L2步，同时走到两链表的尾节点指向的None。此时node1和node2相等，返回node1，即None。
因此为免于判断特殊情况，if条件中需要判断的是node是否为None，而不是node.next！！


时间复杂度：O(M+N)
空间复杂度：O(1)


### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def getIntersectionNode(self, headA: ListNode, headB: ListNode) -> ListNode:
        node1, node2 = headA, headB
        
        while node1 != node2:
            node1 = node1.next if node1 else headB
            node2 = node2.next if node2 else headA

        return node1
```