### 解题思路
此处撰写解题思路

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def mergeTwoLists(self, l1: ListNode, l2: ListNode) -> ListNode:
        head = ListNode(0)
        l3 = head
        while l1 and l2:
            if l1.val <= l2.val:
                l3.next = l1
                l1 = l1.next
            else:
                l3.next = l2
                l2 = l2.next
            l3 = l3.next
        if l1:
            l3.next = l1
        if l2:
            l3.next = l2
        return head.next
```
其实和下面这个没什么太大的区别，只不过有个类ListNode，数据结构里面有讲这个东西，思路都差不多

'''

def mergeTwoLists(l1,l2):
    i,j,l3 = 0,0,[]
    while i<len(l1) and j<len(l2):
        if l1[i] <= l2[j]:
            l3.append(l1[i])
            i += 1
        else:
            l3.append(l2[j])
            j += 1
    if len(l1) == i:
        while j<len(l2):
            l3.append(l2[j])
            j += 1
    else:
        while i<len(l1):
            l3.append(l1[i])
            i += 1
    return l3

if __name__ == '__main__':
    l1 = [1,3,5,7,9]
    l2 = [0,2,4,6,8]
    print(mergeTwoLists(l1,l2))
'''