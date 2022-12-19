
```python []
class Solution:
    def splitListToParts(self, root: ListNode, k: int) -> List[ListNode]:
        ans, nodes = [], []
        while root:
            nodes.append(root)
            root = root.next
        (p, q), j, n = divmod(len(nodes), k), 0, len(nodes)
        for i in range(k):
            if j < n:
                ans.append(nodes[j])
                j += p + (i < q)
                nodes[j - 1].next = None
            else:
                ans.append(None)
        return ans
```

![image.png](https://pic.leetcode-cn.com/aaba4dc8ef7232aff2b2f4a2ef6bdb9e045c5c5a7d9d75b9b05087c4935d4c77-image.png)
