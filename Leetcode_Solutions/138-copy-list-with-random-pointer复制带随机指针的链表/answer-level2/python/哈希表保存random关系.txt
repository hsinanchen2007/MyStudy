```
"""
# Definition for a Node.
class Node(object):
    def __init__(self, val, next, random):
        self.val = val
        self.next = next
        self.random = random
"""
class Solution(object):
    def copyRandomList(self, head):
        """
        :type head: Node
        :rtype: Node
        :思路： 创建hash表，遍历链表，复制val和next，并将random关系用hash表保存下来
                再一次遍历链表，给random赋值
        """
        
        hash_table = {}
        cur_node = head
        dummy_node = Node(0, None, None)
        copy_node = dummy_node
        
        # 建立映射关系
        while cur_node:
            new_node = Node(cur_node.val, None, None)
            hash_table[cur_node] = new_node
            copy_node.next = new_node
            copy_node = new_node
            cur_node = cur_node.next
        
        # 赋值random
        cur_node = head
        copy_node = dummy_node.next
        while cur_node:
            if cur_node.random:
                copy_node.random = hash_table[cur_node.random]             
            cur_node = cur_node.next
            copy_node = copy_node.next
        
        return dummy_node.next
```
