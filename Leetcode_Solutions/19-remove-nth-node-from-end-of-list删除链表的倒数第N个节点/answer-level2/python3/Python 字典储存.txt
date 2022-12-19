### 解题思路
比较菜鸡，用的字典来储存每个结点指针
然后再计算出要删除结点的位置
按照情况来进行删除即可

### 代码

```python3
class Solution:
    def removeNthFromEnd(self, head: ListNode, n: int) -> ListNode:
        dist = {}
        temp,i = head,0
        #记录链表
        while temp != None:
            dist[i] = temp
            temp = temp.next
            i += 1
        if i < 2:
            return None
            
        #i为长度,dist[i]为指引
        if i-n+1 < i and i-n-1 >= 0:
            dist[i-n-1].next = dist[i-n+1]
        elif i-n-1 < 0:
            return dist[i-n+1]
        else:
            dist[i-n-1].next = None

        return head

```