## 解题思路
**这里的复制指的是深复制！！！**
复杂链表的节点里除了有next指针，还有其他东西例如：random指针。
如果是next和random分开复制，那么对于复制了next的某个节点：如果想要再复制random的内容，首先需要从原链表中找到对应的random节点，然后在新链表中定位了新的random节点，然后连接起来。时间复杂度是O(N*2N)

重点就是找到原random和新random之间的关系，这样就可以根据原random找到新的random然后和新节点连接起来。
### 法一：
把新旧节点的关系用哈希表存起来。每次需要得到新random位置时就用旧random去查找。目标就是遍历旧链表，复制新节点的random。
具体图解如下：
![Screenshot 2020-04-04 at 09.41.21.png](https://pic.leetcode-cn.com/9e95c9b640d1d993de8a770785debfe021eaad6aead20bd90a671ec1bcdf87c1-Screenshot%202020-04-04%20at%2009.41.21.png)


时间复杂度：O(N)
空间复杂度：O(N)

### 法二：新旧交替连接
若节点A的random是B，那么新节点A'的random就是B'，且B'的位置就在B的下一个。这样遍历一边就可以完成。然后把偶数位上的节点取出来，就是新的链表。
具体步骤：
1. 创建新旧交替链表，仅复制next关系
2. 复制random关系
3. 奇偶分开得新链表

时间复杂度：O(N)
空间复杂度：O(1)


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
            return None
        # 1. create new node and link next
        ori = head

        while head:
            node = Node(head.val)
            node.next = head.next
            head.next = node
            head = head.next.next
        
        # print new linklist
        # while ori:
        #     print(ori.val)
        #     ori = ori.next
        
        # 2. link random
        head = ori
        while head:
            new_head = head.next
            if head.random:  
                new_head.random = head.random.next
            else:
                new_head.random = None
            
            head = new_head.next

        # print new linklist with random
        # while ori:
        #     print('ori:',ori,ori.val,ori.random)
        #     print('new:',ori.next,ori.next.val,ori.next.random)
        #     ori = ori.next.next

        # 3. split
        temp = ori.next
        new_ll = temp

        while temp.next:
            temp.next = temp.next.next
            temp = temp.next
            
        # while new_ll:
        #     print(new_ll.val)
        #     new_ll = new_ll.next

        return new_ll






```