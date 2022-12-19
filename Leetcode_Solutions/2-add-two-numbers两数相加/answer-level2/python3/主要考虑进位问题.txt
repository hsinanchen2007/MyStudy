### 解题思路
两数相加
1，长度相同
2，长度不同
3，进位问题
我们计算每一位的和sum = l1.val + l2.val
那么当前位的数字为:val = sum % 10
当前位的进位:sum//10
下一位的数字为:val = (sum//10 + sum_next)%10

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        result = ListNode(0)
        p_result = result
        sum = 0
        while True:
            if l1 and l2:  #长度相同
                sum = sum // 10 + l1.val + l2.val
                p_result.val = sum % 10
                l1 = l1.next
                l2 = l2.next
            elif l1:  #l1长
                sum = sum // 10 + l1.val
                p_result.val = sum % 10
                l1 = l1.next
            elif l2:  #l2长
                sum = sum // 10 + l2.val
                p_result.val = sum % 10
                l2 = l2.next
            else:  #l1和l2都到末尾并且有进位，最后补充最高位
                sum = sum // 10
                p_result.val = sum % 10
            if l1 or l2 or sum // 10:  #如果l1和l2还有位数或者有进位，就申请存储
                p_result.next = ListNode(0)
                p_result = p_result.next
            else:  #累加完毕，结束
                break
        return result

```