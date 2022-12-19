### 核心思路
这道题得想到每层是个链表。下一层的链表元素一定在上一层链表的左右子节点内。所以用当前层的节点链表，可以求得其子节点层的链表，这样来解题就容易多了：
1. 顶层是root,遍历root的子节点层，记下其开始节点start,停止遍历；
2. 接着步骤1的停止遍历位置，继续遍历此层的剩余子节点，用next连接起来形成链表。
3. 然后用start当做root子节点层，进行刚才操作：根据start链表来访问其子节点层，先找子节点层开始位置记为start，继续遍历此层余下节点，用next连接。
### 奇技淫巧
这里提到一个链表的trick：设置空节点dummy，让它next指向上面的start，就可以大量简化代码。
```python
#简化前：
class Solution:
    def connect(self, root: 'Node') -> 'Node':
        
        start=root
        while start:

            dummy = Node(0,None,None,start)
            start = None
            ## 记住下一层的start
            while dummy.next:
                dummy = dummy.next
                dummy_children = [x for x in [dummy.right,dummy.left] if x] ##最多2个元素的列表
                if start==None and dummy_children:
                    start = i = dummy_children.pop()
                    break
            ## 设定下一层的指针，指针的next指向同一层的下一个节点
            if dummy_children:
                i.next = dummy_children.pop()
                i = i.next
            ## 设定下一层的指针，指针的next指向同一层的下一个节点
            while dummy.next:
                dummy = dummy.next
                dummy_children = [x for x in [dummy.right,dummy.left] if x]
                while dummy_children:
                    i.next = dummy_children.pop()
                    i = i.next            
        return root
```
```python
#简化后
class Solution:
    def connect(self, root: 'Node') -> 'Node':
        head = root
        while head:
            dummy = Node()
            nxt, cur = dummy, head ## 用已知的cur层链表，遍历其子节点，求nxt层链表 
            while cur:
                if cur.left: 
                    nxt.next = cur.left
                    nxt = nxt.next
                if cur.right: 
                    nxt.next = cur.right
                    nxt = nxt.next
                cur = cur.next
            head = dummy.next ## dummy.next是子节点层的开始，由此跳到子节点层
        return root
```

