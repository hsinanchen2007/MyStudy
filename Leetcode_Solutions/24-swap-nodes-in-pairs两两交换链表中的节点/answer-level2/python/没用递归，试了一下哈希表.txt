### 解题思路
把所有节点地址先放进哈希表
两两转指针，再把表里的位置也改了
两组之间链接指针
最后一位指向None
当然性能不行，特别是对25题那种，我再去康康递归
![image.png](https://pic.leetcode-cn.com/844a27190a3a199d0649d5222d99df1a459fd7f48a380fca83365d89398476c9-image.png)


### 代码

```python
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def swapPairs(self, head):
        if not head or not head.next:return head
        star=head.next
        count={}
        index=0
        while head:
            index += 1
            count[index]=head
            head=head.next
        for i in range(1,index,2):
            count[i+1].next=count[i]
            temp=count[i+1]
            count[i+1]=count[i]
            count[i]=temp
        for i in range(2,index,2):
            count[i].next=count[i+1]
        count[index].next=None
        return star

```