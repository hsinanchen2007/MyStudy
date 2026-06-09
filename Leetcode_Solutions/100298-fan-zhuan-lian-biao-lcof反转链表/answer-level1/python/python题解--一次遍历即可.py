### 解题思路
![image.png](https://pic.leetcode-cn.com/8bb197b3751ff58f5f1c86f5b25a5bfb0fc0f77be1b0c2029357b77e0ec47dbe-image.png)

- 思路如下:
- 给定如下链表`1->2->3->4->5->NULL`,其最后结果为`5->4->3->2->1->NULL`.
- 我们初始化一个头结点`result`,另`result.next = None`,因为我们知道第一个节点将是结果中的最后一个节点.
- 在设置`temp_1 = head.next`,初始化`temp_2 = None`
- 我们下面就开始遍历了,我们的目的是反转整个链表,所以我们从链表中取下一个节点`temp_1`,这是我么应先记录下`temp_1`的下一个节点,即`temp_2 = temp_1.next`,在将`temp_1`这个节点作为我们`result`的头结点,接着`result = temp_1`
- 如此循环下去,直到`temp_1`为空,也就是链表访问结束,`result`就是我们反转链表的头结点
- 时间复杂度`O(n)`,空间复杂度`O(1)`
- ### 代码

```python
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def reverseList(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        if not head:
            return []
        result = ListNode(head.val)
        result.next = None
        temp_1 = head.next
        temp_2 = None
        while temp_1:
            temp_2 = temp_1.next
            temp_1.next = result
            result = temp_1
            temp_1 = temp_2
        return result


```