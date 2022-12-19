### 解题思路
- 1，3 个列表，分别存储 `head`, `random`, `copy`
- 2，遍历 `head`，存储 `head` 和 `random` ，同时获取 `head.val` 并生成 `copy`
- 3，遍历 `copy`，存储所有 `copy` 节点
- 4，计算 `random` 在 `head` 中的 `index`，这时对应的 `copy.random` 指向的也是这个 `copy[index]`


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
        if not head.next:
            if head.random is not None:
                n = Node(head.val, None)
                n.random = n
                return n
            else:
                return Node(head.val, None)

        head_list = []  # 存储 head 节点
        random_list = []  # 存储对应 head 节点对应的 random 节点
        copy_list = []  # 存储 copy 节点

        rev = copy_node_1 = copy_node = Node(0, None)

        while head:
            head_list.append(head)
            random_list.append(head.random)
            copy_node.val = head.val
            if head.next:  # 这里注意，当 head.next 为 None 时，copy 的 next 也是 None
                copy_node.next = Node(0, None)
                copy_node = copy_node.next
                head = head.next
            else:
                copy_node.next = None
                copy_node = copy_node.next
                break
        
        while copy_node_1:
            copy_list.append(copy_node_1)  # 遍历 copy_node,存储所有节点
            copy_node_1 = copy_node_1.next
            
        copy_list.append(copy_node)  # 这里加入最后节点 None
        
        ln = len(copy_list)
        
        for i in range(ln-1):
            if random_list[i] == None:  # random 是 None，指向 最后一个 copy_node
                copy_list[i].random=copy_list[-1]
            else:
                j=head_list.index(random_list[i])  # 查找 random 在 head_list 里的 index
                copy_list[i].random = copy_list[j]  # 将 copy_node.random = copy_list 中对应位置 index 的值
        return rev
```