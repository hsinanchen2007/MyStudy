解题思路：
1、用cur指针来遍历整个链表，tail为cur的前一个，head为左边排好序的链表，pre为head~tail的指针
2、每次移动cur指针，从head开始对比cur所指向的值，到合适的位置，插入，并更新head，tail

时间复杂度：
1、cur需要遍历n-1个元素
2、pre最坏的情况在第n-1次的插入要遍历n-2次
因此，需要O(n^2)


```
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None
class Solution:
    def insertionSortList(self, head):
        # 边界条件判断
        if not head:
            return None
        tail = head  # 尾指针
        cur = head.next  # cur是用来遍历待插入的元素的指针，从第2个元素开始

        while cur:
            # 判断是否比左边的最后一个数大
            # 若是，则不用变动，修改指针即可
            if cur.val >= tail.val:
                tail = cur  # 修改尾指针
            else:
                # 否则，从头开始比较
                # 如果最小，则插入到头，并修改相应指针
                if cur.val <= head.val:
                    tail.next = cur.next  # 修改尾指针
                    cur.next = head  # 插入
                    head = cur  # 修改头指针
                else:
                    # 否则，用pre指针去查找
                    # 这里的处理是为了方便cur插入，因此pre指向head
                    # 但实际是与pre.next进行比较
                    pre = head  
                    while cur.val > pre.next.val:
                        pre = pre.next
                    # 插入pre的后面
                    tail.next = cur.next  # 修改尾指针
                    # 插入
                	cur.next = pre.next
                    pre.next = cur
            cur = tail.next  # 下一个元素在tail的右边，准备插入
        return head
```