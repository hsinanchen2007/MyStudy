**第一种思路：两遍遍历**

最直接的想法是：第一遍取得链表长度，第二遍找到链表中间节点

**第二种思路：随机访问**

利用列表的随机访问特性，第一遍遍历将链表数据存入列表，
直接从列表种取得中间节点，
就能提高时间效率，但是也会带来占用额外的空间

**第三种思路：快慢指针**

使用两个指针，快指针变化速度是慢指针变化速度的两倍，当快指针至链表结尾时，慢指针正好在链表中间。

比较：
时间性能：三种方法在时间消耗上没有太大差别，原因是测试用例链表的最大长度只有100个节点。
空间消耗： 两遍遍历< 快慢指针< 随机访问

下面是三种思路的代码实现，
```
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

#快慢指针
class Solution:
    def middleNode(self, head: ListNode) -> ListNode:
        p = head
        q = head
        while p!= None and p.next != None:
            p = p.next.next
            q = q.next
        return q


#列表随机读取
# class Solution:
#     def middleNode(self, head: ListNode) -> ListNode:
#         p = head
#         array = []
#         while p != None:
#             array.append(p)
#             p = p.next
#         return array[len(array)//2]

# 两遍遍历
# class Solution:
#     def middleNode(self, head: ListNode) -> ListNode:
#         p = head
#         lengt = 0
#         while p != None:
#             lengt += 1
#             p = p.next
#         mid = lengt // 2 + 1
#         p = head
#         for i in range(1, mid):
#             p = p.next
#         return p
```
