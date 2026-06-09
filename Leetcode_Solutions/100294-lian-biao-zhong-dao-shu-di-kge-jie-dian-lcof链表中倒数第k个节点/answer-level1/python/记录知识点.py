### 解题思路
此处撰写解题思路
//记录快慢指针解法//下面的解法不是快慢指针，为普通解法
输入k的值，让快指针领先慢指针k步，之后让快慢指针一起出发，即慢指针从head出发，快指针从当前位置出发， 当快指针的值为None时候，慢指针为指向的后面部分即为题解
### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def getKthFromEnd(self, head: ListNode, k: int) -> ListNode:
        dummy = ListNode(0)
        dummy.next = head
        cur = head
        count = 0
        while cur:
            cur = cur.next
            count+=1
        x = count-k
        pur = head
        while x>0:
            pur = pur.next
            x-=1
        dummy.next = pur
        return dummy.next

```