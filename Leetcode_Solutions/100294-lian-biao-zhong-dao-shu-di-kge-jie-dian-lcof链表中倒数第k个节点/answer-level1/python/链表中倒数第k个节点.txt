### 解题思路
## 思路一：往前走N-K+1步
需要先遍历一遍得到链表的长度N，然后从头节点开始往前走N-K+1步即走到倒数第k个结点

时间复杂度：O(2N)
空间复杂度：O(1)

## 思路二：双指针--快慢指针法：
第一个指针先走K-1步，然后两指针始终保持K-1的间距，直到第一个指针走到末尾，则第二个指针就在倒数第K个位置

时间复杂度：O(N)
空间复杂度：O(1)

注：需要考虑三种特殊情况：
1. 空链表
2. 倒数第0个节点
3. k超出链表长度

双指针法的延伸：
1. 速度快慢不一样，成倍数关系
2. 先走后走



### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def getKthFromEnd(self, head: ListNode, k: int) -> ListNode:
        if not head or not k:
            return None

        p1 = head
        p2 = head
        
        for _ in range(k):
            if p1:
                p1 = p1.next
            else:
                return None

        while p1 != None:
            p1 = p1.next
            p2 = p2.next

        return p2
```