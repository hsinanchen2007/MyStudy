### 解题思路
链表的创建可以由头插或者尾插来解决，比如一个数 123456789,让我们将他写入链表中的形式为:987654321.
1.显然逆序的输出要用到头插法，每一次将新的node 指向原来的head，之后将head指向新的node。时间复杂度为O(n)
2.如果是顺序的输出，我们则要对每个数遍历一遍链表,比如上面的例子，写入链表的形式为:123456789.
我们就要对链表进行尾插法，时间复杂度是O(n^2).
3.需要注意的是可以将输入的123456789 取反，但是取反的时间复杂度是O(n),总体来说方法2最费时。方法1最省时。

### 方法1代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        item1 = l1
        item2 = l2
        s1 = "";s2=""
        while item1 !=None:
            s1 += str(item1.val)
            item1 = item1.next
        while item2 != None:
            s2 += str(item2.val) 
            item2 = item2.next
        s1 = s1[::-1];s2 = s2[::-1]
        out = str(int(s1)+int(s2))
        #head node
        head = None
        # result = ListNode(int(out[0]))
        # item = result
        for i in out:
            val = ListNode(int(i))
            if head == None:
                head = val
            else:
                val.next = head
                head = val
        return val 

```
