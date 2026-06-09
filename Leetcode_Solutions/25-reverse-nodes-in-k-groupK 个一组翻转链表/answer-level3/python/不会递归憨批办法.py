### 解题思路
跟24题基本一样
用哈希表辅助记录链表的结构，最后把相邻的连接起来就行了
性能一如既往的低
![image.png](https://pic.leetcode-cn.com/cc348020e1328879e972b12392f8020437e4694fface7111779171e219093ea7-image.png)


### 代码

```python
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def reverseKGroup(self, head, k):
        """
        :type head: ListNode
        :type k: int
        :rtype: ListNode
        """        
        if not head or not head.next:return head
        count={}
        index=0
        while head:
            index += 1
            count[index]=head
            head=head.next
        if k>index: return count[1]
        star=count[k]
        for i in range(1,int(index/k)*k,k):
            for j in range(0,k-1):
                count[i+k-1-j].next=count[i+k-2-j]
            for j in range(0, int(k/2)):
                temp=count[i+j]
                count[i+j]=count[i+k-1-j]
                count[i + k - 1 - j]=temp
        for i in range(k,index,k):
            count[i].next=count[i+1]
        count[index].next=None
        return star

```