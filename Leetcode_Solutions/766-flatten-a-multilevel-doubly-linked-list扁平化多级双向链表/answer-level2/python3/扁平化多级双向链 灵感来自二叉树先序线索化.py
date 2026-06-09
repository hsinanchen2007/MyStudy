代码量全场最少，空间效率最高，递归。

```
class Solution:

    def flatten(self, head: 'Node') -> 'Node':
        
        def fun(node):
            
            global pre             # 一定要用global定义pre，保证在底层递归返回上层时保留底层
                                   # 最后一个节点，使其成为上层递归位置结束后第一个节点的前驱
            if node:         
                
                pre=node
                
                if node.child:
                    fun(node.child)
                    next_node=node.next
                    node.next=node.child
                    node.child.prev=node
                    node.child=None
                    if next_node:
                        pre.next=next_node
                        next_node.prev=pre

                if node.next:
                    fun(node.next)
        
        fun(head)
        return head
```
