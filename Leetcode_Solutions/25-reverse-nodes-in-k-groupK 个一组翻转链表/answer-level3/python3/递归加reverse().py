```
class Solution:  # 递归法
    def reverseKGroup(self, head: ListNode, k: int) -> ListNode:
        if not head or k == 1: return head
        temp = head
        dumpy = result = ListNode(0)
        # 取出前k个元素
        k_list = []
        for _ in range(k):  # 取出前k个节点的值
            k_list.append(temp.val)
            temp = temp.next
            if not temp:
                break
        if len(k_list) == k:  # 前k个节点值翻转
            k_list.reverse()
        for i in k_list:
            dumpy.next = ListNode(i)
            dumpy = dumpy.next
        if len(k_list) == k:
            dumpy.next = self.reverseKGroup(temp, k)  # 递归翻转下一次的k个节点，然后拼接
        return result.next
```

