## 思路

官方题解给了两种方法：

- 使用队列的BFS。 这种做法是不符合题目的$O(N)$的空间复杂度的要求的。
- 递归。 这种解法不是很好理解，并且递归性能没有迭代好。虽然题目说明了递归的栈开销不算额外复杂度，但是这不影响其比迭代慢的事实，并且这种递归版本也不是很好写。

这里介绍一种迭代，不仅性能更好，而且容易理解。 

- 我们使用一个指针pre，pre.next指向下一层的最左节点
- 我们使用一个指针cur。cur在每一层中从左向右，给每个节点增加next指针

可能语言你看不太明白，大家结合下面的代码理解。

## 代码


```python
"""
# Definition for a Node.
class Node:
    def __init__(self, val: int = 0, left: 'Node' = None, right: 'Node' = None, next: 'Node' = None):
        self.val = val
        self.left = left
        self.right = right
        self.next = next
"""
class Solution:
    def connect(self, root: 'Node') -> 'Node':
        # pre.next 指向下一层最左节点
        # cur 每一层从做往右增加next指针
        ans = root
        pre = Node(0)
        cur = pre
        while root:
            if root.left:
                cur.next = root.left
                cur = cur.next
            if root.right:
                cur.next = root.right
                cur = cur.next
            root = root.next
            # next level
            if not root:
                cur = pre
                root = pre.next
                # 设置为None，否则会无限循环
                pre.next = None
        return ans
        
```



**复杂度分析**
- 时间复杂度：$O(N)$
- 空间复杂度：$O(1)$

欢迎关注我的公众号《脑洞前端》获取更多更新鲜的LeetCode题解

![](https://pic.leetcode-cn.com/89ef69abbf02a2957838499a96ce3fbb26830aae52e3ab90392e328c2670cddc-file_1581478989502)