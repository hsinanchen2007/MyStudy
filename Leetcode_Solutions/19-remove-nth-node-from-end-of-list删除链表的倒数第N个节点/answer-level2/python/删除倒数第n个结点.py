### 解题思路
此处撰写解题思路
1. 从前到后，每n个点标记一个位置，这个只需要最后两个n的位置就可以找到倒数第n个点
2. 考虑标记每个n段中的首位置或者尾位置：因为被标记的位置不能是被删除的点(不然还得找前面的结点)，所以应该标记尾位置；因为head结点没有前结点，所以加一个dummy结点
3. count的状态有[0,1,...,n]，共n+1个，但是对于后序代码，可见的状态只能有n个，因为状态n(或者状态0)会发生重置，不为外界所见
4. 需要pre1，pre2两个临时变量保存状态
### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def removeNthFromEnd(self, head: ListNode, n: int) -> ListNode:
        dummy = ListNode(0)
        dummy.next = head
        pre1 = dummy
        pre2 = dummy
        cur = head
        count = 0
        while True:
            if cur != None:
                count = count + 1
                if count == n:
                    pre2 = pre1
                    pre1 = cur
                    count = 0
                cur = cur.next
            else:
                break
        
        cur = pre2
        for i in range(0, count):
            cur = cur.next
        cur.next = cur.next.next

        return dummy.next


```