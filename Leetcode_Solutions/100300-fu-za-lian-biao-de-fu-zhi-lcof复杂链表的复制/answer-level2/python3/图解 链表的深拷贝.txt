### 题意理解

本题的意思是复制一个链表并返回，这个链表与一般链表不同的是多了一个 `random` 指针。

在这里，复制的意思是指 *深拷贝（Deep Copy）*，类似我们常用的“复制粘贴”，事实上，与此对应的还有 浅拷贝，它们的区别是：

>浅拷贝只复制指向某个对象的指针，而不复制对象本身，新旧对象还是共享同一块内存。但深拷贝会另外创造一个一模一样的对象，新对象跟原对象不共享内存，修改新对象不会改到原对象。

![1.png](https://pic.leetcode-cn.com/51803415d5440d4589ae6b2e1a157bc6df4aa2f3ac62195cedb5f5ee97055db1-1.png)


### 方法一：一行 python（不推荐）
明白了以上原理，对于 python 可直接调用相关函数：


```python
class Solution:
    def copyRandomList(self, head: 'Node') -> 'Node':
        return copy.deepcopy(head)
```
### 方法二：DFS & BFS
图的基本单元是 **顶点**，顶点之间的关联关系称为 **边**，我们可以将此链表看成一个图：

![2.png](https://pic.leetcode-cn.com/166afb3c11f82e09fdf3dd5e01731f12d73ae21c328b5981957a86b109e52c14-2.png)

由于图的遍历方式有深度优先搜索和广度优先搜索，同样地，对于此链表也可以使用深度优先搜索和广度优先搜索两种方法进行遍历。

#### 算法：深度优先搜索
1. 从头结点 `head` 开始拷贝；
2. 由于一个结点可能被多个指针指到，因此如果该结点已被拷贝，则不需要重复拷贝；
3. 如果还没拷贝该结点，则创建一个新的结点进行拷贝，并将拷贝过的结点保存在哈希表中；
4. 使用递归拷贝所有的 `next` 结点，再递归拷贝所有的 `random` 结点。
#### 代码

```python []
class Solution:
    def copyRandomList(self, head: 'Node') -> 'Node':
        def dfs(head):
            if not head: return None
            if head in visited:
                return visited[head]
            # 创建新结点
            copy = Node(head.val, None, None)
            visited[head] = copy
            copy.next = dfs(head.next)
            copy.random = dfs(head.random)
            return copy
        visited = {}
        return dfs(head)
```
#### 复杂度分析
- 时间复杂度：$O(N)$。
- 空间复杂度：$O(N)$。

#### 算法：广度优先搜索
1. 创建哈希表保存已拷贝结点，格式 `{原结点：拷贝结点}`
2. 创建队列，并将头结点入队；
3. 当队列不为空时，弹出一个结点，如果该结点的 `next` 结点未被拷贝过，则拷贝 `next` 结点并加入队列；同理，如果该结点的 `random` 结点未被拷贝过，则拷贝 `random` 结点并加入队列；
```python []
class Solution:
    def copyRandomList(self, head: 'Node') -> 'Node':
        visited = {}
    
        def bfs(head):
            if not head: return head
            clone = Node(head.val, None, None) # 创建新结点
            queue = collections.deque()
            queue.append(head)
            visited[head] = clone
            while queue:
                tmp = queue.pop()
                if tmp.next and tmp.next not in visited:
                    visited[tmp.next] = Node(tmp.next.val, [], [])
                    queue.append(tmp.next)  
                if tmp.random and tmp.random not in visited:
                    visited[tmp.random] = Node(tmp.random.val, [], [])
                    queue.append(tmp.random)
                visited[tmp].next = visited.get(tmp.next)
                visited[tmp].random = visited.get(tmp.random)
            return clone
        return bfs(head)
```
#### 复杂度分析
- 时间复杂度：$O(N)$。
- 空间复杂度：$O(N)$。
### 方法三：迭代
该方法的思路比较直接，对于一个结点，分别拷贝**此结点、`next` 指针指向的结点、`random` 指针指向的结点，** 然后进行下一个结点...如果遇到已经出现的结点，那么我们不用拷贝该结点，只需将 `next` 或 `random` 指针指向该结点即可。

<![幻灯片4.JPG](https://pic.leetcode-cn.com/8fc9d1d30102d5855e2fcc14ffd39df83571cf6116ab798bef07e3399ba4b7ae-%E5%B9%BB%E7%81%AF%E7%89%874.JPG),![幻灯片5.JPG](https://pic.leetcode-cn.com/a3eb0bcde12712ac99167600d3e11b85460a46bbcf6712aebe851b1faceeeaff-%E5%B9%BB%E7%81%AF%E7%89%875.JPG),![幻灯片6.JPG](https://pic.leetcode-cn.com/381ca37246f5d5f8070674f23ffb10c5ed84126e46cb3c81f1a353bc89c8b25f-%E5%B9%BB%E7%81%AF%E7%89%876.JPG),![幻灯片7.JPG](https://pic.leetcode-cn.com/435853a49ef682e000067173375924a17706dafe34df67c40626ad7694fb7ffe-%E5%B9%BB%E7%81%AF%E7%89%877.JPG),![幻灯片8.JPG](https://pic.leetcode-cn.com/cdb8c8008b891f5b282ac21d95f13b0dbb7b0bcd7b8ca65d42f82983a0fa462a-%E5%B9%BB%E7%81%AF%E7%89%878.JPG),![幻灯片9.JPG](https://pic.leetcode-cn.com/044b60f64209bedb0f900b95b8e2bf17914e627d2eb70402237ea68a48e4c4e9-%E5%B9%BB%E7%81%AF%E7%89%879.JPG),![幻灯片10.JPG](https://pic.leetcode-cn.com/a14b949d648a08ea7a2bf493c65a1f1a82ea92fd6c27e9e8e11d4ae64bc52f0a-%E5%B9%BB%E7%81%AF%E7%89%8710.JPG)>



#### 代码
```python []
class Solution:
    def copyRandomList(self, head: 'Node') -> 'Node':
        visited = {}
        def getClonedNode(node):
            if node:
                if node in visited:
                    return visited[node]
                else:
                    visited[node] = Node(node.val,None,None)
                    return visited[node]
            return None
        
        if not head: return head
        old_node = head
        new_node = Node(old_node.val,None,None)
        visited[old_node] = new_node

        while old_node:
            new_node.random = getClonedNode(old_node.random)
            new_node.next = getClonedNode(old_node.next)
            
            old_node = old_node.next
            new_node = new_node.next
        return visited[head]
```
#### 复杂度分析
- 时间复杂度：$O(N)$。
- 空间复杂度：$O(N)$。
### 方法四：优化的迭代
我们也可以不使用哈希表的额外空间来保存已经拷贝过的结点，而是将链表进行拓展，在每个链表结点的旁边拷贝，比如 `A->B->C` 变成 `A->A'->B->B'->C->C'`，然后将拷贝的结点分离出来变成 `A->B->C`和`A'->B'->C'`，最后返回 `A'->B'->C'`。

![35_1.gif](https://pic.leetcode-cn.com/c53b7c728bcf064803cefc137766e5dbfa0247059ed8adf76a86d7e3f2de7546-35_1.gif)



#### 代码
```python []
class Solution:
    def copyRandomList(self, head: 'Node') -> 'Node':
        if not head: return head
        cur = head
        while cur:
            new_node = Node(cur.val,None,None)   # 克隆新结点
            new_node.next = cur.next
            cur.next = new_node   # 克隆新结点在cur 后面
            cur = new_node.next   # 移动到下一个要克隆的点
        cur = head

        while cur:  # 链接random
            cur.next.random = cur.random.next if cur.random else None
            cur = cur.next.next

        cur_old_list = head # 将两个链表分开
        cur_new_list = head.next
        new_head = head.next
        while cur_old_list:
            cur_old_list.next = cur_old_list.next.next
            cur_new_list.next = cur_new_list.next.next if cur_new_list.next else None
            cur_old_list = cur_old_list.next
            cur_new_list = cur_new_list.next
        return new_head
```
#### 复杂度分析
- 时间复杂度：$O(N)$。
- 空间复杂度：$O(1)$。
### 总结
在对链表进行操作的时候，经常要记得把一个结点的指针域用另一个指针保存起来，这样返回的时候不容易出错。


欢迎提供 c++ 代码~
如有问题，欢迎讨论~