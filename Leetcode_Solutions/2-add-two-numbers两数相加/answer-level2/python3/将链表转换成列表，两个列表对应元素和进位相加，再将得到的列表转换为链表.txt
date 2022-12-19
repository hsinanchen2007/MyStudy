### 解题思路
此处撰写解题思路

### 代码

```python
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

def makenode(lis,nodelis=[]):
        if len(lis):
            nodelis.append(ListNode(lis.pop(0)))
            makenode(lis,nodelis)
        return nodelis
def getnode(listnode,value):
        value.append(listnode.val)
        if listnode.next:
            getnode(listnode.next,value)
        return value #返回一个列表，元素为整数低位到高位的数值
class Solution(object):
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        lis1 = getnode(l1,value=[])
        lis2 = getnode(l2,value=[])
        if len(lis1) > len(lis2):
            lis2 += [0]*(len(lis1) - len(lis2))
        else:
            lis1 += [0]*(len(lis2) - len(lis1))
        lis3 = []
        add = 0
        for temp in zip(lis1,lis2):
            lis3.append(temp[0] + temp[1] + add)
            add = 0
            if lis3[-1] >=10:
                a,b = lis3[-1]%10,lis3[-1]/10
                lis3[-1] = a
                add = b
        if add:
            lis3.append(add)
        nodelis = makenode(lis3,[])
        for i in range(len(nodelis)-1):
            nodelis[i].next = nodelis[i+1]
        return nodelis[0]
```