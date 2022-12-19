### 解题思路
来源: https://segmentfault.com/a/1190000020546996
在网上看到有朋友尝试用栈先进后出的性质，通过数组接受链表的遍历值，再通过数组逆序赋值链表实现的思路。总体思路感觉比较清晰，代码也不复杂。但是这里有代码有一个疑惑点想请教下各位。
![微信图片_20200326085636.png](https://pic.leetcode-cn.com/b1668df3fcfdc37d5dbca944a1ff705d7a12c59f327518a21673aa631fb4a5e0-%E5%BE%AE%E4%BF%A1%E5%9B%BE%E7%89%87_20200326085636.png)

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def reverseList(self, head: ListNode) -> ListNode:
        lst = []
        temp1 = head  # 这种赋值是代表什么意思？
        while temp1:    
            lst.append(temp1.val)
            temp1 = temp1.next
        i = len(lst)-1
        temp2 = head    # 这种赋值是代表什么意思？
        while i>=0:
            temp2.val = lst[i]
            temp2 = temp2.next
            i -= 1
        return head


```