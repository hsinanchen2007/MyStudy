在[python3 更简洁易懂高效的代码 + 更简单粗暴的解法](https://leetcode-cn.com/problems/merge-two-sorted-lists/solution/python3-geng-jian-ji-yi-dong-gao-xiao-de-dai-ma-ge/)中，我们总结了链表类题目的2种解题工具：
**指针和列表**

### 方法1：列表模拟DFS
看示例的输入输出，明显是DFS，二叉树的中序遍历。当然是用列表表示栈来模拟DFS过程了  
```
class Solution:
    def flatten(self, head: 'Node') -> 'Node':
        p = rst = Node(None,None,None,None) ## 初始化结果链表及其指针
        visited = head and [head] ## 初始化栈
        while visited:
            vertex = visited.pop()
            if vertex.next: visited.append(vertex.next)
            if vertex.child: visited.append(vertex.child)
            p.next= vertex ## pop出来的节点就是所需节点
            p, p.prev, p.child = p.next, p, None ## 设定节点属性        
        if rst.next: rst.next.prev = None ## rst.next的prev属性要设为None
        return rst.next
```
思路简单，执行效果如下：
执行用时 :1128 ms, 在所有 python3 提交中击败了77.59%的用户  
内存消耗 :335.8 MB, 在所有 python3 提交中击败了5.88%的用户  

不是特别好，那试试全指针无列表的方法：

### 方法2：双指针
也可以勉强理解为快慢双指针，快指针用来遇到child节点时遍历child节点，慢指针用来遍历主线节点：

```
class Solution:
    def flatten(self, head: 'Node') -> 'Node':
        p=head
        while p:
            if p.child: ## 若存在孩子节点:
                child, child.prev = p.child, p ## 初始化child指针                               
                while child.next: ## 遍历child分支
                    child = child.next
                child.next = p.next ## 遍历完成，设定分支的next为主线节点的next
                if p.next: p.next.prev = child ## 设定主线节点的next的prev属性
                p.next, p.child = p.child, None ## 设定主线的next为主线的child
            p = p.next
        return head
```
这样的双指针思路有点绕，效果差不多吧：
执行用时 :1104 ms, 在所有 python3 提交中击败了81.98%的用户
内存消耗 :335.7 MB, 在所有 python3 提交中击败了5.88%的用户 

但有没有更好的办法？既然用了栈，能否不用指针，栈顶pop哪个我就修改哪个，应该更快！

### 方法3：纯用栈模拟DFS不用指针
```
class Solution:
    def flatten(self, head: 'Node') -> 'Node':
        visited = head and [head]
        while visited:
            vertex = visited.pop()
            if vertex.next:
                visited.append(vertex.next)
            elif visited: ## 当pop出的元素为None，要考虑到可能是分支的尾节点，需append主线节点
                vertex.next, vertex.next.prev = visited[-1], vertex
            if vertex.child:
                visited.append(vertex.child)
                vertex.next, vertex.next.prev = vertex.child, vertex
                vertex.child = None
        return head
```
执行效果如下：
执行用时 :1060  ms, 在所有 python3 提交中击败了91.95%的用户
内存消耗 :335.9 MB, 在所有 python3 提交中击败了5.88%的用户 

提升还是很明显的！