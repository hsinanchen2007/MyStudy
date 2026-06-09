### 解题思路
【plus】
不知道怎么修改字体颜色，所以发图片了；
不知道为什么，步骤和靠前的解法几乎一样，但提交后才到前66%左右

![image.png](https://pic.leetcode-cn.com/fc6ad82511fa7b1f727c30a07d90f1f5dae7be1f088807d9c259940b0699d14c-image.png)

![image.png](https://pic.leetcode-cn.com/17d2a381a2af1a1780ece7c6f86f2c7240034a90c4a7412d3b68fc42f5d10331-image.png)

逻辑如上，各个 关键点的相对位置 和 环内结点数量 无关，画图只是方便理解；
如果难以理解环比较小的情况，可以把环多次重复变成大环进行理解
- 如环内只有结点0、1；可以看成有结点0、 1、 0、 1、 0、 1...，构成足够大的环，当结点标号相等时，看做同一个结点
- 实际上，我们关心的只是相对位置关系，和环大小、绕着环走了多少圈无关（将环扩大理解后，过程可能相当于在原来的小环中多次相遇，但不影响最终结果）

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def detectCycle(self, head: ListNode) -> ListNode:
        slow = fast = head

        while fast and fast.next:
            slow, fast = slow.next, fast.next.next
            ## 有环
            if slow is fast:
                ## 相遇处结点meetNode
                meetNode = slow
                
                start = head
                while start != meetNode:
                    start, meetNode = start.next, meetNode.next
                return meetNode

        return None
                

            
```