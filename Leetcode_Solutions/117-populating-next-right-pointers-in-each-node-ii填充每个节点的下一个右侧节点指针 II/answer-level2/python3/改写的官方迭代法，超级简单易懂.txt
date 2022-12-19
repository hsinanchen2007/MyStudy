### 解题思路
纵向是二叉树，横向是链表，两层嵌套循环，主循环处理各层，**子循环处理每层节点的各子节点**。
定义3个变量，分别标记：下一层头节点head，下一层已遍历到的前置节点pre，以及当前层处理的游标cur：
- 总初始化：下一层要处理的头节点`head=root`
- 各层初始化：当前层处理游标节点cur用head更新赋值，而后`pre=head=None`，表示下一层尚未找到前置和头节点
- 对当前层游标节点cur进行处理，对左右子节点分别判断：
  - 如果下一层尚未找到前置节点，则意味着该左/右子节点就是下一层的头节点，于是更新pre=head=该子节点
  - 如果pre已赋值，则直接更新pre的next到当前的左/右子节点，然后pre更新到其next值
  - cur游标更新到下一个值
- 根据更新后的head，处理下一层

### 执行结果
![image.png](https://pic.leetcode-cn.com/d931bcd3c397499da375b39bf5dcb3a1f899a7c40a334fbd2bfd71b2e2d4fda5-image.png)

### 代码

```python3
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
        head = root
        while head:#当前层的头节点
            cur = head #当前层处理节点
            pre = head = None#初始化下一层头节点和前置节点
            while cur:
                if cur.left:
                    if not pre:#若尚未找到下一层前置节点，则同步更新下一层头节点和前置节点
                        pre = head =cur.left
                    else:#已找到下一层前置节点，则将前置节点指向当前子节点，并前移pre
                        pre.next = cur.left
                        pre = pre.next
                if cur.right:
                    if not pre:
                        pre = head = cur.right
                    else:
                        pre.next = cur.right
                        pre = pre.next
                cur = cur.next
        return root
```
最后，低调推荐个人公众号：[小数志](https://pic.leetcode-cn.com/962ebbb357f15acd99bfcc5dc74188fc9f2a3492e73bca90b673428d5c1c7559-image.png)


