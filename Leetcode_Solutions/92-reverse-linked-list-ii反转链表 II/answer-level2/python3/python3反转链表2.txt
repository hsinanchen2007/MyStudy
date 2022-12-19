### 解题思路
使用双指针，先找出反转链表的头部和尾部，再使用反转链表方法对目标区域进行反转

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def reverseBetween(self, head: ListNode, m: int, n: int) -> ListNode:
        prev=ListNode(0)
        prevh=prev
        prev.next=head
        k=0
        while k<m-1:
            prev=prev.next
            k+=1
        tail=prev
        while k<n:
            tail=tail.next
            k+=1
        front=prev.next
        prev.next=tail
        prev=tail.next
        tail.next=None
        while front:
            r=front.next
            front.next=prev
            prev=front
            front=r
        return prevh.next
```
![image.png](https://pic.leetcode-cn.com/521399b3fed58e02ad79944009ea223a69c8db981fa1b969e4f56cd30ec8e104-image.png)
