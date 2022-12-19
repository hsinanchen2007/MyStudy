### 解法一：快慢指针+改链表
执行用时 :88 ms, 在所有 Python3 提交中击败了43.83%的用户
内存消耗 :23.6 MB, 在所有 Python3 提交中击败了5.12%的用户

思路：
1. 找到中点
2. 把中点右半部分的链表翻转（不包括中点）
3. 得到类似于这样的一个链表1->2->3->2<-1(2指向None)，左右开弓判断链表是否是回文链表

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    
    def reverse(self, head):
        pre = None
        cur = nxt = head
        while cur:
            nxt = cur.next
            cur.next = pre
            pre = cur
            cur = nxt
        return pre
    
    def isPalindrome(self, head: ListNode) -> bool:
        # 找到中点：快慢指针
        p = q = head
        while q and q.next:
            p = p.next
            q = q.next.next
        if q:
            p = p.next
        
        # 把后半部分翻转过来
        res = self.reverse(p)
        
        # 判断是不是回文链表
        p = head
        q = res
        while q:
            if p.val == q.val:
                p = p.next
                q = q.next
            else:
                return False
        return True
        
```

### 解法二：递归
个人觉得这种解法有点儿难理解

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    
    def isPalindrome(self, head: ListNode) -> bool:
        self.left = head  # left要写在外面 不能被递归进去

        def stack(right):
            if not right:
                return True
            res = stack(right.next)  # 相当于入栈
            # 每次出栈之后做的
            res = res and self.left.val == right.val
            self.left = self.left.next
            return res
            
        return stack(head)
```