### 解题思路
快慢指针一次遍历

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def removeNthFromEnd(self, head: ListNode, n: int) -> ListNode:
        fastNode=head
        lowNode=head
        ii=0
        while fastNode:
            fastNode=fastNode.next
            ii+=1
            if ii>n+1:
                lowNode=lowNode.next
        if ii>n:
            lowNode.next=lowNode.next.next
        else:
            head=head.next
        return head
```

![image.png](https://pic.leetcode-cn.com/6e520403aaa936fabf5d8b47c59f6bd8e5a9eabff50c374e5cd78eb6aee35ea7-image.png)
