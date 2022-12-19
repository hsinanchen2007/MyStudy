### 解题思路
1->2->3->4->5
k=2
以上链表，我先把他根据k值切分成二维数组，[[1,2],[3,4],[5]]
之后将二维数组里个数是k的数组用数组自带的reverse()方法反转，变成[[2,1],[4,3],[5]]
最后将这个二维数组再转回链表2->1->4->3->5

### 代码

```python
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x, node):
#         self.val = x
#         self.next = node

class Solution(object):
    list = []
    def reverseKGroup(self, head, k):
        """
        :type head: ListNode
        :type k: int
        :rtype: ListNode
        """
        self.list = []
        self.getListByNode(head)
        level = int(len(self.list)/k)
        rest = len(self.list)%k
        split_list = []
        for i in range(level):
            split_list.append(self.list[i*k:(i+1)*k])
        for l in split_list:
            l.reverse()
        if rest != 0:
            split_list.append(self.list[len(self.list)-rest:])
        ultimate_list = []
        for i in split_list:
            for j in i:
                ultimate_list.append(j)
        self.modifyValueForNode(head, ultimate_list)
        return head

    def modifyValueForNode(self, head, ultimate_list):
        node = head
        count = 0
        while node:
            if node.next:
                node.val = ultimate_list[count]
                node = node.next
                count  = count + 1
            else:
                node.val = ultimate_list[count]
                count = count + 1
                break
        return head

    def getListByNode(self, head):
        if head != None:
            self.list.append(head.val)
            self.getListByNode(head.next)
        else:
            return
```