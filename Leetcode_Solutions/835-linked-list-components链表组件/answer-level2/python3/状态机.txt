### 解题思路
把题意理解为：链表中所有 (在G中 且 在链表中连续) 的段的数量。  
构造一个状态机，遍历链表: (state 初始化为 False)  
- 链表当前值在G中 → state = True  
- 链表当前值不在G中 → state = False  

统计所有 state 由 False 变为 True 的次数就可以了。
1. 使用 last_state 保存上一次 state 的值
2. 使用 异或运算符(^) 和 last_state 提取所有 state 跳变的地方，即 (last_state ^ state)
3. 使用 state 筛选出来 state 由 False 变为 True 的跳变，即 (last_state ^ state) & state

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def numComponents(self, head: ListNode, G: List[int]) -> int:
        count = 0
        last_state = state = False
        G_set = set(G)
        while head:
            state = head.val in G_set
            if (last_state ^ state) & state:
                count += 1
            last_state = state
            head = head.next
        return count
```