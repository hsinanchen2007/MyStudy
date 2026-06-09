![image.png](https://pic.leetcode-cn.com/a1c97aa6677cbadca9ab84750331188e13142de37cfec8c0cdbff2e4fb1c3d21-image.png)

用数组来实现逆序，只修改链表值，不用修改next，不一定会慢多少。

```python []
class Solution:
    def reverseBetween(self, head: ListNode, m: int, n: int) -> ListNode:
        ans = ListNode(0)
        ans.next = head
        pre = ans
        for _ in range(m - 1):      #扫描到起点
            pre = pre.next
        h = pre.next
        a = []
        for _ in range(n - m + 1):  #逆向录入数组
            a = [h.val] + a
            h = h.next
        h = pre.next
        for i in a:                 #按顺序修改链表值
            h.val = i
            h = h.next
        return ans.next
```
