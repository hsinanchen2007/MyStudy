### 解题思路
第一步：遍历链表，生成新节点接在原节点后面
第二步：遍历链表，修改新链表random指针
第三步：分离原链表和新链表
时间复杂度O(n),空间复杂度O(1)
![image.png](https://pic.leetcode-cn.com/8038180028a86a7e692b9e11f26d455d50772cf61cc173bd227470e1cf5d5765-image.png)

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
        if not head:
            return head
        p0=head
        while p0: # 遍历链表，生成新节点接在原节点后面
            newNode=Node(p0.val,None,None)
            nextNode=p0.next
            p0.next=newNode
            newNode.next=nextNode
            p0=nextNode
        p1=head
        while p1: # 遍历链表，修改新链表random指针
            if p1.random:
                p1.next.random=p1.random.next
            p1=p1.next.next
        p2=head # 创建用于还原原链表的指针
        p3=head.next # 创建提取新链表的指针
        res=p3 # 保存新链表头节点
        while p3.next:
            p2.next=p2.next.next
            p3.next=p3.next.next
            p2=p2.next
            p3=p3.next
        return res




            
        

```