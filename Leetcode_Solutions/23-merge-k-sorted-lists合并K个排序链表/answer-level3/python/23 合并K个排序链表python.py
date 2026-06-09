### 解题思路
遍历所有链表，将所有节点的值放到一个数组中。
将这个数组排序，然后遍历所有元素得到正确顺序的值。
用遍历得到的值，创建一个新的有序链表。
![image.png](https://pic.leetcode-cn.com/cfaeaeee866ef676358ab9a1a5e94658ef62db0a2aefc54b3ada473478ef59e9-image.png)



### 代码

```python
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def mergeKLists(self, lists):
        """
        :type lists: List[ListNode]
        :rtype: ListNode
        """

        array = []
        l1 = ListNode(0)
        l2 = l1
        for list_node in lists:
            while list_node:
                array.append(list_node.val)
                list_node = list_node.next
            
        array.sort()
        print array

        for i in array:
            l1.next = ListNode(i)
            l1 = l1.next

        return l2.next



```