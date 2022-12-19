### 解题思路 1.0
*参考信息
作者：tryangel
链接：https://leetcode-cn.com/problems/insertion-sort-list/solution/ccha-ru-pai-xu-xiao-bai-ban-by-tryangel/*

问题：与传统插入排序不同，无法对已排序链表从尾至首遍历进行插入

方法：
1. 为链表增加一个头部，其值为无穷小
2. 对已排序链表部分从首至尾遍历，找到所有小于当前遍历元素的位置，进行链表的尾部插入
3. 将"已排序链表部分"->"待排序链表部分"进行拼接

步骤：
![链表插入排序.jpg](https://pic.leetcode-cn.com/aee669b13146058457c2eda22e8a0a23148f3296012c2b9067e18607418874bb-%E9%93%BE%E8%A1%A8%E6%8F%92%E5%85%A5%E6%8E%92%E5%BA%8F.jpg)


### 执行结果
执行用时：172 ms
内存消耗：16.2 MB
### 代码

```python
# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution(object):
    def insertionSortList(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        fhead = ListNode(float('-Inf') )
        fhead.next = head
        pcur = fhead
        cur = head

        while cur:

            if pcur.val <= cur.val:
                pcur = pcur.next
                cur = pcur.next
                continue
            
            pcur.next = cur.next
            cur.next = None
            
            p = fhead
            while p.next and p.next.val <= cur.val:
                p = p.next

            cur.next = p.next
            p.next = cur
            cur = pcur.next

        return fhead.next
```