### 解题思路
时间最佳和内存最佳的方法有点无聊，学习一下其他解题方法。递归也是一个平时很少用到的方法，既然有这个机会，就啃一啃这个硬骨头。
像我这样对递归不太熟悉的小白，一般还是能够应付像斐波那契或者n！的简单问题。稍微复杂一点的可能就会觉得有点抽象。
当然这题解答得如此秀还是有一点特殊性的，相信很多人不知道，原来对于and，只要前面那一项是false，就执行完毕并且返回左表达式结果；对于or，只要前面一项是True，就执行完毕并且返回左表达式结果。
首先这题为什么能用递归，是因为我们一直在做一个重复性的事，就是比较两个链表的node的大小，然后小的接大的。这里有一个点，就是只要把l1理解为一个指针，而且这个指针仅仅指向的是一个node，跟整个链表的关系也仅仅是这个node有一个next指向下一个node，一个接一个形成了链表。千万不能把一个指向node的指针当成指向整个链表的指针。

**本题关键思路**：对比连个指针的node的值，如果l1的node比较大，l1和l2指针就来个互换，确保l1永远指向相对更小的node。然后指针的next指递归返回值，递归直到l1指向None和只剩下l2为止，然后接上l2结束。


**本题关键思路**：

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def mergeTwoLists(self, l1: ListNode, l2: ListNode) -> ListNode:
        # 特殊情况也符合这个秀的写法，就不提了
        # 一般情况下当l1指向的相对较小的node没有next了，递归就结束了
        if l1 and l2:
            # 确保l1永远指向当前两个指针指向的node中val最小的那个
            if l1.val > l2.val: l1, l2 = l2, l1
            # 较小的node的next为下一个比较中较小的node
            # 下一对需要比较的是l1.next指向的node的val和l2指向的node的val
            l1.next = self.mergeTwoLists(l1.next, l2)
        # 当l1是false，一般情况下l2还是有node的，这个时候就是返回l2接上，结束
        return l1 or l2
```