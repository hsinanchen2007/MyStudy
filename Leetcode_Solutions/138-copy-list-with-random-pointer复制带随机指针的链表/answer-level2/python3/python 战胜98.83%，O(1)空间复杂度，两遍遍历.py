# 思路
遍历链表两次：
第一遍：把每个新生成的结点放在对应的旧结点后面， 形如: 1->1'->2->2'->3->3'->4->4'->null。
第二遍：修改每个新结点的 next 指针和 random 指针。

# 代码：
```
class Solution:
    def copyRandomList(self, head: 'Node') -> 'Node':
        if not head:
            return None

        # 第一遍遍历，把每个新生成的结点放在对应的旧结点后面
        p = head
        while p:
            new_node = Node(p.val)
            new_node.next = p.next
            p.next = new_node

            p = new_node.next       # 下一个旧结点
        
        # 第二遍修改每个新结点的 next 和 random 
        p = head
        while p:
            next_origin = p.next.next        # 下一个旧结点备份一下
            p.next.next = next_origin.next if next_origin else None   # 修改新结点的 next
            p.next.random = p.random.next if p.random else None    # 修改新结点的 random

            p = next_origin         # 下一个旧结点
        
        return head.next
```
