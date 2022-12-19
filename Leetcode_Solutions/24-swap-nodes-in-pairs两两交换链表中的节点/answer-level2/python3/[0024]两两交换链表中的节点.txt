## 思路
根据题意，只要将接下来的两个节点交换位置就行了
时间复杂度O(n)
* 首先创建一个头节点（方便插入操作）
* 找到当前节点p
* 找到下一个节点node1和下下一个节点node2（如果找到的node1或者node2为空，就不需要交换了）
* 将node2插入到p跟node1节点之间
* 最后是迭代当前节点2次
## 代码实现
```
class Solution:
    def swapPairs(self, head: ListNode) -> ListNode:
        '''
        对于接下来的两个节点node1,node2，
        将node2插入到node1之前
        '''
        #新建头部节点
        h = ListNode(0)
        h.next = head
        head = h
        p = head
        
        #接下来的两个节点 
        while True:
            node1 = p.next
            if not node1: #到达末端
                break
            node2 = p.next.next
            if not node2: #到达末端 
                break
            #将node2插入到node1之前
            node1.next = node2.next
            node2.next = node1
            p.next = node2
            #迭代两位
            p = p.next.next
        #将头节点移回正确位置
        head = head.next
        return head
```
## 希望指正