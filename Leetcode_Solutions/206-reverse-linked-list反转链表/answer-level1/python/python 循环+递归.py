#### 理解题目

```
# 反转一个单链表。 
# 
#  示例: 
# 
#  输入: 1->2->3->4->5->NULL
# 输出: 5->4->3->2->1->NULL 
# 
#  进阶: 
# 你可以迭代或递归地反转链表。你能否用两种方法解决这道题？ 
#  Related Topics 链表


# leetcode submit region begin(Prohibit modification and deletion)
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None
```
理解：将链表的值反转
#### 解题思路
* 法一：递归
* 法二：循环

#### 法1

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
        #法二： 递归函数调用栈，先进后出，那么最后能访问到最后一个节点 再反过来改变链表指向
        # 递归停止条件
        if head is None or head.next is None:
            return head 
        root = self.reverseList(head.next) # root 为5,传入的head 为 4
        
        head.next.next = head # 4<-5
        head.next = None  # 清空之前的指向
        return root 
        

```
##### 复杂度分析
* 时间复杂度：O(n)
* 空间复杂度:O(n)
#### 法2

```Python
class Solution:
    def reverseList(self, head: ListNode) -> ListNode:
        # 循环
        pre, cur = None, head
        while cur:
            next_node = cur.next
            cur.next = pre
            pre = cur
            cur = next_node
        return pre
```
##### 复杂度分析
* 时间复杂度：O(N)
* 空间复杂度：O(1)