### 解题思路
0，1，2，个的时候可以直接处理出结果，3个以上的时候分成小规模，不断合并

### 代码

```python3
# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def mergeTwoLists(self, l1,l2):
        if l1 is None:return l2
        if l2 is None:return l1

        if l1.val>l2.val:
            l1,l2=l2,l1
        l1.next=self.mergeTwoLists(l1.next,l2)
        return l1
    def mergeKLists(self, lists: List[ListNode]) -> ListNode:
        if len(lists)==0:
            return ListNode(None)
        if len(lists)==1:
            return lists[0]
        if len(lists)==2:
            return self.mergeTwoLists(lists[0],lists[1])
        else:
            medium=len(lists)//2
            return self.mergeTwoLists(self.mergeKLists(lists[:medium]),self.mergeKLists(lists[medium:]))


```
执行用时 :
136 ms
, 在所有 Python3 提交中击败了
43.47%
的用户
内存消耗 :
23.6 MB
, 在所有 Python3 提交中击败了
5.45%
的用户