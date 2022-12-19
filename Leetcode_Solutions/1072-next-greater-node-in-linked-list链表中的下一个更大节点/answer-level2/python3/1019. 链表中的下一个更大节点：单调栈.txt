### 解题思路
把链表的值存成数组，逆遍历，保持除栈底以外的值呈单调递减状态，即如果栈顶的值小于当前值则弹出栈顶，坐标对应的下一个更大节点值为栈顶的值，空间上可以直接在生成链表值数组上修改。时间复杂度和空间复杂度都是$O(N)$

### 代码

```python []
class Solution:
    def nextLargerNodes(self, head: ListNode) -> List[int]:
        vals, stack = [], [0]
        while head:
            vals.append(head.val)
            head = head.next
        for i in range(len(vals) - 1, -1, -1):
            while stack[-1] and vals[i] >= stack[-1]:
                stack.pop()
            stack.append(vals[i])
            vals[i] = stack[-2]
        return vals
```
![image.png](https://pic.leetcode-cn.com/2eda5aaafbab55f08594430f54cee6d434cad1f85cf8d1ba37d68c131e5b5190-image.png)

