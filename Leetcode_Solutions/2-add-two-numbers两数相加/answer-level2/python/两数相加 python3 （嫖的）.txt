用一个flag记录进位状况，然后考虑最高位，及位数不一致等情况即可
代码嫖的作者：jutraman
链接：https://leetcode-cn.com/problems/add-two-numbers/solution/
瞎说，程序猿的事能叫嫖吗，借代码，借！
主要是用于补全注释后方便以后自己查找
嘿嘿嘿
```python []
class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        newNode = ListNode(0)
        ansNode = newNode
        flag = 0
        while l1.val >= 0 or l2.val >= 0: # 数值还存在
            x = l1.val if l1.val >= 0 else 0 #同上，数值不为空
            y = l2.val if l2.val >= 0 else 0
            sum = x + y + flag
            flag = sum // 10 # flag 用于记录进位
            newNode.val = sum%10 #实际该位数字为相加结果对10取模
            l1 = l1.next if l1.next else ListNode(-1) #如果不存在则该表结束
            l2 = l2.next if l2.next else ListNode(-1) #同上
            if l1.val >= 0 or l2.val >= 0 or flag: #如果表结束，flag还有进一位还要补，没有就结束了
                newNode.next = ListNode(0)
                newNode = newNode.next
        if flag == 1:  #最后数值处理
            newNode.val = 1
        return ansNode # 返回结果
```
