### 解题思路
思路比较简单，先遍历两个链表，将所有元素加到一个列表里，然后利用列表的sort方法排好序再遍历列表重建一个链表返回头节点。
注意，这里有个坑，就是输入的两个链表都是空的情况，如果判断列表是空的，就直接返回None即可。

### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def mergeTwoLists(self, l1: ListNode, l2: ListNode) -> ListNode:
        nums = []  # 存放所有元素的列表
        # 将两个链表的所有元素加入到nums中
        for point in (l1, l2):
            while point:
                nums.append(point.val)
                point = point.next
        # 考虑nums为空的情况
        if  not nums:
            return None
        # 将nums顺序排序
        nums.sort()
        # 新建一个ListNode对象，并根据nums初始化它
        p = ListNode(nums.pop(0))  # 指向头部的节点
        temp_p = p
        for num in nums:
            temp_p.next = ListNode(num)
            temp_p = temp_p.next
        return p
        

```