### 解题思路
1. 先看懂题目，看不懂的话可以print()各种调试，慢慢摸索就懂了。
2. 计算结果可以先存在列表里，等后面全部结果算出来再写链条，也可以得到结果的同时写入链条。
3. 用列表写链条时，可以将列表反转（list.reverse()），这是我正向写链条没想明白时想到的办法。
4. 看了范例后，学到个很有用的技巧：先初始化第一个节点，最后结果返回的是初始化节点的后一个节点。
5. 有一些if语句可以合并的，多比较if和else的执行语句，想想。

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        # result = []
        first_node = ListNode(0)
        follow_node = first_node
        carry_bit = 0

        while l1 or l2:
            
            add1 = l1.val if l1 else 0
            add2 = l2.val if l2 else 0

            sum_bit = add1 + add2 + carry_bit

            # if sum_bit >= 10:
            #     carry_bit = 1
            #     sum_bit = sum_bit % 10
            # else:
            #     carry_bit = 0
            carry_bit = sum_bit // 10
            sum_bit = sum_bit % 10
            
            # result.append(sum_bit)    
            follow_node.next = ListNode(sum_bit)
            follow_node = follow_node.next

            l1 = l1.next if l1 else l1
            l2 = l2.next if l2 else l2
        
        if carry_bit == 1:
            follow_node.next = ListNode(carry_bit)
            follow_node = follow_node.next
        
        # result.reverse()
        # last_node = None
        
        # for node in result:
        #     if last_node is None:
        #         last_node = ListNode(node)
        #     else:
        #         curr_node = ListNode(node)
        #         curr_node.next = last_node
        #         last_node = curr_node

        
        return first_node.next
```