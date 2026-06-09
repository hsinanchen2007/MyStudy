### 解题思路
此处撰写解题思路
利用迭代 
首先定义一个cur工作节点指向头节点head 从前往后遍历 把指向逐一翻转
再定义一个指向None的节点 pre 用于反转，最后pre为头节点，返回pre
if cur: 工作节点位置有节点就进行反转
 tmp = cur.next 保存下一个节点给tmp
 cur.next=pre 反转指向
 cur = tmp 将工作节点和pre都移动到下个处理的节点
 pre = cur

### 代码

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
        if not head or not head.next:
            return head
        pre,cur = None,head
        while(cur):
            tmp=cur.next
            cur.next = pre
            pre=cur
            cur=tmp
        return pre


```