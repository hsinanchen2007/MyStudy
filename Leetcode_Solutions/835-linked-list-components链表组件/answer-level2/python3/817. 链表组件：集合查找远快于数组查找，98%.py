### 解题思路
G转集合，然后检查遍历链表即可获得计数。

### 代码

```python []
class Solution:
    def numComponents(self, head: ListNode, G: List[int]) -> int:
        ans, prev = 0, ListNode(None)
        G, prev.next = {*G}, head
        while head:
            if prev.val not in G and head.val in G:
                ans += 1
            head, prev = head.next, head
        return ans
```

![image.png](https://pic.leetcode-cn.com/a14ff6e6dbbd88e8f5be30d9d4d3a4ef2c2132411df31c4cdf4d4c8ffb078e77-image.png)
