此题和《***》的第26题一样。 我们使用一个seen 开存储访问过的元素，减少时间复杂度。 这样时间复杂度可以从$O(N^2)$ 降低到 $O(N)$， 相应地我们牺牲了N的空间。


```python
class Solution:
    seen = {}

    def copyRandomList(self, head: 'Node') -> 'Node':
        if not head:
            return None
        if head in self.seen:
            return self.seen[head]
        copy = Node(head.val)
        self.seen[head] = copy
        copy.next = self.copyRandomList(head.next)
        copy.random = self.copyRandomList(head.random)

        return copy
```

**复杂度分析**

- 时间复杂度：每一个节点我们只会访问一次， 故时间复杂度为 $O(N)$。
- 空间复杂度：我我们使用了seen来存储所有处理过的节点，因此seen的大小就是节点的个数，故空间复杂度为$O(N)$。


欢迎关注我的公众号《脑洞前端》获取更多更新鲜的LeetCode题解

![](https://pic.leetcode-cn.com/960f0fcedb710cca012ce919c8cd275be29ce72312da2da095b0eb13b99ec60f.jpg)

