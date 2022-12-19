### 解题思路
那道题第一个想法就是创建两个指针，一个指针一个位置一个位置挪动，另一个两个位置挪动（隔一个）。这样子只要第二个指针指向链表最末端，就取第一个指针的值。
结果：
![屏幕快照 2020-03-23 下午12.35.39.png](https://pic.leetcode-cn.com/c0de9dd03589ba3d076df1ce6f13dd6c4cb67e0b5d458c2c390f3e0390107832-%E5%B1%8F%E5%B9%95%E5%BF%AB%E7%85%A7%202020-03-23%20%E4%B8%8B%E5%8D%8812.35.39.png)

这样子消耗的内存会多。。


### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def middleNode(self, head: ListNode) -> ListNode:
        cur = head
        cur_2 = head

        while cur_2.next != None:
            cur = cur.next
            if cur_2.next.next != None:
                cur_2 = cur_2.next.next
            else:
                cur_2 = cur_2.next

        return cur

```