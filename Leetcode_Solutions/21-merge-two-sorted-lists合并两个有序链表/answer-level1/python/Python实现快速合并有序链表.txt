### 解题思路
1.使用一个新ListNode保存合并后的数据
2. 由于两个链表都有序，可以一次循环两个链表
3. 依次比较两个链表的元素，元素小的添加到新ListNode，然后赋值当前小的元素为当前元素的next再进行比较
4. 如果当前元素已经为None，证明所有元素已经比较完了，如果此时其他链表还有元素存在，可以直接将剩下元素添加ListNode中
5. 这里使用一点trick的方法，应为默认ListNode的对象要有值，而同时要有个新的Listnode对象来添加元素，所以使用一个空字符串值对象，不是None，这样返回结果的时候就是对象的next，因为前面有个空字符串值

时间复杂度O(n+m)
空间复杂度O(1)

### 代码
以下为官方的代码，还是官方提供的代码质量更高，学习了。
```
class Solution(object):
    def mergeTwoLists(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        解题思路：
        1.使用一个新list保存合并后的数据
        2. 由于两个链表都有序，一次循环两个链表，使用两个指针分别指向两个链表表头
        3. 依次比较两个链表的元素，元素小的添加到新list，然后将指针后移，再进行比较
        4. 如果指针已经大于当前list，直接添加另一个list的所有值
        """
        
        l3 = ListNode("")
        ret = l3

        while l1 and l2:            
            if l1.val > l2.val:
                l3.next = l2
                l2 = l2.next
            else:
                l3.next = l1
                l1 = l1.next
            l3 = l3.next
            
        l3.next = l1 if l1 is not None else l2
        return ret.next
    
```



```python
# Definition for singly-linked list.
class ListNode(object):
     def __init__(self, x):
        self.val = x
        self.next = None

class Solution(object):
    def mergeTwoLists(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        解题思路：
        1.使用一个新list保存合并后的数据
        2. 由于两个链表都有序，一次循环两个链表，使用两个指针分别指向两个链表表头
        3. 依次比较两个链表的元素，元素小的添加到新list，然后将指针后移，再进行比较
        4. 如果指针已经大于当前list，直接添加另一个list的所有值
        """
        
        l3 = ListNode("")
        ret = l3

        item = None

        while True:
            if l1 == None:
                self.append(l2, l3)
                break
            
            if l2 == None:
                self.append(l1, l3)
                break
            
            if l1.val > l2.val:
                item = ListNode(l2.val)
                item.val = l2.val
                item.next = None
                l2 = l2.next
            else:
                item = ListNode(l1.val)
                item.val = l1.val
                item.next = None
                l1 = l1.next
            
            l3.next = item
            l3 = l3.next

        return ret.next
    
    def append(self, l1, l3):
        while True:
            if l1 == None:
                break
                
            item = ListNode(l1.val)
            item.val = l1.val
            item.next = None
            l1 = l1.next
            l3.next = item
            l3 = l3.next
```