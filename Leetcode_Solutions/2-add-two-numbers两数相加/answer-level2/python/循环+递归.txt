### 解题思路
将节点+数字的算法写成函数plus(l2,num)
将l1每一位的数字加到l2对应的位上
发生进位时判断l2.next是否存在，不存在则创建，存在则plus(l2.next,1)
用递归方式处理多次进位。
我不明白的是这个方法为什么内存消耗13.7M，打败5%。。。还有办法优化内存使用量吗

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        l2s=l2
        def plus(l2,num):
            s=l2.val+num
            if s<10:
                l2.val = s
            else:
                l2.val = s-10
                if l2.next==None:
                    l2.next = ListNode(1)
                else:
                    plus(l2.next,1)
           

        while l1:
            plus(l2,l1.val)
            l1=l1.next
            if l1 and l2.next==None:
                l2.next=ListNode(0)
            l2=l2.next

        return l2s

```