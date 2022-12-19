### 解题思路
字典 hash
### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def mergeKLists(self, lists: list) -> ListNode:
        if len(lists)==0:
            return None
        listDict = {}
        for item in lists:
            while item != None:
                subitem = item.val
                item = item.next
                if subitem in listDict:
                    listDict[subitem] += 1
                else:
                    listDict[subitem] = 1
        nodeHead = ListNode(1)
        nodeTemp = nodeHead
        for i in sorted(listDict):
            while listDict[i]>0:
                subNode = ListNode(i)
                nodeTemp.next = subNode
                nodeTemp = nodeTemp.next
                listDict[i] -= 1
        return nodeHead.next
```