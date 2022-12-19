### 解题思路
暴力解法（没有技术含量）：
要求我们输出最中间的位置的结点，那么我们只要先遍历链表链表长度，计算中间结点的下标，然后再遍历链表，输出最中间的结点就好了

快慢指针：
顾名思义，定义一个快的指针和一个慢的指针，此题要求我们输出中间位置的结点，那么我们将快的指针定义为慢指针的两倍，这样当快指针到达最后一位数据的时候，慢指针就刚好到达中间位置的数据。
综上，我们可以将循环的结束标志定为 快指针fast 的 当前地址(fast)和下一个地址(fast.next)不为空(null) 。 



### 代码
暴力解法：
```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def middleNode(self, head: ListNode) -> ListNode:
        cur = head 
        length = 0
        while cur :
            cur = cur.next
            length += 1
        if length % 2 == 0:
            mid = length / 2  + 1
        else :
            mid = (length + 1) / 2
        cur = head 
        mid -= 1
        while mid :
            cur = cur.next
            mid -= 1
        return cur


```


快慢指针（双指针）：
```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def middleNode(self, head: ListNode) -> ListNode:
        fast , slow = head , head 
        while fast and fast.next :
            fast = fast.next.next
            slow = slow.next
        return slow


```



当然有细心的朋友会问 为什么判断条件不是fast.next and fast.next.next不为null呢?

假设链表： [1,2,3,4]
很显然中间结点是  3 

while fast.next and fast.next.next 执行语句时
fast = 3 , slow = 2 
在这时  fast.next.next = null 将不再执行while里的语句 但是slow指针才指到 2 这不是我们要的结果

但是当判断条件为 while fast and fast.next
fast = 3 , slow = 2 
在这时，条件依然成立，while可以继续执行
fast = null , slow = 3
while结束循环
这样才能得到我们要的结果