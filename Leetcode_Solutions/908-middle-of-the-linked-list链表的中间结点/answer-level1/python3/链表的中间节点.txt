### 解题思路
1.链表不能直接获取中间节点，所以需要新建一个列表result来存储链表各个节点的值，以此可以间接获取整个链表的长度len(result)和中间节点的值result[n//2]；
2.然后要新建一个哨兵节点ans，让节点的next域指向head；
3.初始化指针p用来遍历，初始化一个计数器count，用来计算p走过的长度；
4.然后比较p当前所指的值是否与中间节点的值result[n//2]相等，还需要判断是否走到了一半（因为中间节点的值可能出现重复的情况，提前出现时返回结果就不对了）；
5.若4全满足，则直接将ans.next=p即可得到中间节点后面的序列（此处注意还需要break跳出循环，否则此刻是满足条件的，就会不停地循环下去，从而进入死循环），最后return ans.next即可。

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def middleNode(self, head: ListNode) -> ListNode:
        if head is None and head.next is None:
            return head
        result = []
        ans = ListNode('a')
        ans.next = head
        cur = head
        p = head
        while cur:
            result.append(cur.val)
            cur = cur.next
        n = len(result)
        count = 1
        while p:
            if p.val == result[n//2] and (count == n // 2 or count == (n // 2) + 1):
                ans.next = p
                break
            else:
                p = p.next
                count += 1
        return ans.next

```