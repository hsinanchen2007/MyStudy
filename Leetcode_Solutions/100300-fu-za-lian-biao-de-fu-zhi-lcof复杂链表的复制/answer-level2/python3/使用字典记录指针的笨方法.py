### 解题思路
先进行一次循环，将val复制，并利用字典记录当前指针与参数count的关系；第二次循环复制每个节点random的指向。
![image.png](https://pic.leetcode-cn.com/2d36a3f99c2d54160e489fe6272c551df74354efa096506712886c510852ce18-image.png)


### 代码

```python3
"""
# Definition for a Node.
class Node:
    def __init__(self, x: int, next: 'Node' = None, random: 'Node' = None):
        self.val = int(x)
        self.next = next
        self.random = random
"""
class Solution:
    def copyRandomList(self, head: 'Node') -> 'Node':
        ans = Node(-1)
        ans_p, p = ans, head
        ans_dict,  ori_dict = {}, {}
        count = 0
        while p:
            ans_p.next = Node(p.val)
            ans_dict[count], ori_dict[p] = ans_p.next, count
            p, ans_p = p.next, ans_p.next
            count += 1
        count = 0
        ans_p, p = ans.next, head
        while p:
            if p.random != None:  ans_p.random = ans_dict[ori_dict[p.random]]
            else: ans_p.random = None
            count += 1
            ans_p, p = ans_p.next, p.next
        return ans.next
```