### 解题思路

* 计算 两个链表长度
* 递归 计算每一位数字 分情况处理 链表 i，j 长度 num_i,num_j
  1. 高位（长链表 多出的位数 即 num_i > num_j的部分）= i.val + 下一位进位
  2. 等长部分 = i.val + j.val + 下一位进位
  3. 计算 进位 ， 更新 i.val (以长链表作最终结果)
* 最后注意 头节点的进位，判断需不需要加一个头节点

### 代码

```python3
class Solution:
    def addTwoNumbers(self, l1, l2):
        def add(num1, num2, i, j):
            if not i or not j:
                return 0
            if num1 > num2:
                temp = i.val + add(num1 - 1, num2, i.next, j)
            else:
                temp = i.val + j.val + add(num1, num2, i.next, j.next)
            i.val = temp % 10
            return temp // 10

        num1 = num2 = 0
        cur = l2
        while cur:
            num2 += 1
            cur = cur.next
        cur = l1
        while cur:
            num1 += 1
            cur = cur.next
        
        if num2 > num1:
            l1, l2 = l2, l1
            num2, num1 = num1, num2

        if add(num1,num2,l1, l2):
            l2 = ListNode(1)
            l2.next = l1
            l1 = l2
        return l1

```