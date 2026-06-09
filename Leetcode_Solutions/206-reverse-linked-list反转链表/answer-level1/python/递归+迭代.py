# ### 方法一：迭代
# 从头到尾迭代每个元素。

# #### 代码

# ```python []
class Solution:
    def reverseList(self, head: ListNode) -> ListNode:
        pre = None
        cur = head
        while cur:
            nexttmp = cur.next
            cur.next = pre
            pre = cur
            cur = nexttmp
        return pre
# ```
# #### 复杂度分析
# - 时间复杂度：$O(n)$。
# - 空间复杂度：$O(1)$。

# ### 方法二：递归
# #### 代码
# ```python []
class Solution:
    def reverseList(self, head: ListNode) -> ListNode:
        if not head or not head.next: return head

        p = self.reverseList(head.next)
        head.next.next = head
        head.next = None
        return p
# ```
# #### 复杂度分析
# - 时间复杂度：$O(n)$。
# - 空间复杂度：$O(n)$。

# PS：想要一起努力的童鞋们可以关注我的公众号：腐烂的橘子，致力于摆脱算法的抽象思维，彻底搞懂算法，同时公众号还会发布面试中的高频知识点，一起努力吧！😋