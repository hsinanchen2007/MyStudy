### 解题思路

#### **方法一：栈**（只需要两个指针实现局部翻转）
时间复杂度为O(n),空间复杂度为O(k)。因为栈每次有需要开辟k个空间。
首先定义一个哨兵节点。
用栈的思路比较简单，后进先出，每次都可以实现翻转，不过注意的是，不满足k个元素的节点就无需翻转了，因此我们需要有一个`temp_head`，用来记录能够翻转的节点的最后一个节点的下一个节点，方便与之间翻转过后的节点连接起来。

#### **方法二：利用三个指针实现局部翻转**
时间复杂度为O(n),空间复杂度为O(1),只需要开辟几个指针节点就ok。
首先定义
①一个哨兵节点。
②一个start节点，用来标记每轮（k次）翻转的头结点，因为一轮中的头结点，肯定会翻转到一轮中的最后去。所以用它来作为与之后所有节点连接的桥梁。所以一开始为head
③一个标志位flag，用来判断是否满足剩余的节点数量小于k

其实和法一的跳出判断思想是一样的，只不过法二的这个`temp_head`由start来代替了，

思路也是每次提取k个节点出来，将箭头反指，后面指向前面。

用pre来连接前一次翻转和这次翻转，start用来连接这次翻转后的正常节点。

### 代码

```python
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def reverseKGroup(self, head: ListNode, k: int) -> ListNode:
        
        self.stack = []
        p = ListNode(-1)
        result = p
        # 状态标志
        flag = True
        temp_head = head
        while head:
            for i in range(k):
                if not head:
                    flag = False
                    break
                self.stack.append(head)
                head = head.next
            if not flag:
                break
            else:
                # 更新翻转后的进行连接的节点
                temp_head = head
            for i in range(k):
                cur = self.stack.pop()
                p.next = cur
                p = cur
            # 翻转后和后面的节点相连
            p.next = temp_head
        return result.next
        
```

```python
class Solution:
    def reverseKGroup(self, head: ListNode, k: int) -> ListNode:
        # 定义一个哨兵节点
        sentry = ListNode(0)
        pre = sentry
        start = head
        flag = True
        while head:
            for i in range(k):
                if not head:
                    # 剩余节点数量小于k，跳出
                    flag = False
                    break
                head = head.next
            if not flag:
                break
            # 上次翻转后的节点连接这次翻转后的节点
            pre.next = self.reverse(start,head)
            # 连接这次翻转以后的正常节点
            start.next = head
            # 更新位置
            pre = start
            # 更新位置
            start = head
        return sentry.next

    def reverse(self,start,end):
        pre, cur, nexts = None, start, start
        # 三个指针进行局部翻转
        while cur != end:
            nexts = nexts.next
            # 箭头反指
            cur.next = pre
            # 更新pre位置
            pre = cur 
            # 更新cur位置
            cur = nexts
        return pre



```