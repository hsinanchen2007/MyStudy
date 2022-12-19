![image.png](https://pic.leetcode-cn.com/81dbe20ce1637d0a56fb196785459fe92c3748d89bff28cc5fd48e3bbf67de34-image.png)

2分钟内应该能够完成
```python []
class Solution:
    def sortedListToBST(self, head: ListNode) -> TreeNode:
        a = []
        while head:
            a += [head.val]
            head = head.next
        def f(i, j):
            if i <= j:
                k = (i + j) // 2
                r = TreeNode(a[k])
                r.left = f(i, k - 1)
                r.right = f(k + 1, j)
                return r
        return f(0, len(a) - 1)
```
