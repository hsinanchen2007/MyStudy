### 解题思路
head、pre、cur分别代表 头结点、当前结点前驱(已排序部分最大值)、当前结点
分三种情况讨论：
    1、cur.val < head.val:
        插入到表头
    2、cur.val > pre.val
        遍历下一个节点
    3、head.val < cur.val < pre.val
        查找插入位置，插入
表头插入过程：
    pre.next = cur.next
    cur.next = head
    head = cur

    

### 代码

```python
# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution(object):
    def insertionSortList(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        if head is None or head.next is None:
            return head

        cur = head.next
        pre = head

        while cur:
            next_node = cur.next    # 保存下一个节点
            # 表头插入
            if cur.val <= head.val:
                pre.next = cur.next
                cur.next = head
                head = cur
                cur = next_node
                continue
            # 当前结点为最大值
            if cur.val >= pre.val:
                pre = pre.next
                cur = next_node
                continue
            # 查找插入位置
            insert_node = head
            while cur.val > insert_node.next.val:
                insert_node = insert_node.next
            # 插入
            pre.next = cur.next
            cur.next = insert_node.next
            insert_node.next = cur
            # 遍历下一个节点
            cur = next_node
       
        return head
            

            













```