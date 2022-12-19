### 解题思路
carry 是进位
starNode 移动的指针(用来存加后的值的节点)
resNode 记录初始位置(通过它返回最终的值)

1. l1 和 l2 只要有值你不能不加。有可能l1先玩完，有可能l2先玩完。I dont care
2. 那如果加到最后刚好没值啦 还得进位 依然还得在加一位
3. 你把算出的值接到starNode后面，更新一下starNode。(因为resNode保存着starNode的地址，不用但心怎么输出)
4. 感觉 如果没想到把初始位置记下来。你怎么写 都不爽 
5. 最后就是注意l1和l2为空，继续取next的bug啦(算法都搞出来了 bug这真糟心)



### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        '''
            carry 是进位
            starNode 跟着移动的指针
            resNode 记录初始位置(通过它返回最终的值)
        '''
        carry = 0 
        starNode = ListNode(0)
        resNode = starNode
        while l1 or l2 or carry:
            l1_val = l1.val if l1 else 0
            l2_val = l2.val if l2 else 0
            if (l1_val + l2_val + carry) >= 10:
                node = ListNode(l1_val + l2_val + carry - 10)
                starNode.next = node
                starNode = node
                carry = 1        
            else:
                node = ListNode(l1_val + l2_val + carry)
                starNode.next = node
                starNode = node
                carry = 0
            # 这里确定 只有carry 有值 不报错
            if l1:
                l1 = l1.next
            if l2:
                l2 = l2.next
        return resNode.next
```