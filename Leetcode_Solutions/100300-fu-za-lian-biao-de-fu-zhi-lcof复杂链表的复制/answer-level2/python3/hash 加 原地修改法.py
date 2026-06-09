```
1. 先复制简单的链表，搁置random；用hashmap建立旧的节点与新的节点之间的映射关系；遍历赋值新的random链表
2. 就地在原来链表的后方重复复制一份，利用node.next.random = node.random.next的特性赋值random；最后拆分两个链表
# Definition for a Node.
class Node:
    def __init__(self, x: int, next: 'Node' = None, random: 'Node' = None):
        self.val = int(x)
        self.next = next
        self.random = random

class Solution:
    #先遍历复制一遍无random节点的链表
    #建造hashmap，hash[old_node] = new_node hash表起到了连接旧的random与新的节点之间的桥梁关系
    #遍历旧的random链，依次赋值给新的random节点
    def copyRandomList(self, head: 'Node') -> 'Node':
        if not head: return head
        memo = {}
        newh = Node(head.val)
        memo[head] = newh
        ncur = newh
        ocur = head
        while ocur.next:
            ncur.next = Node(ocur.next.val)
            ncur = ncur.next
            ocur = ocur.next
            memo[ocur] = ncur
        
        ncur = newh
        ocur = head
        while ocur:
            if ocur.random is not None:
                ncur.random = memo[ocur.random]
            ocur = ocur.next
            ncur = ncur.next
        return newh
    
    def inplaceCopyRandom(self, head):
        #首先将链表重复复制一份， 1->1->2->2->3->3->None
        if not head: return head

        #copy list
        cur = head
        while cur:
            new_node = Node(cur.val)
            new_node.next = cur.next
            cur.next = new_node
            cur = new_node.next
        
        #copy random link
        cur = head
        while cur:
            if cur.random: #random may be None
                cur.next.random = cur.random.next
            cur = cur.next.next
        
        #seperate two list
        cur = head
        new_head = head.next
        ncur = new_head
        while cur.next.next:  #注意这里的判断条件 不是cur 也不是cur.next
            # print(cur.val)
            cur.next = cur.next.next
            ncur.next = ncur.next.next

            cur = cur.next
            ncur = ncur.next
        
        return new_head

if __name__ == "__main__":
    n1 = Node(1,None,None)
    n2 = Node(2,None,n1)
    n3 = Node(3,None,None)
    n1.next = n2
    n2.next = n3
    n1.random = n3
    print(n1.next.val, n1.random.val)
    newn = Solution().copyRandomList(n1)
    print(newn.next.val, newn.random.val)
    new_head = Solution().inplaceCopyRandom(n1)
    print(new_head.next.val, new_head.random.val)
```
