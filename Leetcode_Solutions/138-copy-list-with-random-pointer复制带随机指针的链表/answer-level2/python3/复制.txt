### 解题思路
添加复制的链表，进行重新赋值

### 代码

```java
/*
// Definition for a Node.
class Node {
    int val;
    Node next;
    Node random;

    public Node(int val) {
        this.val = val;
        this.next = null;
        this.random = null;
    }
}
*/

class Solution {
    public Node copyRandomList(Node head) {
        if(head == null) return null;
        Node p = head;
        while(p != null) {//复制，加在相同的后面
            Node clo = new Node(p.val);
            clo.next = p.next;
            p.next = clo;

            p = clo.next;
        }

        p = head;
        while(p != null) {//修改random指针
            p.next.random = (p.random != null) ? p.random.next : null;

            p = p.next.next;
        }
        Node old = head;
        Node news = head.next;
        Node res = news;//保留复制的头结点
        while(old != null) {
            old.next = old.next.next;
            news.next = (news.next != null) ? news.next.next : null;//更新next指针
            old = old.next;
            news = news.next;
        }
        return res;
    } 
}
```

```
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
        p = head
        while p:#复制一遍，加在原节点的后面
            clone = Node(p.val)        
            clone.next = p.next
            p.next = clone

            p = clone.next

        p = head
        while p:#将新节点指针修改
            tmp = p.next.next
            p.next.next = tmp.next if tmp else None
            p.next.random = p.random.next if p.random else None#注意random指向的是原节点random的下一个

            p = tmp
        return head.next
```
