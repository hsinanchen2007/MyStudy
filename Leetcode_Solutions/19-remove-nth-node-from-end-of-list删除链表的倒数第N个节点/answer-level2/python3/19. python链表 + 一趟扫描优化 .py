### 解题思路

#### 首先我们来看没有经过一趟扫描的情况。
这种思路简单。
   首先求出链表的长度，然后匹配到目标节点的前一个节点，最后删除目标节点。
通过两个节点副本作用分别是来计算链表的长度和找到目标节点的前一个节点，对目标节点进行删除

**注：python一切即对象，在算法中定义的两个临时节点指向同一个对象（可以将他们看作对节点的便签），每个节点为一个对象，遍历节点并不会改变对象，只是不断地给对象贴标签。最终的检测时从贴有标签的位置进行遍历，寻找next指向的节点。因此删掉某个节点也就只要修改next指向就行了。**


#### 然后我们来实现一趟扫描实现
   一趟扫描顾名思义就是在一次循环中删除节点。
   这里我们可以拿题目的示例作为例子，链表的长度为5，n为2，此时我们要删除的节点为val=4的节点，所以我们要到目标节点的前一个节点位置，正好这个位置索引就是5-2=3(为了方便计算，添加一个临时节点作为头节点，是的索引往后推移一个单位)。
   因此我们可以设定一个位置计数器i,当i>n时，就可以利用一个节点副本去寻找目标节点的前一个节点位置了，寻找3(5-2)次后，正好结束循环，此时就可以删除节点了。最后返回的应该是头节点的位置。所以我们要在程序的开始，新建两个副本来进行节点的操作。

### 代码

```python

class Solution:
    def removeNthFromEnd(self, head: ListNode, n: int) -> ListNode:
        
        if head.next == None:
            return None
        deep = 0
        head_temp = head
        while head_temp:
            head_temp = head_temp.next
            deep += 1
        aim = deep-n-1
        # aim为目标节点位置的前一个位置，由于从第二个节点开始，所以减去第一个节点
        temp = head
        while aim>0:
            temp = temp.next
            aim -= 1
        # 删除第一个节点
        if aim == -1:
            head = head.next
        else:
            temp.next = temp.next.next
        return head
```

```python
class Solution:
    def removeNthFromEnd(self, head: ListNode, n: int) -> ListNode:
        # 一趟扫描实现
        if head.next == None:
            return None
        new_node = ListNode(-1)
        i = 0
        new_node.next = head
        p = q = new_node
        while p.next:
            p = p.next
            i += 1
            if i > n:
                q = q.next 
        q.next = q.next.next
        return new_node.next
```