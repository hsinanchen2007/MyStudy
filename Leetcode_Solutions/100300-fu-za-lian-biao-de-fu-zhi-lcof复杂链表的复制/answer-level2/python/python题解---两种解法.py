### 1.哈希表解法
![image.png](https://pic.leetcode-cn.com/c2bdfd8a954d04a0eb24a2f32b0eac33aa37fe478bd452e236e200ee02ebe9c8-image.png)

- 这个方法分成两步:
- 第一步,我们只构建`next`的部分,不构建`random`的部分,同时我们将原链表与新链表的关系保存在哈希表中
- 第二步,我们构建`random`部分,这次是根据哈希表中存的相对关系创建
- 时间复杂度`O(n)`,空间复杂度`O(n)`

### 代码

```python
"""
# Definition for a Node.
class Node:
    def __init__(self, x, next=None, random=None):
        self.val = int(x)
        self.next = next
        self.random = random
"""
class Solution(object):
    def copyRandomList(self, head):
        """
        :type head: Node
        :rtype: Node
        """
        if not head:
            return None
        dic = {}
        prior = Node(0)
        temp_1 = prior
        temp_2 = head
        while head: #构建next部分
            node = Node(head.val)
            dic[head] = node
            prior.next = node
            prior = node
            head = head.next

        prior.next = None
        temp_1 = temp_1.next
        result = temp_1
        head = temp_2
        while head:#构建random部分
            if not head.random:
                dic[head].random = None 
            else: 
                dic[head].random = dic[head.random]
            head = head.next

        return temp_1

```
### 2.链接法
![image.png](https://pic.leetcode-cn.com/e2a88215ba6b072aef8a1e842bf17a83998618be002e1a60dd2713d4aa270279-image.png)

- 这种思路分为三步:
- 第一步,我们创建新的链表,但是我们这次每创建一个新的节点,就在将这个节点放到原链表节点的后面,例如有原始链表`1->3->4->7`,经过我们创建可以得到链表`1->1'->3->3'->4->4'->7->7'`,其中`1',3'.....`代表我们新创建的节点,这一步只是创建这些节点并加入到原链表中
- 第二步,我们开始处理`random`指针.开始从`1->1'->3->3'->4->4'->7->7'`的头结点开始遍历,因为这个链表的新旧节点我们可以看作是绑定在一起的,例如我们假定`3.radom = 7`,那么我们如何找到`3'.random`,我们知道`3'.random = 7'`,可以通过`3.random.next = 7'`来找到,这样我们就就建立了它们之间的关系
- 第三步,我们需要将第二步完成的链表进行分割,也就是分成原始链表和复制链表,这个操作相对简单,直接跳跃连接就可以
- 时间复杂度`O(n)`,空间复杂度`O(1)`

### 代码
```
"""
# Definition for a Node.
class Node:
    def __init__(self, x, next=None, random=None):
        self.val = int(x)
        self.next = next
        self.random = random
"""
class Solution(object):
    def copyRandomList(self, head):
        """
        :type head: Node
        :rtype: Node
        """
        if not head:
            return None

        original = head
        while head:#合并两个链表
            temp = head.next
            node = Node(head.val)
            head.next = node
            node.next = temp
            head = temp
               
        temp_1 = original
        temp_2 = original.next

        while temp_1:# 处理random连接
            if temp_1.random:
                temp_2.random = temp_1.random.next
            else:
                temp_1.random = None
            temp_1 = temp_2.next
            if temp_2.next:
                temp_2 = temp_1.next
            else:
                break
        
        temp_1 = original
        temp_2 = original.next
        result = temp_2

        while temp_1:#拆分链表
            temp_1.next = temp_2.next
            temp_1 = temp_2.next
            if temp_2.next:
                temp_2.next = temp_1.next
                temp_2 = temp_1.next
            else:
                temp_2.next = None
         
        return result

```

