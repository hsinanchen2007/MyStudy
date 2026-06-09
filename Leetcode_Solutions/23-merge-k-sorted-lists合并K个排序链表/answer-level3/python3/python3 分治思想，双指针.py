### 解题思路
此处撰写解题思路
![image.png](https://pic.leetcode-cn.com/fde7886fee0623291ea0cabab685e87e6e433957637266ccf67ca0437a071423-image.png)
时间长的，内存消耗高的那个是新建节点的合并方式，时间短的，内存消耗低的是原地修改链表的。
归并排序的分治思想，以及双指针合并两个排序的链表的思路，这里只是多提供了原地修改的和创建新节点的两个方式。
不知道自己的时间复杂度和空间复杂度分析的正确么
### 代码

```python3
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None
# 分治思想，想到之前的2个排序列表的双指针做法，以及归并排序，这里考虑了分治思想来做。
# 在连接的时候不是创建节点来做的。而是修改原链表，所以需要断开连接节点，不知道和直接创建新的节点相比差距大不大
# 时间是 O(nlgk)  n是表示两个排序链表合并的平均时间
# 如果是原地修改链表的话，那么空间复杂度是O(1),否则就是 O(N))  N 是表示所有的节点个数
class Solution:
    def mergeKLists(self, lists: List[ListNode]) -> ListNode:
        
        def helper(lists):
            if len(lists)==1:
                return lists[0]
            mid = len(lists)//2
            a = helper(lists[:mid])
            b = helper(lists[mid:])
            return merge(a,b)

        def merge(a,b):
            head = ListNode(0)
            cur = head
            while a and b:
                if a.val<b.val:
                    cur.next = ListNode(a.val)
                    a = a.next
                    # temp = a.next
                    # cur.next = a
                    # a.next = None
                    # a = temp
                else:
                    cur.next = ListNode(b.val)
                    b = b.next
                    # temp = b.next
                    # cur.next = b
                    # b.next = None
                    # b = temp
                cur = cur.next
            cur.next = a or b
            temp = head.next
            head.next = None
            return temp
        
        return helper(lists) if lists else None

```